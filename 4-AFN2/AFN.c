#include "AFN.h"

afn AFN_initialiser_afn(){
  int i, j;
  afn n;
  n = (afn)malloc(sizeof(afn_t));
  ENS_initialiser(n->final);
  ENS_initialiser(n->initial);
  for(i=0; i<NB_ETATS_MAX; i++){
    for(j=0; j<TAILLE_ALPHABET; j++)
      ENS_initialiser(n->trans[i][j]);
  }
  return n;
}

int AFN_rendre_final(int e, afn a){
  return ENS_ajouter(e, a->final);
}

int AFN_rendre_initial(int e, afn a){
  return ENS_ajouter(e, a->initial);
}

int AFN_ajouter_transition(int p, char x, int r, afn a){
  return ENS_ajouter(r, a->trans[p][x-'a']);
}

int AFN_afficher_afn(afn a){
  int i, j, y;
  printf("--- Etats initiaux ---\n");
  ENS_afficher(a->initial);
  printf("--- Etats finaux ---\n");
  ENS_afficher(a->final);
  printf("--- Transitions ---\n");
  for(i=0; i<NB_ETATS_MAX; i++){
    for(j=0; j<TAILLE_ALPHABET; j++){
      for(y=0; y<NB_ETATS_MAX; y++){
        if(ENS_appartient(y, a->trans[i][j]))
          printf("%d -> %c -> %d\n", i, j+'a', y);
      }
    }
  }
  return 0;
}

int AFN_analyse_mot_rec(char *mot, int etat, afn a){
  int i, y;
  int found = 0;
  if(mot[0] == '\0'){
    if(ENS_appartient(etat, a->final))
      return 1;
    else
      return 0;
  }
  for(i=0; i<NB_ETATS_MAX; i++){
    if(ENS_appartient(i, a->trans[etat][mot[0]-'a'])){
      found += AFN_analyse_mot_rec(mot+1, i, a);
    }
  }
  return found != 0;
}

int AFN_analyse_mot(char *mot, afn a){
  int i;
  int found = 0;
  for(i=0; i<NB_ETATS_MAX; i++){
    if(ENS_appartient(i, a->initial)){
      found += AFN_analyse_mot_rec(mot, i, a);
    }
  }
  return found != 0;
}

int NTwoToNOne(int a, int b){
  // Bijection de NxN dans N
  return 0.5*(a+b)*(a+b+1)+b;
}

int AFN_construire_produit_intersection(afn a, afn b, afn r){
  AFN_initialiser_afn(r);
  for(int j=0; j<TAILLE_ALPHABET; j++){
    for(int i=0; i<NB_ETATS_MAX; i++){
      for(int y=0; y<NB_ETATS_MAX; y++){
        if(ENS_appartient(y, a->trans[i][j])){
          // on a (i 'j' y) dans (i, x) (j, y)
          for(int k=0; k<NB_ETATS_MAX; k++){
            for(int m=0; m<NB_ETATS_MAX; m++){
              if(ENS_appartient(m, b->trans[k][j])){
                // on a (i, k) (y, m) 
                if(NTwoToNOne(i, k) > NB_ETATS_MAX || NTwoToNOne(y, m) > NB_ETATS_MAX){
                  printf("NB_ETATS_MAX depasse.\n");
                  return -1;
                }
                AFN_ajouter_transition(NTwoToNOne(i, k), j+'a', NTwoToNOne(y, m), r);
                // Faisons les etats initiaux
                if(ENS_appartient(i, a->initial) && ENS_appartient(k, b->initial)){
                  AFN_rendre_initial(NTwoToNOne(i, k), r);
                }
                if(ENS_appartient(y, a->initial) && ENS_appartient(m, b->initial)){
                  AFN_rendre_initial(NTwoToNOne(y, m), r);
                }
                // Faisons les etats finaux
                if(ENS_appartient(i, a->final) && ENS_appartient(k, b->final)){
                  AFN_rendre_final(NTwoToNOne(i, k), r);
                }
                if(ENS_appartient(y, a->final) && ENS_appartient(m, b->final)){
                  AFN_rendre_final(NTwoToNOne(y, m), r);
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
