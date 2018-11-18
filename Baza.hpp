//
// Created by fainche on 09.11.18.
//

#ifndef PRZEWODNIKTELEWIZYJNY_BAZA_HPP
#define PRZEWODNIKTELEWIZYJNY_BAZA_HPP

#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

template<typename Typ>
class Baza : public vector<Typ> {
public:
    Baza();

    void zapisz();

    Baza<Typ> &operator+=(Typ);

    Baza<Typ> &operator-=(Typ &);

    Baza<Typ> &operator-=(int);
};

template<typename Typ>
Baza<Typ> &Baza<Typ>::operator+=(Typ nowy) {
    this->push_back(nowy);
    return *this;
}

template<typename Typ>
Baza<Typ> &Baza<Typ>::operator-=(Typ &stary) {
    auto it = find(this->begin(), this->end(), stary);
    if (it == this->end()) throw string("Podany element nie zostal znaleziony w bazie");
    erase(it);
    return *this;
}

template<typename Typ>
Baza<Typ>::Baza() {
    ifstream plik("baza" + Typ::typ());
    if (plik.good()) {
        string linia;
        vector <string> slowa;
        string slowo;
        while (getline(plik, linia) && !linia.empty()) {
            slowa.clear();
            for (const auto &znak:linia) {
                if (znak == '\t') {
                    slowa.push_back(slowo);
                    slowo.clear();
                } else slowo += znak;
            }
            slowa.push_back(slowo);
            (*this) += Typ(slowa);
            linia.clear();
        }
    } else cout << "Nie udalo sie otworzyc pliku baza" + Typ::typ() << endl;
    plik.close();
}

template<typename Typ>
void Baza<Typ>::zapisz() {
    Typ::typ();
    ofstream plik("baza" + Typ::typ());
    for (const auto &produkcja: *this) {
        plik << produkcja.print() << endl;
    }
    plik.close();
}

template<typename Typ>
Baza<Typ> &Baza<Typ>::operator-=(int i) {
    this->erase(this->begin() + i);
    return *this;
}

#endif //PRZEWODNIKTELEWIZYJNY_BAZA_HPP
