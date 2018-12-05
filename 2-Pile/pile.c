#include "pile.h"

int PILE_initialiser(pile p){
  int i;
  for(i=0; i<TAILLE_MAX; i++){
    p[i] = 0;
  }
  return 0;
}

int PILE_empiler(int elem, pile p){
  if(p[0] == TAILLE_MAX-1){
    printf("TAILLE_MAX dépassée\n");
    return -1;
  }
  p[++p[0]] = elem;
  return 0;
}

int PILE_estvide(pile p){
  return p[0]==0;
}

int PILE_depiler(pile p){
  if(PILE_estvide(p))
    return -1;
  int value = p[p[0]];
  p[p[0]+1] = 0;
  p[0]--;
  return value;
}

int PILE_afficher(pile p){
  int i;
  printf("[");
  for(i=1; i<=p[0]; i++){
    if(i != 1)
      printf(", ");
    printf("%d", p[i]);
  }
  printf("]\n");
}
