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
