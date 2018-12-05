#include "AFN.h"

int main(int argc, char *argv[]){
	afn mon_afn = AFN_initialiser_afn();

	AFN_rendre_final(3, mon_afn);
	AFN_rendre_initial(1, mon_afn);
	AFN_ajouter_transition(1, 'a', 2, mon_afn);
	AFN_ajouter_transition(2, 'a', 1, mon_afn);
	AFN_ajouter_transition(1, 'b', 3, mon_afn);
	AFN_ajouter_transition(3, 'b', 1, mon_afn);

	AFN_afficher_afn(mon_afn);

	printf("\n%d\n", AFN_analyse_mot("aaaabbaabbb", mon_afn));

	int result[2];
	NOneToNTwo(1305, result);

	printf("%d\n", NTwoToNOne(25, 32));
	printf("%d %d\n", result[0], result[1]);

	return 0;
}