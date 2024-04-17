#include "Bike.h"

Bike::Bike() {
    length = 1;
    name = 'B';

    go_back= false;
    was_parked= false;
    left_parking= false;

    isOnBoard = false;

    ParkingCounter = 30;
}

void Bike::SetVehicleOnBoard(Parking_Place & p) {
    int collumn = (p.getBoardHeight()/3);

    //losowanie, w ktorym rzedzie ma sie pojawic rower

    if(!isOnBoard) {
        int row = rand() % collumn + 1;
        switch (row) {
            case 1: {
                row = 1;
                break;
            }
            case 2: {
                row = 4;
                break;
            }
            case 3: {
                row = 7;
                break;
            }
            case 4: {
                row = 10;
                break;
            }
            case 5: {
                row = 13;
                break;
            }
            case 6: {
                row = 16;
                break;
            }
            case 7: {
                row = 19;
                break;
            }
        }
        position.V_row = row;
        position.V_col= 0;

        //pojazd moze sie pojawic na pierszym miejsc tylko wtedy gdy to miejsce nie jest zajete
        if(!p.isPlaceTaken(row, 0) && !p.isPlaceTaken(row, 1)){
            p.ChangeFieldInfo(row, 0, true, 'B');
            // piersze miejsce staje sie zajete
            // pierwsze miejsce otrzymuje nazwe pojazdu

            isOnBoard = true;
        }
    }
}
void Bike::move(Parking_Place &p) {
    if(!isOnBoard){
        return;
    }

    if(position.V_col<0){
        p.ChangeFieldInfo(position.V_row, position.V_col, false, 'B');
        return;
    }

    if(!was_parked && check_parking_spot_in(p)){  //sparwda czy miejsce jest wolne, parkuje tylko raz
        park(p); // parkuje
        return;
    }
    if( !left_parking && was_parked ){ //jest na parking
        if(!check_parking_spot_out(p)){ // sparwdza czy moze wyjechac
            return;
        }
        leave_parking_spot(p); //opuszcza miejsce parkingowe
        return;
    }


    if(!go_back) { //zawracanie
        if (position.V_col < (p.getBoardWidth())-1) {
            p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

            position.V_col = position.V_col + 1;

            p.ChangeFieldInfo(position.V_row, position.V_col, true, 'B');
            return;
        }
        else {
            p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

            position.V_row = position.V_row + 1;
            go_back = true;

            p.ChangeFieldInfo(position.V_row, position.V_col, true, 'B');
            return;
        }
    }
    if(go_back){
        p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

        position.V_col=position.V_col-1;

        p.ChangeFieldInfo(position.V_row, position.V_col, true, 'B');
        return;
    }
}
void Bike::park(Parking_Place &p) {
    // droga staje sie wolna
    p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

    position.V_row = position.V_row-1;

    // miejsce parkingowe staje sie zajete
    p.ChangeFieldInfo(position.V_row, position.V_col, true, 'B');

    was_parked= true;
}
void Bike::leave_parking_spot(Parking_Place &p) {
    // miejsce parkingowe staje sie wolne
    p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

    position.V_row = position.V_row + 1;

    // droga staje sie zajeta
    p.ChangeFieldInfo(position.V_row, position.V_col, true, 'B');

    left_parking = true;
}
bool Bike::check_parking_spot_in(Parking_Place &p) {
    // moze zaparkowac jesli miesce pole nad nim jest parkingiem i jest wolne
    if(p.isPlaceParking(position.V_row-1, position.V_col) && !p.isPlaceTaken(position.V_row-1, position.V_col)){
        return true;
    }
    return false;
}
bool Bike::check_parking_spot_out(Parking_Place &p) {
    if(ParkingCounter>0){
        ParkingCounter--;
        return false;
    }
//moze wyjechac jeli pole pod nim jest wolne
    if(!p.isPlaceTaken(position.V_row+1, position.V_col-1)
        && !p.isPlaceTaken(position.V_row+1, position.V_col)
            && !p.isPlaceTaken(position.V_row+1, position.V_col+1)){
            return true;
    }
    return false;
}

