//
// Created by fainche on 09.11.18.
//

#include "Serial.hpp"

Serial::Serial(string tytul, unsigned int czasTrwania, string dataProdukcji, string opis, float ocena)
        : Produkcja(std::move(tytul), czasTrwania, std::move(dataProdukcji), std::move(opis)), ocena(ocena) {}

bool Serial::operator<(const Serial &rhs) const {
    return ocena < rhs.ocena;
}

void Serial::flipCzyOgladam() {
    czyOgladam = !czyOgladam;
}

string Serial::print() const {
    char tmp[1000];
    sprintf(tmp, "%s\t%15d\t%10.2f", Produkcja::print().c_str(), czyOgladam, ocena);
    return string(tmp);
}

string Serial::naglowek() const {
    char tmp[1000];
    sprintf(tmp, "%s\t%15s\t%10s\t", Produkcja::naglowek().c_str(), "Czy Ogladam", "Ocena");
    return string(tmp);
}

const string Serial::typ() {
    return "serial";
}

Serial::Serial(vector <string> &atrybuty) : Produkcja(atrybuty) {
    czyOgladam = atrybuty[4] == "1";
    ocena = stof(atrybuty[5]);
}

bool Serial::isCzyOgladam() const {
    return czyOgladam;
}

void Serial::setCzyOgladam(bool czyOgladam) {
    Serial::czyOgladam = czyOgladam;
}

float Serial::getOcena() const {
    return ocena;
}

void Serial::setOcena(float ocena) {
    Serial::ocena = ocena;
}

