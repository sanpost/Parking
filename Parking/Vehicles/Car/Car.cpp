#include "Car.h"

Car::Car() {
    length=2;
    name='C';

    go_back= false;
    was_parked= false;
    left_parking= false;

    car_turn = false;
    car_First_move = true;

    isOnBoard = false;

    ParkingCounter = 30;
}


void Car::SetVehicleOnBoard(Parking_Place &p) {
    // losowanie, w ktorym rzedzie ma sie pojawic auto
    int collumn = (p.getBoardHeight()/3);
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
        position.V_col = 0;

        // pojazd moze sie pojawic na pierszym i drugim  miejscu tylko wtedy gdy to miejsce nie jest zajete
        if(!p.isPlaceTaken(row, 0) && !p.isPlaceTaken(row, 1)){

            p.ChangeFieldInfo(row, 0, true, 'C');

            car_First_move = true;
            isOnBoard = true;
        }
    }
}
void Car::move(Parking_Place &p) {
    if(!isOnBoard){
        return;
    }
        if(car_First_move){
            if(p.isPlaceTaken(position.V_row, position.V_col+1)){return;}

            p.ChangeFieldInfo(position.V_row, position.V_col+1, true, 'C');

            car_First_move = false;
            return;
        }
        if( !was_parked && check_parking_spot_in( p)){
            park(p);
            return;
        }
        if(!left_parking && was_parked){
            if(!check_parking_spot_out(p)){
                return;
            }
            leave_parking_spot(p);
            return;
        }

        if(!go_back) {
            if (position.V_col < (p.getBoardWidth())-2) {
                p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

                p.ChangeFieldInfo(position.V_row, position.V_col+1, false, 'N');

                position.V_col = position.V_col + 1;

                p.ChangeFieldInfo(position.V_row, position.V_col, true, 'C');

                p.ChangeFieldInfo(position.V_row, position.V_col+1, true, 'C');
            }
            else{
                p.ChangeFieldInfo(position.V_row, position.V_col+1, false, 'N');

                p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

                position.V_col++;

                go_back = true;
                car_turn = true;

                p.ChangeFieldInfo(position.V_row, position.V_col, true, 'C');

                p.ChangeFieldInfo(position.V_row+1, position.V_col, true, 'C');
            }
        }
        else{
            if(car_turn){
                p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

                p.ChangeFieldInfo(position.V_row+1, position.V_col, false, 'N');

                position.V_row++;

                p.ChangeFieldInfo(position.V_row, position.V_col, true, 'C');


                p.ChangeFieldInfo(position.V_row, position.V_col-1, true, 'C');

                car_turn = false;
            }
            else{
                p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

                p.ChangeFieldInfo(position.V_row, position.V_col-1, false, 'N');

                position.V_col--;

                p.ChangeFieldInfo(position.V_row, position.V_col, true, 'C');

                p.ChangeFieldInfo(position.V_row, position.V_col-1, true, 'C');
            }
        }
}
void Car::park(Parking_Place &p) {
    p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

    p.ChangeFieldInfo(position.V_row, position.V_col+1, false, 'N');

    position.V_row = position.V_row - 1;

    p.ChangeFieldInfo(position.V_row, position.V_col, true, 'C');

    p.ChangeFieldInfo(position.V_row, position.V_col+1, true, 'C');

    was_parked= true;
}
void Car::leave_parking_spot(Parking_Place &p) {
    p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

    p.ChangeFieldInfo(position.V_row, position.V_col+1, false, 'N');

    position.V_row = position.V_row + 1;

    p.ChangeFieldInfo(position.V_row, position.V_col, true, 'C');

    p.ChangeFieldInfo(position.V_row, position.V_col+1, true, 'C');
    left_parking = true;
}
bool Car::check_parking_spot_in(Parking_Place &p) {
    if(!p.isPlaceTaken(position.V_row-1, position.V_col) && !p.isPlaceTaken(position.V_row-1, position.V_col+1)){
        return true;
    }
    return false;
}
bool Car::check_parking_spot_out(Parking_Place &p) {
    if(ParkingCounter>0){
        ParkingCounter--;
        return false;
    }

    if(!p.isPlaceTaken(position.V_row+1, position.V_col-1)
        && !p.isPlaceTaken(position.V_row+1, position.V_col)
            && !p.isPlaceTaken(position.V_row+1, position.V_col+1)
                && !p.isPlaceTaken(position.V_row+1, position.V_col+2)){
                return true;
    }
    return false;
}
