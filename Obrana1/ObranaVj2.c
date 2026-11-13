#include <stdio.h>
#include <stdlib.h>

//vraca novi niz struktura gdje ce na kraju se dodati nova struktura sa (0, 0)
typedef struct {
	float x, y;
} Tocka;

Tocka* dodaj(Tocka* niz, int n) {
	Tocka* novi = malloc(sizeof(Tocka) * (n + 1));
	int i;
	for (i = 0; i < n; i++) {
		novi[i].x = niz[i].x;
		novi[i].y = niz[i].y;
	}

	novi[i].x = 0;
	novi[i].y = 0;
	return novi;
}


//Izbrisi  srednji clan
Tocka* izbrisi(Tocka* t, int n, int* vel) {
	int nova = n - 1;
	*vel = nova;

	Tocka* novi = malloc(nova * sizeof(Tocka));
	int k = 0;

	for (int i = 0; i < n; i++) {
		if (i == n / 2)	continue;
		novi[k].x = t[i].x;
		novi[k].y = t[i].y;
		k++;
	}

	return novi;
}


int main() {
	Tocka niz[] = { { 1.0, 2.0 }, { 2.0, 2.0 }, { 3.0, 2.0 }, { 3.0, 2.0 }, { 1.0, 2.0 } };
	int duljina = sizeof(niz) / sizeof(niz[0]);

	Tocka* novi = dodaj(niz, duljina);
	for (int i = 0; i < duljina + 1; i++) printf("(%.1f, %.1f)\n", novi[i].x, novi[i].y);
	free(novi);

	//int duljinaN;
	//Tocka* novi = izbrisi(niz, duljina, &duljinaN);
	//for (int i = 0; i < duljinaN;i++) printf("(%.1f, %.1f)\n", novi[i].x, novi[i].y);
	//free(novi);

	return 0;
}