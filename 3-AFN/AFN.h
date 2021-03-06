#ifndef AFN
#define AFN

#define NB_ETATS_MAX 40
#define TAILLE_ALPHABET 2

#include <stdlib.h>
#include <stdio.h>
#include "ensemble.h"

typedef struct afn_t{
  ensemble final;
  ensemble initial;
  ensemble trans[NB_ETATS_MAX][TAILLE_ALPHABET];
} afn_t;

typedef struct afn_t* afn;

afn AFN_initialiser_afn();

int AFN_rendre_final(int e, afn a);

int AFN_rendre_initial(int e, afn a);

int AFN_ajouter_transition(int p, char x, int r, afn a);

int AFN_afficher_afn(afn a);

#endif //AFN