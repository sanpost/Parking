#include "SFMLParking.h"

SFMLParking::SFMLParking(Parking_Place &p) : Parking(p) {
    road_spot.setFillColor(sf::Color::White);
    road_spot.setSize(sf::Vector2f(20, 5));

    parking_spot.setSize(sf::Vector2f(20, 20));
    parking_spot.setFillColor(sf::Color::Green);

    Bike.setFillColor(sf::Color::Magenta);
    Bike.setSize(sf::Vector2f(20, 8));

    Car.setFillColor(sf::Color::Blue);
    Car.setSize(sf::Vector2f(20, 15));

    Truck.setFillColor(sf::Color::Red);
    Truck.setSize(sf::Vector2f(20, 20));
}

void SFMLParking::draw(sf::RenderWindow &win) {

    int x;
    int y=0;

    drawFrame(win);

    for(int row=0; row<Parking.getBoardHeight(); row++) {
        x = 0;
        for(int col=0; col<Parking.getBoardWidth(); col++){

            // PARKING //
            char c = Parking.WhatVehicle(row, col);
            switch(c) {
                case 'N': {
                    if(Parking.isPlaceParking(row,col)){
                        parking_spot.setPosition(static_cast<float>(30 + x), static_cast<float>(30 + y));
                        win.draw(parking_spot);
                        x = x + 30;
                        break;
                    }
                    else{
                        road_spot.setPosition(static_cast<float>(30 + x), static_cast<float>(37 + y));
                        win.draw(road_spot);
                        x = x + 30;
                        break;
                    }
                }
                case 'B': {

                    Bike.setPosition(static_cast<float>(30 + x), static_cast<float>(30 + y));
                    win.draw(Bike);

                    x = x + 30;
                    break;
                }
                case 'C': {
                    Car.setPosition(static_cast<float>(30 + x), static_cast<float>(30 + y));
                    win.draw(Car);

                    x = x + 30;
                    break;
                }
                case 'T': {
                    Truck.setPosition(static_cast<float>(30 + x), static_cast<float>(30 + y));
                    win.draw(Truck);

                    x = x + 30;
                    break;
                }
            }
        }
        y = y+30;
    }
}

void SFMLParking::drawFrame(sf::RenderWindow & win) {

    int col = Parking.getBoardWidth();
    int row = Parking.getBoardHeight();

    sf::RectangleShape c{{static_cast<float>(30+(30*col)), static_cast<float>(30+(30*row))}};
    c.setOutlineThickness(5);
    c.setOutlineColor(sf::Color{sf::Color::White});
    c.setFillColor ( sf::Color::Black );
    c.setPosition(10, 10);
    win.draw(c);

}