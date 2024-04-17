#ifndef PARKING_VEHICLE_H
#define PARKING_VEHICLE_H

#include <iostream>
#include "../Parking_Place/ParkingPlace.h"

using namespace std;

/// Klasa odpowiedzialna za pozycję pojazdu
/// \param [int] V_row - rząd, w którym znajduje się pojzad
/// \param [int] V_col - kolumna, w której znajduje się pojazd
struct Position{
    int V_row;
    int V_col;
};

/// Klasa nadrzędna
class Vehicle{
public:
    /// \brief Funkcja odpowiedzialna za pojawienie się pojazdu na planszy
    /// \param p - parking
    virtual void SetVehicleOnBoard(Parking_Place & p)=0;

    /// \brief Funkcja odpowiedzialna za poruszanie się pojazdu po planszy
    /// \param p - parking
    virtual void move(Parking_Place & p)=0;

    /// \brief Funkcja odpowiedzialna za parkowanie pojazdu na miejscu parkingowym
    /// \param p - parking
    virtual void park(Parking_Place & p)=0;

    /// \brief Funkcja odpowiedzialna za opuszczanie miejsca parkingowego
    /// \param p - parking
    virtual void leave_parking_spot(Parking_Place & p)=0;

    /// \brief Funkcja odpowiedzialna za sprawdzanie czy pojazd może wjechać na miejsce parkingowe
    /// \param p - parking
    /// \return true or fale
    virtual bool check_parking_spot_in(Parking_Place & p)=0;

    /// \brief Funkcja odpowiedzialna za sprawdzanie czy pojazd może wyjechać z miejsca parkingowego
    /// \param p - parking
    /// \return true or fale
    virtual bool check_parking_spot_out(Parking_Place & p)=0;
};

#endif //PARKING_VEHICLE_H
