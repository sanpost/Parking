#ifndef PARKING_CAR_H
#define PARKING_CAR_H

#include "../../MainClassVehicle/Vehicle.h"
#include "../../Parking_Place/ParkingPlace.h"

/// \brief Klasa Car to klasa podrzędna i dziedziczy po klasie Vehicle
/// \param [int] length - 2
/// \param [char] name - C
class Car : public Vehicle{
    int length;
    char name;

    /// pozycja auta
    Position position;

    /// Sprawdza czy pojazd zawrócił
    bool go_back;

    /// Sprawdza czy pojazd już wcześniej był zaparkowany
    bool was_parked;

    /// Sprawdza czy pojazd opóścił parking
    bool left_parking;

    /// Sprawdza czy auto jest w trakcie zawracania
    bool car_turn;

    /// Sprawdza czy auto wykonało pierwszy ruch
    bool car_First_move;

    /// Sprawdza  czy pojazd jest na planszy
    bool isOnBoard;

    /// Odlicza czas pozjadu na parkingu
    int ParkingCounter;
public:
    Car();
    /// \brief Funkcja odpowiedzialna za pojawienie się auta na planszy
    /// \param p - parking
    virtual void SetVehicleOnBoard(Parking_Place & p);

    /// \brief Funkcja odpowiedzialna za poruszanie się auta po planszy
    /// \param p - parking
    virtual void move(Parking_Place & p);

    /// \brief Funkcja odpowiedzialna za parkowanie auta na miejscu parkingowym
    /// \param p - parking
    virtual void park(Parking_Place & p);

    /// \brief Funkcja odpowiedzialna za opuszczanie miejsca parkingowego
    /// \param p - parking
    virtual void leave_parking_spot(Parking_Place & p);

    /// \brief Funkcja odpowiedzialna za sprawdzanie czy pojazd może wjechać na miejsce parkingowe
    /// \param p - parking
    /// \return true or fale
    virtual bool check_parking_spot_in(Parking_Place & p);

    /// \brief Funkcja odpowiedzialna za sprawdzanie czy pojazd może wyjechać z miejsca parkingowego
    /// \param p - parking
    /// \return true or fale
    virtual bool check_parking_spot_out(Parking_Place & p);
};

#endif //PARKING_CAR_H
