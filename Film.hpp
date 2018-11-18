//
// Created by fainche on 09.11.18.
//

#ifndef PRZEWODNIKTELEWIZYJNY_FILM_HPP
#define PRZEWODNIKTELEWIZYJNY_FILM_HPP

#include "Produkcja.hpp"

class Film : public Produkcja {
private:
    bool czyObejrzany = false;
    bool chceObejrzec = false;
    float ocena = 0;
public:
    Film(string tytul, unsigned int czasTrwania, string dataProdukcji, string opis, float ocena);

    Film() = default;

    Film(vector <string> &);

    void flipCzyObejrzany();

    void flipChceObejrzec();

    string print() const override;

    string naglowek() const override;

    bool operator<(const Film &rhs) const;

    static const string typ();

    bool isCzyObejrzany() const;

    void setCzyObejrzany(bool czyObejrzany);

    bool isChceObejrzec() const;

    void setChceObejrzec(bool chceObejrzec);

    float getOcena() const;

    void setOcena(float ocena);
};

#endif //PRZEWODNIKTELEWIZYJNY_FILM_HPP