#ifndef PARKING_SFMLPARKING_H
#define PARKING_SFMLPARKING_H


#include "../Parking_Place/ParkingPlace.h"
#include "SFML/Graphics.hpp"

/// Klasa odpowiedzialna za rysowanie
class SFMLParking{
    Parking_Place & Parking;

    sf::RectangleShape road_spot;
    sf::RectangleShape parking_spot;
    sf::RectangleShape Bike;
    sf::RectangleShape Car;
    sf::RectangleShape Truck;

public:

    explicit SFMLParking(Parking_Place & p);

    /// Funkcja odpowiedzialna za rysowanie ramki
    void drawFrame (sf::RenderWindow & win);

    /// Funkcja odpowiedzialna za rysowanie
    void draw (sf::RenderWindow & win);

};

#endif //PARKING_SFMLPARKING_H
