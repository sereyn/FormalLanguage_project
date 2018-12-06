#ifndef AFN
#define AFN

#define NB_ETATS_MAX 80
#define TAILLE_ALPHABET 2

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

int AFN_analyse_mot(char *mot, afn a);

int AFN_construire_produit_intersection(afn a, afn b, afn r);

int AFN_construire_produit_union(afn a, afn b, afn r);

#endif //AFN