//
// 26.04.2022.
//

#include <iostream>
#include "ParkingPlace.h"

Parking_Place::Parking_Place(int width, int height) {
    this->width = width;
    this->height = height;


    for(int row=0; row<height; row++) {

        for(int col=0; col<width; col++){
            Board[row][col].what_vehicle = 'N'; // na poczatku na planszy nie ma zadnego pojazdu
        }
    }


    // petla, piersszy rzad to parking, dwa kolejne to droga
    for(int row=0; row<height; row++) {

        for(int col=0; col<width; col++){
            int y = row % 3;
            if (y == 0) {
                Board[row][col].isParking = true;
            } else {
                Board[row][col].isParking = false;
            }
        }
    }

}


// zwraca szerokosci
int Parking_Place::getBoardWidth() {
    return width;
}

// zwraca wysokosci
int Parking_Place::getBoardHeight() {
    return height;
}

// zliczanie wolnych miejsc
int Parking_Place::Count_free_parking_spots() {
    int Sum = 0;
    for(int row = 0; row<height; row++){
        for(int col = 0; col<width; col++){
            if(Board[row][col].isParking && !Board[row][col].isTaken){
                Sum++;
            }
        }
    }
    return Sum;
}
// zliczanie zajętych miejsc
int Parking_Place::Count_taken_parking_spots() {
    int Sum = 0;
    for(int row = 0; row<height; row++){
        for(int col = 0; col<width; col++){
            if(Board[row][col].isParking && Board[row][col].isTaken){
                Sum++;
            }
        }
    }
    return Sum;
}

bool Parking_Place::isPlaceTaken(int row, int col) {
    if(Board[row][col].isTaken){
        return true;
    }
    return false;
}

bool Parking_Place::isPlaceParking(int row, int col) {
    if(Board[row][col].isParking){
        return true;
    }
    return false;
}

char Parking_Place::WhatVehicle(int row, int col) {
    if(Board[row][col].what_vehicle == 'N'){
        return 'N';
    }
    if(Board[row][col].what_vehicle == 'B'){
        return 'B';
    }
    if(Board[row][col].what_vehicle == 'C'){
        return 'C';
    }
    if(Board[row][col].what_vehicle == 'T'){
        return 'T';
    }
}

void Parking_Place::ChangeFieldInfo(int row, int col, bool isTaken, char WhatVehicle) {
    Board[row][col].isTaken = isTaken;
    Board[row][col].what_vehicle = WhatVehicle;
}
