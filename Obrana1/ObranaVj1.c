#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Napisati funkciju koja iz stringa izdvaja zadnju riječ u novi string i vraća je.
char* noviString1(char* str) {
	int brojac = 0;
	int pocetak = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && isalpha(str[i + 1])) pocetak = i + 1;
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

	char* novi = malloc(brojac * sizeof(char) + 1);

	int j = 0;
	for (int i = pocinje; str[i] != '\0' && str[i] != ' '; i++) {
		novi[j] = str[i];
		j++;
	}
	novi[j] = '\0';
	return novi;
}


//Napisati funkciju koja iz stringa izdvaja sve osim sredjne riječ u novi string i vraća je.
char* noviString4(char* str) {
	int pocetak = 0;
	int brRijeci = 0;
	int duljinaCijelog = 0;

	//broji sve rijeci
	if (isalpha(str[0])) brRijeci = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && isalpha(str[i + 1])) brRijeci++;
		duljinaCijelog++;
	}

	int srednja = (brRijeci + 1) / 2;
	brRijeci = 0;

	//trazi gdje pocinje sredanj
	if (isalpha(str[0])) brRijeci = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && isalpha(str[i + 1]))brRijeci++;
		if (brRijeci == srednja) {
			pocetak = i + 1;
			break;
		}
	}

	//koliko je duga srrednja
	int duljinaRijec = 0;
	for (int i = pocetak; str[i] != '\0' && str[i] != ' '; i++) {
		duljinaRijec++;
	}

	char* novi = malloc((duljinaCijelog - duljinaRijec) * sizeof(char) + 1);
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (i >= pocetak && i <= pocetak + duljinaRijec) continue;
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



int main() {
	char str[] = "Prva druga trecva cetvrta";

	//char* novi = noviString1(str);
	//printf("%s", novi);
	//free(novi);

	//char* novi = noviString2(str);
	//printf("%s", novi);
	//free(novi);

	//char* novi = noviString3(str);
	//printf("%s", novi);
	//free(novi);

	char* novi = noviString4(str);
	printf("%s", novi);
	free(novi);



	/*char** novi = podijeli(str);
	printf("%s\n", novi[0]);
	printf("%s\n", novi[1]);

	free(novi[0]);
	free(novi[1]);
	free(novi);*/

	return 0;
}