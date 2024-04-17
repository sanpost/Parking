#ifndef PARKING_TRUCK_H
#define PARKING_TRUCK_H

#include "../../MainClassVehicle/Vehicle.h"
#include "../../Parking_Place/ParkingPlace.h"

/// \brief Klasa Truck to klasa podrzędna i dziedziczy po klasie Vehicle
/// \param [int] length - 3
/// \param [char] name - T
class Truck : public Vehicle{
    int length;
    char name;

    /// pozycja ciężarówki
    Position position;

    /// Sprawdza czy pojazd zawrócił
    bool go_back;

    /// Sprawdza czy pojazd już wcześniej był zaparkowany
    bool was_parked;

    /// Sprawdza czy pojazd opóścił parking
    bool left_parking;

    /// Sprawdza czy ciężarkówka jest w trakcie pierwszego zawracania
    bool truck_turn;

    /// Sprawdza czy ciężarówka  jest w trakcie drugiego  zawracania
    bool truck_turn1;

    /// Sprawdza czy ciężarówka wykonała pierwszy ruch
    bool truck_First_move;

    /// Sprawdza czy ciężarówka wykonała drugi ruch
    bool truck_First_move1;

    /// Sprawdza  czy pojazd jest na planszy
    bool isOnBoard;

    /// Odlicza czas pozjadu na parkingu
    int ParkingCounter;
public:
    Truck();
    /// \brief Funkcja odpowiedzialna za pojawienie się ciężarówki na planszy
    /// \param p - parking
    virtual void SetVehicleOnBoard(Parking_Place & p);

    /// \brief Funkcja odpowiedzialna za poruszanie się ciężarówki po planszy
    /// \param p - parking
    virtual void move(Parking_Place & p);

    /// \brief Funkcja odpowiedzialna za parkowanie ciężarówki na miejscu parkingowym
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

#endif //PARKING_TRUCK_H
