#include "AFN.h"

int main(int argc, char *argv[]){
	// tests d'analyse
	/*afn mon_afn = AFN_initialiser_afn();

	AFN_rendre_final(3, mon_afn);
	AFN_rendre_initial(1, mon_afn);
	AFN_ajouter_transition(1, 'a', 2, mon_afn);
	AFN_ajouter_transition(2, 'a', 1, mon_afn);
	AFN_ajouter_transition(1, 'b', 3, mon_afn);
	AFN_ajouter_transition(3, 'b', 1, mon_afn);

	AFN_afficher_afn(mon_afn);

	printf("\n%d\n", AFN_analyse_mot("aaaabbaabbb", mon_afn));*/

	afn afnA = AFN_initialiser_afn();
	AFN_rendre_initial(1, afnA);
	AFN_rendre_initial(2, afnA);
	AFN_rendre_final(3, afnA);
	AFN_ajouter_transition(1, 'a', 2, afnA);
	AFN_ajouter_transition(2, 'a', 3, afnA);
	AFN_ajouter_transition(2, 'b', 3, afnA);
	AFN_ajouter_transition(3, 'b', 2, afnA);

	afn afnB = AFN_initialiser_afn();
	AFN_rendre_initial(1, afnB);
	AFN_rendre_final(3, afnB);
	AFN_ajouter_transition(1, 'a', 2, afnB);
	AFN_ajouter_transition(2, 'a', 1, afnB);
	AFN_ajouter_transition(2, 'b', 3, afnB);
	AFN_ajouter_transition(3, 'b', 3, afnB);
	afn afnC = AFN_initialiser_afn();

	AFN_construire_produit_intersection(afnA, afnB, afnC);
	AFN_afficher_afn(afnC);

	return 0;
}