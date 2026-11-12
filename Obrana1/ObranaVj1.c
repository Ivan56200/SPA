#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Napisati funkciju koja iz stringa izdvaja zadnju riječ u novi string i vraća je.
char* noviString1(char *str) {
	int brojac = 0;
	int pocetak = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && isalpha(str[i + 1])) pocetak = i+1;
	}

	for (int i = pocetak; str[i] != '\0'; i++) {
		if (isalpha(str[i])) brojac++;
	}

	char* novi = malloc((brojac * sizeof(char) + 1));

	int j = 0;
	for (int i = pocetak; str[i] != '\0'; i++) {
		if (isalpha(str[i])) {
			novi[j] = str[i];
			j++;
		}
	}
	novi[j] = '\0';
	return novi;
}


//Napisati funkciju koja iz stringa izdvaja drugu riječ u novi string i vraća je.
char* noviString2(char* str) {
	int brojac = 0;
	int pocetak = 0;

	if (isalpha(str[0])) brojac = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && isalpha(str[i + 1])) brojac++;

		if (brojac == 2) {
			pocetak = i + 1;
			break;
		}
	}

	brojac = 0;
	for (int i = pocetak; str[i] != '\0' && str[i] != ' '; i++) {
		brojac++;
	}

	char* novi = malloc(brojac * sizeof(char) + 1);

	int j = 0;
	for (int i = pocetak; str[i] != '\0' && str[i] != ' '; i++) {
		novi[j] = str[i];
		j++;
	}
	novi[j] = '\0';
	return novi;
}


//Napisati funkciju koja iz stringa izdvaja srednju riječ u novi string i vraća je.
char* noviString3(char* str) {
	int brojac = 0;
	
	if (isalpha(str[0])) brojac = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && isalpha(str[i + 1])) brojac++;
	}
	
	int brRijeci = (brojac + 1) / 2;
	int pocinje; 

	brojac = 0;
	if (isalpha(str[0])) brojac = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && isalpha(str[i + 1])) brojac++;
		if (brojac == brRijeci) { 
			pocinje = i + 1;
			break;
		}
	}

	brojac = 0;
	for (int i = pocinje; str[i] != '\0' && str[i] != ' '; i++) {
		brojac++;
	}

	char* novi = malloc(brojac * sizeof(char) +1 );

	int j = 0;
	for (int i = pocinje; str[i] != '\0' && str[i] != ' '; i++) {
		novi[j] = str[i];
		j++;
	}
	novi[j] = '\0';
	return novi;
}


//Napisati funkciju koja prima string sa dvije riječi i vraća niz od dva nova stringa sa svakom riječi posebno
//NAPISA CHAT RePeTe
char** podijeli(char* str) {
	char** novi = malloc(2 * sizeof(char*));

	int razmak = 0;

	// pronalazak razmaka između dvije riječi
	while (str[razmak] != ' ') {
		razmak++;
	}

	// duljina prve riječi
	int duljina1 = razmak;

	// duljina druge riječi
	int duljina2 = strlen(str) - razmak - 1;

	novi[0] = malloc((duljina1 + 1) * sizeof(char));
	novi[1] = malloc((duljina2 + 1) * sizeof(char));

	// kopiranje prve riječi
	for (int i = 0; i < duljina1; i++) {
		novi[0][i] = str[i];
	}
	novi[0][duljina1] = '\0';

	// kopiranje druge riječi
	for (int i = 0; i < duljina2; i++) {
		novi[1][i] = str[razmak + 1 + i];
	}
	novi[1][duljina2] = '\0';

	return novi;
}


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


int main() {
	char str[] = "Prva druga";
	
	//char* novi = noviString1(str);
	//printf("%s", novi);
	//free(novi);

	//char* novi = noviString2(str);
	//printf("%s", novi);
	//free(novi);

	//char* novi = noviString3(str);
	//printf("%s", novi);
	//free(novi);

	char** novi = podijeli(str);
	printf("%s\n", novi[0]);
	printf("%s\n", novi[1]);

	free(novi[0]);
	free(novi[1]);
	free(novi);



	Tocka niz[] = { { 1.0, 2.0 }, { 2.0, 2.0 }, { 3.0, 2.0 } };
	int duljina = sizeof(niz) / sizeof(niz[0]);

	//Tocka* novi = dodaj(niz, duljina);
	//for (int i = 0; i < duljina + 1; i++) printf("(%.1f, %.1f)\n", novi[i].x, novi[i].y);
	//free(novi);

	return 0;
}
