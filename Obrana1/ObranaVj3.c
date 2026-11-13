#include <stdio.h>
#include <stdlib.h>

//Napisati funkciju koja prima dva niza brojeva, spaja ih u novi niz i vraća ga

int* noviNiz1(int niz1[], int niz2[], int duljina1, int duljina2) {
	int* novi = malloc((duljina1 + duljina2) * sizeof(int));

	for (int i = 0; i < duljina1; i++) {
		novi[i] = niz1[i];
	}

	int j = 0;
	for (int i = duljina1; i < duljina1 + duljina2; i++) {
		novi[i] = niz2[j];
		j++;
	}

	return novi;
}

//Napisati funkciju koja prima niz, u novi niz kopira sve neparne elemente i vraća ga.
int* noviNiz2(int niz[], int duljina, int* n) {
	*n = 0;

	for (int i = 0; i < duljina; i++) {
		if (niz[i] % 2 != 0) (*n)++;
	}

	int* novi = malloc((*n) * sizeof(int));

	int j = 0;
	for (int i = 0; i < duljina; i++) {
		if (niz[i] % 2 != 0) {
			novi[j] = niz[i];
			j++;
		}
	}
	return novi;
}

int main() {
	int niz1[] = { 1, 2, 3, 4 };
	int niz2[] = { 6, 7, 8, 9 };

	int duljina1 = sizeof(niz1) / sizeof(niz1[0]);
	int duljina2 = sizeof(niz2) / sizeof(niz2[0]);

	//int* novi = noviNiz1(niz1, niz2, duljina1, duljina2);
	//for (int i = 0; i < duljina1 + duljina2; i++) printf("%d ", novi[i]);
	//free(novi);

	int duljinaN;
	int* novi = noviNiz2(niz1, duljina1, &duljinaN);
	for (int i = 0; i < duljinaN; i++) printf("%d ", novi[i]);
	free(novi);

	return 0;
}