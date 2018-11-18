//
// Created by fainche on 09.11.18.
//

#ifndef PRZEWODNIKTELEWIZYJNY_STREAM_HPP
#define PRZEWODNIKTELEWIZYJNY_STREAM_HPP

#include "Produkcja.hpp"
#include <vector>

class Stream : public Produkcja {
private:
    bool chceObejrzec = true;
public:
    explicit Stream(vector <string> &);

    Stream(string tytul, unsigned int czasTrwania, string dataProdukcji, string opis);

    Stream() = default;

    void flipChceObejrzec();

    string print() const override;

    string naglowek() const override;

    static const string typ();

    bool isChceObejrzec() const;

    void setChceObejrzec(bool chceObejrzec);
};

#endif //PRZEWODNIKTELEWIZYJNY_STREAM_HPP