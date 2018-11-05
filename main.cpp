#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct gry {
	char tytul[10];
	char gatunek[10];
	char rok[10];
};

void mem_allo(gry **tab, const int ile);
void mem_allo(gry ***tab, const int ile);
void baza(gry **tab, const int ile);
void baza(gry ***tab, const int ile);
void wyswietlanie(gry **tab, const int ile);
void wyswietlanie(gry ***tab, const int ile);
void mem_re(gry **tab);
void mem_re(gry ***tab);

void mem_allo(gry **tab, const int ile) {
	*tab = (gry*)malloc(ile * sizeof(struct gry));
	for (int i = 0; i<ile; i++) {
		tab[i] = (struct gry*)malloc(ile * sizeof(struct gry));
	}
}

void mem_allo(gry ***tab, const int ile) {
	*tab = (gry**)malloc(ile * sizeof(struct gry*));
	for (int i = 0; i<ile; i++) {
		(*tab)[i] = (struct gry*)malloc(ile * sizeof(struct gry));
	}
}

void baza(gry **tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		cout << "Wprowadz tytul gry ";
		cin >> tab[i]->tytul;
		cout << "Wprowadz gatunek gry ";
		cin >> tab[i]->gatunek;
		cout << "Wprowadz rok premiery gry ";
		cin >> tab[i]->rok;
		cout << endl;
	}
}

void baza(gry ***tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		cout << "Wprowadz tytul gry ";
		cin >> (*tab)[i]->tytul;
		cout << "Wprowadz gatunek gry ";
		cin >> (*tab)[i]->gatunek;
		cout << "Wprowadz rok premiery gry ";
		cin >> (*tab)[i]->rok;
		cout << endl;
	}
}

void wyswietlanie(gry **tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		cout << "Tytul gry: " << tab[i]->tytul << endl;
		cout << "Gatunek gry: " << tab[i]->gatunek << endl;
		cout << "Premiera gry: " << tab[i]->rok << endl;
		cout << endl;
	}
}

void wyswietlanie(gry ***tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		cout << "Tytul gry: " << (*tab)[i]->tytul << endl;
		cout << "Gatunek gry: " << (*tab)[i]->gatunek << endl;
		cout << "Premiera gry: " << (*tab)[i]->rok << endl;
		cout << endl;
	}
}

void mem_re(gry **tab) {
	free(*tab);
}

void mem_re(gry ***tab) {
	free(**tab);
}

int main()
{
	gry *tab = NULL;
	gry **tab2 = NULL;
	int ile;
	cout << "Ile gier wprowadzisz? ";
	cin >> ile;
	mem_allo(&tab, ile);
	baza(&tab, ile);
	wyswietlanie(&tab, ile);
	mem_re(&tab);
	mem_allo(&tab2, ile);
	baza(&tab2, ile);
	wyswietlanie(&tab2, ile);
	mem_re(&tab2);
	cin.ignore(1024, '\n');
	cout << "Press enter to continue ...";
	cin.get();
	return 0;
}