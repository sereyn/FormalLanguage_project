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
  return a+NB_ETATS_MAX*b;
}

int NOneToNTwo(int a, int *r){
  r[0] = a%NB_ETATS_MAX;
  r[1] = a/NB_ETATS_MAX;
  return 0;
}

int AFN_construire_produit_intersection(afn a, afn b, afn r){
  for(int i=0; i<NB_ETATS_MAX; i++){
    for(int j=0; j<NB_ETATS_MAX; j++){
      for(int lettre=0; lettre<TAILLE_ALPHABET; lettre++){
        if(ENS_appartient(i, a->trans[j][lettre+'a'])){
          
        }
        if(ENS_appartient(j, a->trans[i][lettre+'a'])){

        }
      }
    }
  }
}