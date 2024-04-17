#include <iostream>
#include "SFML/Graphics.hpp"
#include "Parking_Place/ParkingPlace.h"
#include "SFMLParking_Place/SFMLParking.h"
#include "Vehicles/Bike/Bike.h"
#include "Vehicles/Car/Car.h"
#include "Vehicles/Truck/Truck.h"
#include "Save/Save.h"

// Pierwsza czesc od lewej
// pojazdu to ta glowna !! //

int main() {

    srand (time(NULL));

    //Okno, w ktorym wieswietla sie plansza
    sf::RenderWindow window(sf::VideoMode(1600, 900), "PARKING");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    // uzytkownik podaje wysokość(height), która będzie liczbą podzielna przez 3 i nie większą niż 21. Szerokość dowolna.
    int width = 0;
    int height = 0;

    cout << "Podaj szerokosc planszy: " << endl;
    cin >> width;
    do {
        if(height%3 != 0){
            cout << "Podzielna przez 3!" << endl;
        }
        if(height > 21){
            cout << "Mniejsza od 21!" << endl;
        }
        cout << "Podaj wysokosc planszy (liczba podzielna przez 3 i nie wieksza od 21): " << endl;
        cin >> height;
    }
    while(height%3!=0 || height > 21);

    Parking_Place parking(width, height);
    SFMLParking view(parking);


    // liczba pojazdow na plaszy
    int number = 0;

    cout << "Podaj liczbe pojadow (bedzie to liczba ilosci pojazdow kazdego rodzaju): " << endl;
    cin >> number;

    Bike bike[number];
    Car car[number];
    Truck truck[number];

    // Czas //

    sf::Clock Move_clock;
    sf::Time Move_elapsed;

    // Czas //

    bool STOP = false;


    // wydarzenie, jesli sie wcisnie sie spacje, symulacja sie zatrzymuje
    sf::Event event;

    while (window.isOpen()) {
        Move_elapsed = Move_clock.getElapsedTime();
            //std::cout << StopTime_elapsed.asSeconds() << std::endl;


            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    continue;
                }
                if (event.key.code == sf::Keyboard::Space) {
                    Save(parking.Count_free_parking_spots(), parking.Count_taken_parking_spots());
                    STOP = true;
                }
            }
        window.clear(); //czyszczenie okna
        if(Move_elapsed.asMilliseconds() > 650) {
            if (!STOP) {
                // petla poruszanie sie
                for (int i = 0; i < number; i++) {
                    bike[i].move(parking);
                    car[i].move(parking);
                    truck[i].move(parking);
                }
                // petla tworzenie pojazdow
                for (int i = 0; i < number; i++) {
                    bike[i].SetVehicleOnBoard(parking);
                    car[i].SetVehicleOnBoard(parking);
                    truck[i].SetVehicleOnBoard(parking);
                }
            }
            Move_clock.restart();
        }
        view.draw(window); // rysowanie w oknie
        window.display(); // wysietlanie okna
    }
        return 0;
}
