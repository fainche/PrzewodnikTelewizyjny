//
// Created by fainche on 09.11.18.
//

#include <climits>
#include "Menu.hpp"


template<typename Typ>
bool Menu::listowanie(Baza<Typ> &baza) {
    if (baza.empty()) {
        cout << "Baza jest pusta." << endl;
        return false;
    }
    cout << "id\t" << baza.begin()->naglowek() << endl;
    int i = 1;
    for (const auto &produkcja:baza) {
        cout << i++ << ".\t" << produkcja.print() << endl;
    }
    cout << endl << endl;
    return true;
}

void Menu::menuGlowne() {
    int a = -1;
    const string tab[]{"1. Serial", "2. Film", "3. Stream", "0. Wyjdz"};
    while (a != WYJDZ) {
        cout << endl << "***PRZEWODNIK TELEWIZYJNY***" << endl << endl;
        a = zapytaj(4, tab);
        switch (a) {
            case MENU_SERIALI:
                menuSeriale();
                break;
            case MENU_FILMY:
                menuFilmy();
                break;
            case MENU_STREAMY:
                menuStreamy();
                break;
        }
    }
}

void Menu::menuSeriale() {
    int a = -1;
    const string tab[]{"1. Wyswietl wszystkie", "2. Sortuj po ocenach", "3. Dodaj serial", "4. Usun serial",
                       "5. Edytuj Serial", "0. Wroc"};
    while (a != WYJDZ) {
        cout << endl << "***SERIALE***" << endl << endl;
        a = zapytaj(6, tab);
        switch (a) {
            case WYSWIETL_WSZYSTKIE:
                listowanie(bazaSeriali);
                break;
            case SORTUJ:
                ranking(bazaSeriali);
                break;
            case DODAJ:
                dodajSerial();
                break;
            case USUN:
                usuwanie(bazaSeriali);
                break;
            case EDYTUJ:
                edytujSerial();
                break;
        }
    }
}

void Menu::menuFilmy() {
    int a = -1;
    const string tab[]{"1. Wyswietl wszystkie", "2. Sortuj po ocenach", "3. Dodaj film", "4. Usun film",
                       "5. Edytuj Film", "0. Wroc"};
    while (a != WYJDZ) {
        cout << endl << "***FILMY***" << endl << endl;
        a = zapytaj(6, tab);
        switch (a) {
            case WYSWIETL_WSZYSTKIE:
                listowanie(bazaFilmow);
                break;
            case SORTUJ:
                ranking(bazaFilmow);
                break;
            case DODAJ:
                dodajFilm();
                break;
            case USUN:
                usuwanie(bazaFilmow);
                break;
            case EDYTUJ:
                edytujFilm();
                break;
        }
    }

}

void Menu::menuStreamy() {
    int a = -1;
    const string tab[]{"1. Wyswietl wszystkie", "2. Wyswietl obserwowane", "3. Dodaj stream", "4. Usun stream",
                       "5. Edytuj Stream", "0. Wroc"};
    while (a != WYJDZ) {
        cout << endl << "***STREAMY***" << endl << endl;
        a = zapytaj(6, tab);
        switch (a) {
            case WYSWIETL_WSZYSTKIE:
                listowanie(bazaStreamow);
                break;
            case WYSWIETL_OBSERWOWANE:
                obserwowaneStreamy();
                break;
            case DODAJ:
                dodajStream();
                break;
            case USUN:
                usuwanie(bazaStreamow);
                break;
            case EDYTUJ:
                edytujStream();
                break;
        }
    }
}

void Menu::dodajSerial() {
    string nazwa;
    float ocena;
    unsigned int czasTrwania;
    string dataProdukcji;
    string opis;
    string sledzenie;
    cout << "Podaj nazwę serialu" << endl;
    getinput(nazwa);
    do {
        cout << "Podaj czas trwania serialu" << endl;
    } while (!getinput(czasTrwania));
    do {
        cout << "Podaj ocenę serialu" << endl;
    } while (!getinput(ocena));
    cout << "Podaj rok w ktorym zostal wyprodukowany serial" << endl;
    getinput(dataProdukcji);
    cout << "Podaj krotki opis serialu" << endl;
    getinput(opis);
    cout << "Czy chcesz sledzic wprowadzony serial? T/N" << endl;
    getinput(sledzenie);
    bazaSeriali += Serial(nazwa, czasTrwania, dataProdukcji, opis, ocena);
    if (*sledzenie.begin() == 'T' || *sledzenie.begin() == 't')
        (bazaSeriali.end() - 1)->flipCzyOgladam();
    bazaSeriali.zapisz();
}

