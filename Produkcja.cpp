#include <utility>

#include <utility>

#include <utility>

//
// Created by fainche on 09.11.18.
//

#include "Produkcja.hpp"

Produkcja::Produkcja(string tytul, unsigned int czasTrwania, string dataProdukcji, string opis) : tytul(
        move(tytul)), czasTrwania(czasTrwania), dataProdukcji(move(dataProdukcji)), opis(move(opis)) {}

string Produkcja::print() const {
    char tmp[1000];
    sprintf(tmp, "%20s\t%15d\t%15s\t%15s", tytul.c_str(), czasTrwania, dataProdukcji.c_str(), opis.c_str());
    return string(tmp);
}

string Produkcja::naglowek() const {
    char tmp[1000];
    sprintf(tmp, "%20s\t%15s\t%15s\t%15s", "Tytul", "Czas Trwania", "Data Produkcji", "Opis");
    return string(tmp);
}

Produkcja::Produkcja(vector <string> &atrybuty) {
    tytul = atrybuty[0];
    czasTrwania = static_cast<unsigned int>(stoul(atrybuty[1]));
    dataProdukcji = atrybuty[2];
    opis = atrybuty[3];
}

const string &Produkcja::getTytul() const {
    return tytul;
}

void Produkcja::setTytul(const string &tytul) {
    Produkcja::tytul = tytul;
}

unsigned int Produkcja::getCzasTrwania() const {
    return czasTrwania;
}

void Produkcja::setCzasTrwania(unsigned int czasTrwania) {
    Produkcja::czasTrwania = czasTrwania;
}

const string &Produkcja::getDataProdukcji() const {
    return dataProdukcji;
}

void Produkcja::setDataProdukcji(const string &dataProdukcji) {
    Produkcja::dataProdukcji = dataProdukcji;
}

const string &Produkcja::getOpis() const {
    return opis;
}

void Produkcja::setOpis(const string &opis) {
    Produkcja::opis = opis;
}
