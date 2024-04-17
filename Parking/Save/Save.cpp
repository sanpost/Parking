#include "Save.h"

void Save(int FreePlace, int TakenPlace){
    std::fstream Wyniki;
    int AmountOfParkingSpots = FreePlace + TakenPlace;
    Wyniki.open("../Wyniki.txt", std::ios::out);
    if(Wyniki.good()){
        Wyniki << "Liczba wszystkich miejsc na parkingu: " << AmountOfParkingSpots << std::endl;
        Wyniki << "Liczba wolnych miejsc na parkingu: " << FreePlace << std::endl;
        Wyniki << "Liczba zajętych miejsc na parkingu: " << TakenPlace << std::endl;
    }
    else{
        std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
    }
}