void Menu::dodajFilm() {
    string nazwa;
    float ocena;
    unsigned int czasTrwania;
    string dataProdukcji;
    string opis;
    string obejrzany;
    string chceObejrzec;
    cout << "Podaj nazwę filmu" << endl;
    getinput(nazwa);
    do {
        cout << "Podaj czas trwania filmu" << endl;
    } while (!getinput(czasTrwania));
    do {
        cout << "Podaj ocenę filmu" << endl;
    } while (!getinput(ocena));
    cout << "Podaj rok, w ktorym zostal wyprodukowany serial" << endl;
    getinput(dataProdukcji);
    cout << "Podaj krotki opis filmu" << endl;
    getinput(opis);
    cout << "Czy ogladales juz wprowadzony film? T/N" << endl;
    getinput(obejrzany);
    bazaFilmow += Film(nazwa, czasTrwania, dataProdukcji, opis, 0);
    if (*obejrzany.begin() == 'T' || *obejrzany.begin() == 't')
        (bazaFilmow.end() - 1)->flipCzyObejrzany();
    cout << "Czy chcesz obejrzec wprowadzony film? T/N" << endl;
    getinput(chceObejrzec);
    if (*chceObejrzec.begin() == 'T' || *chceObejrzec.begin() == 't')
        (bazaFilmow.end() - 1)->flipChceObejrzec();
    bazaFilmow.zapisz();
}

void Menu::dodajStream() {
    Stream nowy;
    string nazwa;
    string dataProdukcji;
    string opis;
    string sledzenie;
    unsigned int czasTrwania;
    cout << "Podaj nazwe streamu, ktory chcesz wprowadzic" << endl;
    getinput(nazwa);
    do {
        cout << "Podaj czas trwania streamu" << endl;
    } while (!getinput(czasTrwania));
    cout << "Podaj date streamu" << endl;
    getinput(dataProdukcji);
    cout << "Podaj krotki opis streamu" << endl;
    getinput(opis);
    cout << "Czy chcesz sledzic ten stream? T/N" << endl;
    bazaStreamow += Stream(nazwa, czasTrwania, dataProdukcji, opis);
    getinput(sledzenie);
    if (*sledzenie.begin() == 'T' || *sledzenie.begin() == 't')
        (bazaStreamow.end() - 1)->flipChceObejrzec();
    bazaStreamow.zapisz();
}

unsigned int Menu::zapytaj(int liczbaParametrow, const string *tab) {
    unsigned int a;
    //printf("\033c");
    for (int i = 0; i < liczbaParametrow; ++i) {
        cout << tab[i] << endl;
    }
    cout << ">>> ";
    getinput(a);
    return a;
}

bool Menu::getinput(string &tekst) {
    getline(cin, tekst);
    return true;
}

bool Menu::getinput(float &liczba) {
    string a;
    getinput(a);
    try {
        liczba = stof(a);
    } catch (invalid_argument &e) {
        return false;
    } catch (out_of_range &e) {
        return false;
    }
    return true;
}

bool Menu::getinput(unsigned int &liczba) {
    string a;
    getinput(a);
    unsigned long b;
    try {
        b = stoul(a);
    } catch (invalid_argument &e) {
        return false;
    } catch (out_of_range &e) {
        return false;
    }
    if (b <= UINT_MAX) liczba = static_cast<unsigned int>(b);
    else return false;
    return true;
}

template<typename Typ>
void Menu::ranking(Baza<Typ> baza) {
    sort(baza.begin(), baza.end());
    listowanie(baza);
}

template<typename Typ>
void Menu::usuwanie(Baza<Typ> &baza) {
    if (!listowanie(baza)) return;
    const string tab[]{"Podaj numer linii, ktora chcesz usunac lub wybierz 0 aby przerwac."};
    unsigned int a;
    do {
        a = zapytaj(1, tab);
        if (!a) return;
        if (baza.size() < a) cout << "Podana wartosc jest z poza zakresu" << endl;
    } while (a < 1 || a > baza.size());
    baza -= (a - 1);
    bazaSeriali.zapisz();
    cout << "Usunieto wybrany serial" << endl;
}

