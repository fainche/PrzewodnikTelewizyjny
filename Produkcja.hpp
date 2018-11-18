//
// Created by fainche on 09.11.18.
//

#ifndef PRZEWODNIKTELEWIZYJNY_PRODUKCJA_HPP
#define PRZEWODNIKTELEWIZYJNY_PRODUKCJA_HPP

#define ROK_ROZMIAR 4

#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Produkcja {
protected:
    string tytul;
    unsigned int czasTrwania{}; //[min]
    string dataProdukcji;
    string opis;

    virtual string print() const;

    virtual string naglowek() const;

public:
    Produkcja(vector <string> &);

    Produkcja() = default;

    Produkcja(string tytul, unsigned int czasTrwania, string dataProdukcji, string opis);

    const string &getTytul() const;

    void setTytul(const string &tytul);

    unsigned int getCzasTrwania() const;

    void setCzasTrwania(unsigned int czasTrwania);

    const string &getDataProdukcji() const;

    void setDataProdukcji(const string &dataProdukcji);

    const string &getOpis() const;

    void setOpis(const string &opis);
};

#endif //PRZEWODNIKTELEWIZYJNY_PRODUKCJA_HPP
