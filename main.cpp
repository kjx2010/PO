#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class gry {
	char tytul[10];
	char gatunek[10];
	char rok[10];
public:
	void zapis_gry() {
		cout << "Wprowadz tytul gry ";
		cin >> tytul;
		cout << "Wprowadz gatunek gry ";
		cin >> gatunek;
		cout << "Wprowadz rok premiery gry ";
		cin >> rok;
		cout << endl;
	};
	void odczyt_gry() {
		cout << "Tytul gry: " << tytul << endl;
		cout << "Gatunek gry: " << gatunek << endl;
		cout << "Premiera gry: " << rok << endl;
		cout << endl;
	};
};

class tworca {
	char imie[10];
	char nazwisko[10];
public:
	void zapis_tworcy() {
		cout << "Wprowadz imie tworcy gry ";
		cin >> imie;
		cout << "Wprowadz nazwisko tworcy gry ";
		cin >> nazwisko;
		cout << endl;
	};
	void odczyt_tworcy() {
		cout << "Imie: " << imie << endl;
		cout << "Nazwisko: " << nazwisko << endl;
		cout << endl;
	};
};

void mem_allo(gry **&tab, const int ile);
void mem_allo(tworca ***tab, const int ile);
void baza(gry **&tab, const int ile);
void baza(tworca ***tab, const int ile);
void wyswietlanie(gry **&tab, const int ile);
void wyswietlanie(tworca ***tab, const int ile);
void mem_re(gry **&tab);
void mem_re(tworca ***tab);

void mem_allo(gry **&tab, const int ile) {
	tab = (gry**)malloc(ile * sizeof(struct gry*));
	for (int i = 0; i<ile; i++) {
		tab[i] = (struct gry*)malloc(ile * sizeof(struct gry));
	}
}

void mem_allo(tworca ***tab, const int ile) {
	*tab = (tworca**)malloc(ile * sizeof(struct tworca*));
	for (int i = 0; i<ile; i++) {
		(*tab)[i] = (struct tworca*)malloc(ile * sizeof(struct tworca));
	}
}

void baza(gry **&tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		tab[i]->zapis_gry();
	}
}

void baza(tworca ***tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		(*tab)[i]->zapis_tworcy();
	}
}

void wyswietlanie(gry **&tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		tab[i]->odczyt_gry();
	}
}

void wyswietlanie(tworca ***tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		(*tab)[i]->odczyt_tworcy();
	}
}

void mem_re(gry **&tab) {
	free(*tab);
}

void mem_re(tworca ***tab) {
	free(**tab);
}

void menu(gry **tab_gry, tworca **tab_tworca) {
	int wyb, ile_gier, ile_tworcow;
	do
	{
		cout << "1. Dodaj nowa gre" << endl;
		cout << "2. Dodaj nowego tworce" << endl;
		cout << "3. Wyswietl gry" << endl;
		cout << "4. Wyswietl tworcow" << endl;
		cout << "0. Wyjdz" << endl;
		cin >> wyb;
		switch (wyb)
		{
		case 0:
			mem_re(tab_gry);
			mem_re(&tab_tworca);
			break;
		case 1:
			cout << "Dodaje nowa gre..." << endl;
			cout << "Ile gier wprowadzisz? ";
			cin >> ile_gier;
			cout << endl;
			mem_allo(tab_gry, ile_gier);
			baza(tab_gry, ile_gier);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 2:
			cout << "Dodaje nowego tworce..." << endl;
			cout << "Ile tworcow wprowadzisz? ";
			cin >> ile_tworcow;
			cout << endl;
			mem_allo(&tab_tworca, ile_tworcow);
			baza(&tab_tworca, ile_tworcow);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 3:
			cout << "Wyswietlam..." << endl;
			cout << endl;
			wyswietlanie(tab_gry, ile_gier);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 4:
			cout << "Wyswietlam..." << endl;
			cout << endl;
			wyswietlanie(&tab_tworca, ile_tworcow);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		default:
			cout << "Zly wybor!" << endl;
			break;
		}
	} while (wyb != 0);
}

int main()
{
	gry **tab_gry = NULL;
	tworca **tab_tworca = NULL;
	menu(tab_gry, tab_tworca);
	cin.ignore(1024, '\n');
	cout << "Press enter to continue ...";
	cin.get();
	return 0;
}