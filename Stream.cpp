#include <utility>

#include <utility>

//
// Created by fainche on 09.11.18.
//

#include "Stream.hpp"

Stream::Stream(string tytul, unsigned int czasTrwania, string dataProdukcji, string opis)
        : Produkcja(std::move(tytul), czasTrwania, std::move(dataProdukcji), std::move(opis)) {}

void Stream::flipChceObejrzec() {
    chceObejrzec = !chceObejrzec;
}

string Stream::print() const {
    char tmp[1000];
    sprintf(tmp, "%s\t%15d", Produkcja::print().c_str(), chceObejrzec);
    return string(tmp);
}

string Stream::naglowek() const {
    char tmp[1000];
    sprintf(tmp, "%s\t%15s", Produkcja::naglowek().c_str(), "Chce Obejrzec");
    return string(tmp);
}

const string Stream::typ() {
    return "stream";
}

Stream::Stream(vector <string> &atrybuty) : Produkcja(atrybuty) {
    chceObejrzec = atrybuty[4] == "1";
}

bool Stream::isChceObejrzec() const {
    return chceObejrzec;
}

void Stream::setChceObejrzec(bool chceObejrzec) {
    Stream::chceObejrzec = chceObejrzec;
}