void Menu::edytujSerial() {
    const string tab[]{"Podaj numer linii, ktora chcesz edytowac lub wybierz 0 aby przerwac."};
    unsigned int a;
    string ans;
    if (!listowanie(bazaSeriali)) return;
    do {
        a = zapytaj(1, tab);
        if (!a) return;
        if (bazaSeriali.size() < a) cout << "Podana wartosc jest z poza zakresu" << endl;
    } while (a < 1 || a > bazaSeriali.size());
    do {
        printf("1. ""%20s\t%20s\n", "Tytuł", (bazaSeriali[a - 1].getTytul()).c_str());
        printf("2. ""%20s\t%20d\n", "Czas Trwania", bazaSeriali[a - 1].getCzasTrwania());
        printf("3. ""%20s\t%20s\n", "Opis", (bazaSeriali[a - 1].getOpis()).c_str());
        printf("4. ""%20s\t%20d\n", "Czy Ogladam", (bazaSeriali[a - 1].isCzyOgladam()));
        printf("5. ""%20s\t%20.2f\n\n", "Ocena", bazaSeriali[a - 1].getOcena());
        const string zapytanie[]{"Wybierz numer pola, ktore chcesz edytowac."};
        int b = zapytaj(1, zapytanie);
        switch (b) {
            case 1: {
                string tmpString;
                cout << "Wprowadz nowy tytul serialu: ";
                getinput(tmpString);
                bazaSeriali[a - 1].setTytul(tmpString);
                bazaSeriali.zapisz();
                break;

            }
            case 2: {
                unsigned int tmpInt;
                cout << "Wprowadz nowy czas trwania serialu: ";
                getinput(tmpInt);
                bazaSeriali[a - 1].setCzasTrwania(tmpInt);
                bazaSeriali.zapisz();
                break;
            }
            case 3: {
                string tmpString;
                cout << "Wprowadz nowy opis serialu: ";
                getinput(tmpString);
                bazaSeriali[a - 1].setOpis(tmpString);
                bazaSeriali.zapisz();
                break;
            }
            case 4: {
                string tmp;
                cout << "Czy chcesz obserwowac lub przestac obserwowac serial?: T/N";
                getinput(a);
                if (tmp == "T" || tmp == "t") {
                    bazaSeriali[a - 1].flipCzyOgladam();
                }
                bazaSeriali.zapisz();
                break;
            }
            case 5: {
                unsigned int tmpFLoat;
                cout << "Wprowadz nowa ocene serialu: ";
                getinput(tmpFLoat);
                bazaSeriali[a - 1].setOcena(tmpFLoat);
                bazaSeriali.zapisz();
                break;
            }
        }
        cout << "Czy chcesz edytowac jeszcze jakies pole serialu? T/N" << endl;
        getinput(ans);
    } while (ans == "T" || ans == "t");
}

void Menu::edytujFilm() {
    const string tab[]{"Podaj numer linii, ktora chcesz edytowac lub wybierz 0 aby przerwac."};
    unsigned int a;
    string ans;
    if (!listowanie(bazaFilmow)) return;
    do {
        a = zapytaj(1, tab);
        if (!a) return;
        if (bazaFilmow.size() < a) cout << "Podana wartosc jest z poza zakresu" << endl;
    } while (a < 1 || a > bazaFilmow.size());
    do {
        printf("1. ""%20s\t%20s\n", "Tytuł", (bazaFilmow[a - 1].getTytul()).c_str());
        printf("2. ""%20s\t%20d\n", "Czas Trwania", bazaFilmow[a - 1].getCzasTrwania());
        printf("3. ""%20s\t%20s\n", "Data Produkcji", (bazaFilmow[a - 1].getDataProdukcji()).c_str());
        printf("4. ""%20s\t%20s\n", "Opis", (bazaFilmow[a - 1].getOpis()).c_str());
        printf("5. ""%20s\t%20d\n", "Czy Obejrzany", (bazaFilmow[a - 1].isCzyObejrzany()));
        printf("6. ""%20s\t%20d\n", "Chce Obejrzec", (bazaFilmow[a - 1].isChceObejrzec()));
        printf("7. ""%20s\t%20.2f\n\n", "Ocena", bazaFilmow[a - 1].getOcena());
        const string zapytanie[]{"Wybierz numer pola, ktore chcesz edytowac."};
        int b = zapytaj(1, zapytanie);
        switch (b) {
            case 1: {
                string tmpString;
                cout << "Wprowadz nowy tytul filmu: ";
                getinput(tmpString);
                bazaFilmow[a - 1].setTytul(tmpString);
                bazaFilmow.zapisz();
                break;

            }
            case 2: {
                unsigned int tmpInt;
                cout << "Wprowadz nowy czas trwania filmu: ";
                getinput(tmpInt);
                bazaFilmow[a - 1].setCzasTrwania(tmpInt);
                bazaFilmow.zapisz();
                break;
            }
            case 3: {
                string tmpString;
                cout << "Wprowadz nowa date produkcji filmu: ";
                getinput(tmpString);
                bazaFilmow[a - 1].setDataProdukcji(tmpString);
                bazaFilmow.zapisz();
                break;
            }
            case 4: {
                string tmpString;
                cout << "Wprowadz opis filmuu: ";
                getinput(tmpString);
                bazaFilmow[a - 1].setOpis(tmpString);
                bazaFilmow.zapisz();
                break;
            }
            case 5: {
                string tmp;
                cout << "Czy obejrzales juz ten film?: T/N";
                getinput(tmp);
                if (tmp == "T" || tmp == "t") {
                    bazaFilmow[a - 1].flipCzyObejrzany();
                }
                bazaFilmow.zapisz();
                break;
            }
            case 6: {
                string tmp;
                cout << "Czy chcesz obejrzec ten film?: T/N";
                getinput(tmp);
                if (tmp == "T" || tmp == "t") {
                    bazaFilmow[a - 1].flipChceObejrzec();
                }
                bazaFilmow.zapisz();
                break;
            }
            case 7: {
                unsigned int tmpFLoat;
                cout << "Wprowadz nowa ocene serialu: ";
                getinput(tmpFLoat);
                bazaFilmow[a - 1].setOcena(tmpFLoat);
                bazaFilmow.zapisz();
                break;
            }
        }
        cout << "Czy chcesz edytowac jeszcze jakies pole filmu? T/N" << endl;
        getinput(ans);
    } while (ans == "T" || ans == "t");
}

