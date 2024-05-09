#include <iostream>
#include "aes.h"

using namespace std;

int main() {
	// Le texte de 128 bits à déchiffrer
	uint8_t aes[] = {0xF2, 0x59, 0x42, 0x14, 0x10, 0xF5, 0x76, 0x64, 0x79, 0x99, 0xA4, 0x7C, 0x33, 0x8B, 0xED, 0xCC};

	// La clé dont les 24 derniers bits ne sont pas connus
	uint8_t key[] = {0x6D, 0x6F, 0x6E, 0x20, 0x6C, 0x61, 0x63, 0x20, 0x65, 0x73, 0x74, 0x20, 0x61, 0x00, 0x00, 0x00};

	uint8_t result[16];
	uint32_t ks_d[44];

	// Parcours toutes les valeurs possibles pour les 24 bits restants de la clé
	for (int i = 0; i < 0x1000000; ++i) {
		// Modifier les 24 bits restants de la clé afin de tester une combinaison.
		// Le masque est utilisé afin de s'assurer que l'on garde uniquement les
		// bits souhaités
		key[13] = (i >> 16) & 0xFF; // Stockes Les huit bits de poids fort de i
		key[14] = (i >> 8) & 0xFF; // Stockes Les huit bits du milieu fort de i
		key[15] = i & 0xFF; // Stockes Les huit bits de poids faible de i

		// Dérives des sous-clés
		aes128_dks(ks_d, key);

		// Déchiffres avec les sous-clés dérivées
		aes128_decrypt(result, aes, ks_d);

		// Vérifies du texte déchiffré
		if (result[0] == 'j' && result[1] == ' ' && result[2] == 'a' && result[3] == 'i') {
			// Afficher la clé si le texte déchiffré commence par "j ai"
			for (int j = 0; j < 16; ++j) {
				cout << hex << (int)key[j];
			}
			cout << endl;
			break;
		}
	}

	// Affiches le résultat final
	for(int i = 0; i < 16; ++i){
		cout << result[i];
	}

	return 0;
}