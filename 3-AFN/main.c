#include "AFN.h"

int main(int argc, char *argv[]){
  afn mon_afn = AFN_initialiser_afn(mon_afn);

  AFN_rendre_initial(1, mon_afn);
  AFN_rendre_final(3, mon_afn);

  AFN_ajouter_transition(1, 'a', 2, mon_afn);
  AFN_ajouter_transition(2, 'b', 2, mon_afn);
  AFN_ajouter_transition(2, 'b', 3, mon_afn);

  AFN_afficher_afn(mon_afn);
  return 0;
}