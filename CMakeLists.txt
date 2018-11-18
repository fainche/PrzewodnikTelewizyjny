cmake_minimum_required(VERSION 3.12)
project(PrzewodnikTelewizyjny)

set(CMAKE_CXX_STANDARD 17)

add_executable(PrzewodnikTelewizyjny main.cpp Produkcja.cpp Produkcja.hpp Serial.cpp Serial.hpp Film.cpp Film.hpp Stream.cpp Stream.hpp Baza.hpp Menu.cpp Menu.hpp)