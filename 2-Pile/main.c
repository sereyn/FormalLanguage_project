#include "pile.h"

int main(int argc, char *argv[]){
  pile p;
  PILE_initialiser(p);
  PILE_afficher(p);

  PILE_empiler(5, p);
  PILE_empiler(10, p);
  PILE_afficher(p);

  PILE_depiler(p);
  PILE_afficher(p);

  PILE_depiler(p);
  PILE_depiler(p);
  PILE_depiler(p);

  return 0;
}