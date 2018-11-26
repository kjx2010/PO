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

void mem_allo(gry *&tab, const int ile);
void mem_allo(tworca ***tab, const int ile);
void baza(gry *&tab, const int ile, const int ile2, const int index);
void baza(tworca **&tab, const int ile, const int ile2, const int index);
void edycja(gry *&tab, const int ile, const int ile2);
void edycja(tworca **&tab, const int ile, const int ile2);
void usuwanie(gry *&tab, const int ile, int ile2);
void usuwanie(tworca **&tab, const int ile, int ile2);
void wyswietlanie(gry *&tab, const int ile);
void wyswietlanie(tworca **&tab, const int ile);
void mem_re(gry *&tab);
void mem_re(tworca **&tab, const int ile);

//dla gier
void mem_allo(gry *&tab, const int ile) {
	//tab = (gry*)malloc(ile * sizeof(struct gry));	
	tab = new struct gry[ile];
}

//dla tw�rc�w
void mem_allo(tworca ***tab, const int ile) {
	*tab = (tworca**)malloc(ile * sizeof(struct tworca*));
	for (int i = 0; i<ile; i++) {
		//(*tab)[i] = (struct tworca*)malloc(ile * sizeof(struct tworca));
		(*tab)[i] = new struct tworca[ile];
	}
}

//dla gier
void baza(gry *&tab, const int ile, const int ile2, const int index) {
	gry *tab_gry_temp = NULL;
	if (tab != NULL) {
		mem_allo(tab_gry_temp, (ile2-ile));
		for (int i = 0; i < (ile2 - ile); i++) {
			tab_gry_temp[i] = tab[i];
		}
		mem_re(tab);
	}

	mem_allo(tab, ile2);
	tab[index].zapis_gry();

	if (tab != NULL) {
		for (int i = 0; i < index; i++) {
			tab[i] = tab_gry_temp[i];
		}
		
		for (int i = index+1; i < ile2; i++) {
			tab[i] = tab_gry_temp[i-1];
		}
		mem_re(tab_gry_temp);
	}
}

void edycja(gry *&tab, const int ile, const int ile2) {
	if (tab != NULL) {
		if (ile >= ile2 || ile < 0) {
			cout << "Nie ma elementu o takim indeksie" << endl;
		}
		else {
			gry *tab_gry_temp = NULL;
			mem_allo(tab_gry_temp, ile2);
			for (int i = 0; i < ile2; i++) {
				tab_gry_temp[i] = tab[i];
			}
			mem_re(tab);
			mem_allo(tab, ile2);

			for (int i = 0; i < ile; i++) {
					tab[i] = tab_gry_temp[i];
			}
			tab[ile].zapis_gry();
			for (int i = ile+1; i < ile2; i++) {
				tab[i] = tab_gry_temp[i];
			}
			mem_re(tab_gry_temp);
		}
	}
	else {
		cout << "Tablica nie istnieje" << endl;
	}
}

void usuwanie(gry *&tab, const int ile, int ile2) {
	if (tab != NULL) {
		if (ile >= ile2 || ile < 0) {
			cout << "Nie ma elementu o takim indeksie" << endl;
		}
		else {
			gry *tab_gry_temp = NULL;
			mem_allo(tab_gry_temp, ile2);
			for (int i = 0; i < ile2; i++) {
				tab_gry_temp[i] = tab[i];
			}
			mem_re(tab);
			mem_allo(tab, (ile2-1));

			for (int i = 0; i < ile; i++) {
					tab[i] = tab_gry_temp[i];
			}
			for (int i = ile+1; i < ile2; i++) {
				tab[i-1] = tab_gry_temp[i-1];
			}
			mem_re(tab_gry_temp);
		}
	}
	else {
		cout << "Tablica nie istnieje" << endl;
	}
}

//dla tw�rc�w
void baza(tworca **&tab, const int ile, const int ile2, const int index) {
	tworca **tab_tworca_temp = NULL;
	if (tab != NULL) {
		mem_allo(&tab_tworca_temp, (ile2 - ile));
		for (int i = 0; i < (ile2 - ile); i++)
		{
			tab_tworca_temp[i] = tab[i];
		}
		mem_re(tab, ile);
	}

	mem_allo(&tab, ile2);
	tab[index]->zapis_tworcy();

	if (tab_tworca_temp != NULL) {
			for (int i = 0; i < index; i++) {
					tab[i] = tab_tworca_temp[i];
			}

			for (int i = index+1; i < ile2; i++) {
				tab[i] = tab_tworca_temp[i-1];
			}
		mem_re(tab_tworca_temp, ile);
	}
}

void edycja(tworca **&tab, const int ile, const int ile2) {
	if (tab != NULL) {
		if (ile >= ile2 || ile < 0) {
			cout << "Nie ma elementu o takim indeksie" << endl;
		}
		else {
			tworca **tab_tworca_temp = NULL;
			mem_allo(&tab_tworca_temp, ile2);
			for (int i = 0; i < ile2; i++) {
				tab_tworca_temp[i] = tab[i];
			}
			mem_re(tab, ile);
			mem_allo(&tab, ile2);

			for (int i = 0; i < ile; i++) {
					tab[i] = tab_tworca_temp[i];
			}
			tab[ile]->zapis_tworcy();
			for (int i = ile+1; i < ile2; i++) {
				tab[i] = tab_tworca_temp[i];
			}
			mem_re(tab_tworca_temp, ile);
		}
	}
	else {
		cout << "Tablica nie istnieje" << endl;
	}
}

