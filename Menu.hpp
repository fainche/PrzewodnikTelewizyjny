//
// Created by fainche on 09.11.18.
//

#ifndef PRZEWODNIKTELEWIZYJNY_MENU_HPP
#define PRZEWODNIKTELEWIZYJNY_MENU_HPP


#define WYJDZ 0
#define MENU_SERIALI 1
#define MENU_FILMY 2
#define MENU_STREAMY 3
#define WYSWIETL_WSZYSTKIE 1
#define SORTUJ 2
#define DODAJ 3
#define USUN 4
#define EDYTUJ 5
#define WYSWIETL_OBSERWOWANE 2

#include <iostream>
#include "Serial.hpp"
#include "Baza.hpp"
#include "Film.hpp"
#include "Stream.hpp"

class Menu {
public:
    Baza<Serial> bazaSeriali;
    Baza<Film> bazaFilmow;
    Baza<Stream> bazaStreamow;

    void menuGlowne();

    void menuSeriale();

    void menuFilmy();

    void menuStreamy();

    bool getinput(unsigned int &);

    bool getinput(float &);

    bool getinput(string &);

    template<typename Typ>
    bool listowanie(Baza<Typ> &);

    template<typename Typ>
    void ranking(Baza<Typ>);

    void dodajSerial();

    void dodajFilm();

    void dodajStream();

    unsigned int zapytaj(int, const string *);

    template<typename Typ>
    void usuwanie(Baza<Typ> &);

    void edytujSerial();

    void edytujFilm();

    void edytujStream();

    void obserwowaneStreamy();

};


#endif //PRZEWODNIKTELEWIZYJNY_MENU_HPP
