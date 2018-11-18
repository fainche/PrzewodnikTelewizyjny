//
// Created by fainche on 09.11.18.
//

#ifndef PRZEWODNIKTELEWIZYJNY_SERIAL_HPP
#define PRZEWODNIKTELEWIZYJNY_SERIAL_HPP


#include "Produkcja.hpp"

class Serial : public Produkcja {
private:
    bool czyOgladam = false;
    float ocena = 0;

public:
    Serial(string tytul, unsigned int czasTrwania, string dataProdukcji, string opis, float ocena);

    Serial() = default;

    Serial(vector <string> &);

    bool operator<(const Serial &rhs) const;

    string print() const override;

    string naglowek() const override;

    void flipCzyOgladam();

    static const string typ();

    bool isCzyOgladam() const;

    void setCzyOgladam(bool czyOgladam);

    float getOcena() const;

    void setOcena(float ocena);
};

#endif //PRZEWODNIKTELEWIZYJNY_SERIAL_HPP