void usuwanie(tworca **&tab, const int ile, const int ile2) {
	if (tab != NULL) {
		if (ile >= ile2 || ile < 0) {
			cout << "Nie ma elementu o takim indeksie" << endl;
		}
		else {
			tworca **tab_tworca_temp = NULL;
			mem_allo(&tab_tworca_temp, ile2);
			for (int i = 0; i < ile2; i++) {
				tab_tworca_temp[i] = tab[i];
			}
			mem_re(tab, ile);
			mem_allo(&tab, ile2);

			for (int i = 0; i < ile; i++) {
					tab[i] = tab_tworca_temp[i];
			}
			for (int i = ile+1; i < ile2; i++) {
				tab[i-1] = tab_tworca_temp[i-1];
			}
			mem_re(tab_tworca_temp, ile);
		}
	}
	else {
		cout << "Tablica nie istnieje" << endl;
	}
}

//dla gier
void wyswietlanie(gry *&tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		tab[i].odczyt_gry();
	}
}

//dla tw�rc�w
void wyswietlanie(tworca **&tab, const int ile) {
	for (int i = 0; i<ile; i++) {
		tab[i]->odczyt_tworcy();
	}
}

void mem_re(gry *&tab) {
	//free(tab);
	delete[] tab;
}

void mem_re(tworca **&tab, const int ile) {
	//free(tab);
	delete[] tab;
}

void menu(gry *tab_gry, tworca **tab_tworca) {
	int wyb, ile_gier = 0, ile_tworcow = 0, ile_gier_all = 0, ile_tworcow_all = 0, index = 0;
	do
	{
		cout << "1. Dodaj nowa gre" << endl;
		cout << "2. Dodaj nowego tworce" << endl;
		cout << "3. Wyswietl gry" << endl;
		cout << "4. Wyswietl tworcow" << endl;
		cout << "5. Edytuj gre" << endl;
		cout << "6. Edytuj tworce" << endl;
		cout << "7. Usuwan gre" << endl;
		cout << "8. Usuwan tworce" << endl;
		cout << "0. Wyjdz" << endl;
		cin >> wyb;
		switch (wyb)
		{
		case 0:
			if (tab_gry != NULL) {
				mem_re(tab_gry);
			}
			if (tab_tworca != NULL) {
				mem_re(tab_tworca, ile_tworcow_all);
			}
			break;
		case 1:
			cout << "Dodaje nowa gre..." << endl;
			// cout << "Ile gier wprowadzisz? ";
			// cin >> ile_gier;
			cout << "Podaj index? ";
			cin >> index;
			cout << endl;
			ile_gier_all += 1;
			baza(tab_gry, ile_gier, ile_gier_all, index);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 2:
			cout << "Dodaje nowego tworce..." << endl;
			// cout << "Ile tworcow wprowadzisz? ";
			// cin >> ile_tworcow;
			cout << "Podaj index? ";
			cin >> index;
			cout << endl;
			ile_tworcow_all += 1;
			baza(tab_tworca, ile_tworcow, ile_tworcow_all, index);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 3:
			cout << "Wyswietlam..." << endl;
			cout << endl;
			wyswietlanie(tab_gry, ile_gier_all);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 4:
			cout << "Wyswietlam..." << endl;
			cout << endl;
			wyswietlanie(tab_tworca, ile_tworcow_all);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 5:
			cout << "Edytuje..." << endl; 
			cout << "Podaj index? ";
			cin >> index;
			cout << endl;
			edycja(tab_gry, index, ile_gier_all);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 6:
			cout << "Edytuje..." << endl;
			cout << "Podaj index? ";
			cin >> index;
			cout << endl;
			edycja(tab_tworca, index, ile_tworcow_all);
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 7:
			cout << "Usuwanie..." << endl;
			cout << "Podaj index? ";
			cin >> index;
			cout << endl;
			usuwanie(tab_gry, index, ile_gier_all);
			if(tab_gry != NULL && index <= ile_gier_all){ ile_gier_all -= 1;}
			cin.ignore(1024, '\n');
			cout << "Press enter to continue ...";
			cin.get();
			system("clear");
			break;
		case 8:
			cout << "Usuwanie..." << endl;
			cout << "Podaj index? ";
			cin >> index;
			cout << endl;
			usuwanie(tab_tworca, index, ile_tworcow_all);
			if(tab_tworca != NULL && index <= ile_tworcow_all){ ile_tworcow_all -= 1;}
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
	gry *tab_gry = NULL;
	tworca **tab_tworca = NULL;
	menu(tab_gry, tab_tworca);
	cin.ignore(1024, '\n');
	cout << "Press enter to continue ...";
	cin.get();
	system("clear");
	return 0;
}