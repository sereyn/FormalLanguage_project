#include "ensemble.h"

int main(int argc, char *argv[]){
  ensemble e, d, r;
  printf("Initialisation de e:\n");
  ENS_initialiser(e);
  ENS_afficher(e);

  printf("Remplissage de e:\n");
  ENS_ajouter(5, e);
  ENS_ajouter(12, e);
  ENS_ajouter(55, e);
  ENS_ajouter(14, e);
  ENS_afficher(e);

  printf("Initialisation et remplissage d:\n");
  ENS_initialiser(d);
  ENS_ajouter(3, d);
  ENS_ajouter(5, d);
  ENS_afficher(d);

  printf("Est-ce-que 5 appartient a d ?\n%d\n", ENS_appartient(5, d));
  printf("Est-ce-que 0 appartient a d ?\n%d\n", ENS_appartient(0, d));

  printf("Initialisation de r puis stockage de (e union d) dans r:\n");
  ENS_initialiser(r);
  ENS_union(e, d, r);
  ENS_afficher(r);

  printf("Stockage de (e inter d) dans r:\n");
  ENS_intersection(e, d, r);
  ENS_afficher(r);

  printf("Affectation des valeurs de r dans d:\n");
  ENS_affecter(d, r);
  ENS_afficher(d);
  
  printf("Ajout des valeurs de e dans d:\n");
  ENS_ajouter_les_elements_de(e, d);
  ENS_afficher(d);
  
  return 0;
}