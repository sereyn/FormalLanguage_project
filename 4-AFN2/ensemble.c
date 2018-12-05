#include "ensemble.h"

int ENS_initialiser(ensemble e){
  int i;
  for(i=0; i<TAILLE_MAX; i++)
    e[i] = 0;
  return 0;
}

int ENS_ajouter(int elem, ensemble e){
  if(TAILLE_MAX < elem+1)
    return -1;
  if(e[elem+1]++)
    e[elem+1]--;
  else
    e[0]++;
  return 0;
}

int ENS_appartient(int elem, ensemble e){
  if(TAILLE_MAX < elem+1)
    return -1;
  return e[elem+1];
}

int ENS_estvide(ensemble e){
  return e[0]==0;
}

int ENS_afficher(ensemble e){
  int i;
  int compteur = 0;
  if(e[0] == 0)
    return printf("vide\n");
  printf("{");
  for(i=1; i<TAILLE_MAX && compteur<e[0]; i++){
    if(e[i]){
      if(compteur)
        printf(", ");
      printf("%d", i-1);
      compteur++;
    }
  }
  printf("}\n");
}

int ENS_retirer_un_element(ensemble e){
  if(ENS_estvide(e))
    return -1;
  int i = 1;
  while(e[i] == 0){
    i++;
  }
  e[i] = 0;
  e[0]--;
  return i-1;
}

int ENS_ajouter_les_elements_de(ensemble s, ensemble d){
  int i;
  int compteur=0;
  for(i=1; i<TAILLE_MAX && compteur<s[0]; i++){
    d[0] += (!d[i]) && (s[i]);
    d[i] = s[i] || d[i];
    compteur += s[i];
  }
  return 0;
}

int ENS_affecter(ensemble s, ensemble d){
  int i;
  int compteur = 0;
  for(i=1; i<TAILLE_MAX && compteur<d[0]; i++){
    s[i] = d[i];
  }
  s[0] = d[0];
}

int ENS_intersection(ensemble a, ensemble b, ensemble r){
  int i;
  int compteur = 0;
  ensemble max_ensemble;
  r[0] = 0;
  if(a[0] > b[0])
    ENS_affecter(max_ensemble, a);
  else
    ENS_affecter(max_ensemble, b);
  for(i=1; i<TAILLE_MAX && compteur<max_ensemble[0]; i++){
    r[i] = a[i] && b[i];
    r[0] += r[i];
    compteur += max_ensemble[i];
  }
}

int ENS_union(ensemble a, ensemble b, ensemble r){
  int i;
  int compteur = 0;
  ensemble max_ensemble;
  r[0] = 0;
  if(a[0] > b[0])
    ENS_affecter(max_ensemble, a);
  else
    ENS_affecter(max_ensemble, b);
  for(i=1; i<TAILLE_MAX && compteur<max_ensemble[0]; i++){
    r[i] = a[i] || b[i];
    r[0] += r[i];
    compteur += max_ensemble[i];
  }
}

int ENS_egal(ensemble a, ensemble b){
  if(a[0] != b[0])
    return 0;
  int i;
  int compteur = 0;
  for(i=1; i<TAILLE_MAX && compteur<a[0]; i++){
    if(a[i] != b[i])
      return 0;
    compteur += a[i];
  }
  return 1;
}