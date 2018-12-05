#ifndef PILE
#define PILE

#define TAILLE_MAX 100

#include <stdio.h>

typedef int pile[TAILLE_MAX];

int PILE_initialiser(pile p);

int PILE_empiler(int elem, pile p);

int PILE_estvide(pile p);

int PILE_depiler(pile p);

int PILE_afficher(pile p);

#endif //PILE