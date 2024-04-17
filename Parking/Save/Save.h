#ifndef PARKING_SAVE_H
#define PARKING_SAVE_H


#include <fstream>
#include <iostream>

/// Fuknkcja odpowiedzilana za zapisywanie danych do pliku
/// \param [int] FreePlace - ilość wolnych miejsc na parkingu
/// \param [int] TakenPlace - ilość zajętych miejsc na parkingu
void Save(int FreePlace, int TakenPlace);


#endif //PARKING_SAVE_H
