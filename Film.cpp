//
// Created by fainche on 09.11.18.
//

#include "Film.hpp"

Film::Film(string tytul, unsigned int czasTrwania, string dataProdukcji, string opis, float ocena)
        : Produkcja(std::move(tytul),
                    czasTrwania,
                    std::move(dataProdukcji),
                    std::move(opis)), ocena(ocena) {}

void Film::flipCzyObejrzany() {
    czyObejrzany = !czyObejrzany;
}

void Film::flipChceObejrzec() {
    chceObejrzec = !chceObejrzec;
}

string Film::print() const {
    char tmp[1000];
    sprintf(tmp, "%s\t%15d\t%15d\t%10.2f", Produkcja::print().c_str(), czyObejrzany, chceObejrzec, ocena);
    return string(tmp);
}

string Film::naglowek() const {
    char tmp[1000];
    sprintf(tmp, "%s\t%15s\t%15s\t%10s", Produkcja::naglowek().c_str(), "Czy Obejrzany", "Chce Obejrzec", "Ocena");
    return string(tmp);
}

bool Film::operator<(const Film &rhs) const {
    return ocena < rhs.ocena;
}

const string Film::typ() {
    return "film";
}

Film::Film(vector <string> &atrybuty) : Produkcja(atrybuty) {
    czyObejrzany = atrybuty[4] == "1";
    chceObejrzec = atrybuty[5] == "1";
    ocena = stof(atrybuty[6]);
}

bool Film::isCzyObejrzany() const {
    return czyObejrzany;
}

void Film::setCzyObejrzany(bool czyObejrzany) {
    Film::czyObejrzany = czyObejrzany;
}

bool Film::isChceObejrzec() const {
    return chceObejrzec;
}

void Film::setChceObejrzec(bool chceObejrzec) {
    Film::chceObejrzec = chceObejrzec;
}

float Film::getOcena() const {
    return ocena;
}

void Film::setOcena(float ocena) {
    Film::ocena = ocena;
}