void Menu::edytujStream() {
    const string tab[]{"Podaj numer linii, ktora chcesz edytowac lub wybierz 0 aby przerwac."};
    unsigned int a;
    string ans;
    if (!listowanie(bazaStreamow)) return;
    do {
        a = zapytaj(1, tab);
        if (!a) return;
        if (bazaStreamow.size() < a) cout << "Podana wartosc jest z poza zakresu" << endl;
    } while (a < 1 || a > bazaStreamow.size());
    do {
        printf("1. ""%20s\t%20s\n", "Tytuł", (bazaStreamow[a - 1].getTytul()).c_str());
        printf("2. ""%20s\t%20d\n", "Czas Trwania", bazaStreamow[a - 1].getCzasTrwania());
        printf("3. ""%20s\t%20s\n", "Data Produkcji", (bazaStreamow[a - 1].getDataProdukcji()).c_str());
        printf("4. ""%20s\t%20s\n", "Opis", (bazaStreamow[a - 1].getOpis()).c_str());
        printf("5. ""%20s\t%20d\n", "Chce Obejrzec", (bazaStreamow[a - 1].isChceObejrzec()));
        const string zapytanie[]{"Wybierz numer pola, ktore chcesz edytowac."};
        int b = zapytaj(1, zapytanie);
        switch (b) {
            case 1: {
                string tmpString;
                cout << "Wprowadz nowy tytul streamu: ";
                getinput(tmpString);
                bazaStreamow[a - 1].setTytul(tmpString);
                bazaStreamow.zapisz();
                break;

            }
            case 2: {
                unsigned int tmpInt;
                cout << "Wprowadz nowy czas trwania streamu: ";
                getinput(tmpInt);
                bazaStreamow[a - 1].setCzasTrwania(tmpInt);
                bazaStreamow.zapisz();
                break;
            }
            case 3: {
                string tmpString;
                cout << "Wprowadz nowa date streamu: ";
                getinput(tmpString);
                bazaStreamow[a - 1].setDataProdukcji(tmpString);
                bazaStreamow.zapisz();
                break;
            }
            case 4: {
                string tmpString;
                cout << "Wprowadz opis streamu: ";
                getinput(tmpString);
                bazaStreamow[a - 1].setOpis(tmpString);
                bazaStreamow.zapisz();
                break;
            }
            case 5: {
                string tmp;
                cout << "Czy chcesz zmienic sledzenie tego streamu? T/N";
                getinput(tmp);
                if (tmp == "T" || tmp == "t") {
                    bazaStreamow[a - 1].flipChceObejrzec();
                }
                bazaStreamow.zapisz();
                break;
            }
        }
        cout << "Czy chcesz edytowac jeszcze jakies pole streamu? T/N" << endl;
        getinput(ans);
    } while (ans == "T" || ans == "t");
}

void Menu::obserwowaneStreamy() {
    if (bazaStreamow.empty()) {
        cout << "Baza jest pusta." << endl;
        return;
    }
    cout << bazaStreamow.begin()->naglowek() << endl;
    for (const auto &stream:bazaStreamow) {
        if (stream.isChceObejrzec()) cout << stream.print() << endl;
    }
}
