#ifndef ENSEMBLE
#define ENSEMBLE

#define TAILLE_MAX 100

#include <stdio.h>

typedef int ensemble[TAILLE_MAX];

int ENS_initialiser(ensemble e);

int ENS_ajouter(int elem, ensemble e);

int ENS_appartient(int elem, ensemble e);

int ENS_estvide(ensemble e);

int ENS_afficher(ensemble e);

int ENS_retirer_un_element(ensemble e);

//Ajoute les elements de s à d
int ENS_ajouter_les_elements_de(ensemble s, ensemble d);

//Affecte d à s
int ENS_affecter(ensemble s, ensemble d);

//Stocke l'intersection de a et b dans r
int ENS_intersection(ensemble a, ensemble b, ensemble r);

//Stocke l'union de a et b dans r
int ENS_union(ensemble a, ensemble b, ensemble r);

int ENS_egal(ensemble a, ensemble b);

#endif //ENSEMBLE