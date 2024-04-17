#ifndef PARKING_PARKINGPLACE_H
#define PARKING_PARKINGPLACE_H

/// Klasa Field - pojedyncze pole na mapie
struct Field{

    /// Sprawdza czy pole jest parkingiem

    bool isParking;

    /// Sprawdza czy pole jest zajęte
    bool isTaken;

    /// Sprawdza jaki pojazd jest na danym polu
    char what_vehicle;

};
/// Klasa zawierająca plasznę i odpowiadająca za wszystkie czynności jakie się na niej wykonują
/// \param [int]width - szerokość planszy
/// \param [int]height - wyskość planszy
class Parking_Place{

    int width;
    int height;

    /// Tablica 100x100 z pojedyńczych pól
    Field Board[100][100];

public:
    ///
    /// \param width szerokość planszy
    /// \param height  wysokość planszy
    //konstruktor
    Parking_Place(int width, int height);


    /// \bierf Fuknkcja umożliwijąca zwracanie szerokości planszy, aby inne funkcje mogły wiedzieć jaka jest szerokość
    /// \return width - szerokość
    int getBoardWidth();

    /// \bierf Fuknkcja umożliwijąca zwracanie wysokości planszy, aby inne funkcje mogły wiedzieć jaka jest wysokość
    /// \return height - wykość
    int getBoardHeight();

    /// \bierf Funkcja zliczająca wolne miejsca na parkingu
    /// \return Sum - suma wszystkich wolnych miejsc
    int Count_free_parking_spots();

    /// \bierf Funkcja zliczająca zajęte miejsca na parkingu
    /// \return Sum - suma wszystkich zajętych  miejsc
    int Count_taken_parking_spots();

    /// \brief Funkcja sprawdzająca czy mniejsce jest zajęte
    /// \param [int] row - rząd, w którym znajduje się sprawdzane miejsce
    /// \param [int] col - kolumna, w której znajduje się sprawdzane miejsce
    /// \return true or false
    bool isPlaceTaken(int row, int col);

    /// \brief Funkcja sprawdzająca czy mniejsce jest parkingiem
    /// \param [int] row - rząd, w którym znajduje się sprawdzane miejsce
    /// \param [int] col - kolumna, w której znajduje się sprawdzane miejsce
    /// \return true or false
    bool isPlaceParking (int row, int col);

    /// \brief Funkcja sprawdzająca jaki pojad jest na danym polu
    /// \param [int] row - rząd, w którym znajduje się sprawdzane pole
    /// \param [int] col - kolumna, w której znajduje się sprawdzane pole
    /// \return 'name' pojazu: N - none, B - bike, C - car, T - truck
    char WhatVehicle(int row, int col);

    /// \brief Funkcja pozwalająca zmienić infomarmację na temat danego pola
    /// \param [int] row - rząd, w którym znajduje się dane pole
    /// \param [int] col - kolumna, w której znajduje się dane  pole
    /// \param [bool] isTaken - infomacja czy dane pole jest zajęte czy nie
    /// \param [char] WhatVehicle - infomacja jaki pojazd znajduje się na danym polu
    void ChangeFieldInfo(int row, int col, bool isTaken, char WhatVehicle);


};

#endif //PARKING_PARKINGPLACE_H
