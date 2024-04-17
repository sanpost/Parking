#include "Truck.h"

Truck::Truck() {
    length = 3;
    name = 'T';

    go_back= false;
    was_parked= false;
    left_parking= false;

    truck_turn = false;
    truck_turn1 = false;

    truck_First_move = true;
    truck_First_move1 = true;

    isOnBoard = false;

    ParkingCounter = 30;
}

void Truck::SetVehicleOnBoard(Parking_Place &p){
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
        // pojazd moze sie pojawic na pierszym, drugim i trzecim miejscu tylko wtedy gdy to miejsce nie jest zajete
        if(!p.isPlaceTaken(row, 0) && !p.isPlaceTaken(row, 1)){
            p.ChangeFieldInfo(row, 0, true, 'T');

            truck_First_move = true;
            truck_First_move1 = true;
            isOnBoard = true;
        }
    }
}
void Truck::move(Parking_Place &p) {
    if(!isOnBoard){
        return;
    }
    if(truck_First_move){
        if(truck_First_move1){
            if(p.isPlaceTaken(position.V_row, position.V_col+1)){return;}
            p.ChangeFieldInfo(position.V_row, position.V_col+1, false, 'T');

            truck_First_move1 = false;
            return;
        }
        if(p.isPlaceTaken(position.V_row, position.V_col+2)){return;}
        p.ChangeFieldInfo(position.V_row, position.V_col+2, true, 'T');

        truck_First_move1 = false;
        truck_First_move = false;
        return;
    }
    if(!was_parked && check_parking_spot_in(p)){
        park(p);
        return;
    }
    if( !left_parking && was_parked){
        if(!check_parking_spot_out(p)){
            return;
        }
        leave_parking_spot(p);
        return;
    }

    if(!go_back) {
        if (position.V_col < (p.getBoardWidth())-3) {
            p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

            p.ChangeFieldInfo(position.V_row, position.V_col+1, false, 'N');

            p.ChangeFieldInfo(position.V_row, position.V_col+2, false, 'N');

            position.V_col = position.V_col + 1;

            p.ChangeFieldInfo(position.V_row, position.V_col, true, 'T');

            p.ChangeFieldInfo(position.V_row, position.V_col+1, true, 'T');

            p.ChangeFieldInfo(position.V_row, position.V_col+2, true, 'T');
        }
        else {
            p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

            p.ChangeFieldInfo(position.V_row, position.V_col+1, false, 'N');

            p.ChangeFieldInfo(position.V_row, position.V_col+2, false, 'N');


            position.V_col = position.V_col + 2;
            position.V_row = position.V_row + 1;

            go_back = true;
            truck_turn = true;
            truck_turn1 = true;
            p.ChangeFieldInfo(position.V_row, position.V_col, true, 'T');

            p.ChangeFieldInfo(position.V_row-1, position.V_col, true, 'T');

            p.ChangeFieldInfo(position.V_row-1, position.V_col-1, true, 'T');
            return;
        }
    }
    if(go_back){
        if(truck_turn){
            if(truck_turn1){
                p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

                p.ChangeFieldInfo(position.V_row-1, position.V_col, false, 'N');

                p.ChangeFieldInfo(position.V_row-1, position.V_col-1, false, 'N');

                //
                p.ChangeFieldInfo(position.V_row-1, position.V_col, true, 'T');

                p.ChangeFieldInfo(position.V_row, position.V_col, true, 'T');

                p.ChangeFieldInfo(position.V_row, position.V_col-1, true, 'T');

                truck_turn1 = false;
            }
            else{
                p.ChangeFieldInfo(position.V_row-1, position.V_col, false, 'N');

                p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

                p.ChangeFieldInfo(position.V_row, position.V_col-1, false, 'N');

                //
                p.ChangeFieldInfo(position.V_row, position.V_col, true, 'T');

                p.ChangeFieldInfo(position.V_row, position.V_col-1, true, 'T');

                p.ChangeFieldInfo(position.V_row, position.V_col-2, true, 'T');

                truck_turn = false;
            }
        }
        else {
            p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

            p.ChangeFieldInfo(position.V_row, position.V_col-1, false, 'N');

            p.ChangeFieldInfo(position.V_row, position.V_col-2, false, 'N');

            position.V_col = position.V_col - 1;

            p.ChangeFieldInfo(position.V_row, position.V_col, true, 'T');

            p.ChangeFieldInfo(position.V_row, position.V_col-1, true, 'T');

            p.ChangeFieldInfo(position.V_row, position.V_col-2, true, 'T');
        }
    }
}
void Truck::park(Parking_Place &p) {
    p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

    p.ChangeFieldInfo(position.V_row, position.V_col + 1, false, 'N');

    p.ChangeFieldInfo(position.V_row, position.V_col + 2, false, 'N');

    position.V_row = position.V_row - 1;

    p.ChangeFieldInfo(position.V_row, position.V_col, true, 'T');

    p.ChangeFieldInfo(position.V_row, position.V_col + 1, true, 'T');

    p.ChangeFieldInfo(position.V_row, position.V_col + 2, true, 'T');

    was_parked= true;
}
void Truck::leave_parking_spot(Parking_Place &p) {
    p.ChangeFieldInfo(position.V_row, position.V_col, false, 'N');

    p.ChangeFieldInfo(position.V_row, position.V_col+1, false, 'N');

    p.ChangeFieldInfo(position.V_row, position.V_col+2, false, 'N');

    position.V_row = position.V_row + 1;

    p.ChangeFieldInfo(position.V_row, position.V_col, true, 'T');

    p.ChangeFieldInfo(position.V_row, position.V_col+1, true, 'T');

    p.ChangeFieldInfo(position.V_row, position.V_col+2, true, 'T');

    left_parking = true;
}
bool Truck::check_parking_spot_in(Parking_Place &p) {
    if(p.isPlaceParking(position.V_row-1, position.V_col)
        && p.isPlaceParking(position.V_row-1, position.V_col+1)
            && p.isPlaceParking(position.V_row-1, position.V_col+2)){
                if(!p.isPlaceTaken(position.V_row-1, position.V_col)
                    && !p.isPlaceTaken(position.V_row-1, position.V_col+1)
                        && !p.isPlaceTaken(position.V_row-1, position.V_col+2)){
                        return true;
        }
    }
    return false;
}
bool Truck::check_parking_spot_out(Parking_Place &p) {

    if(ParkingCounter>0){
        ParkingCounter--;
        return false;
    }

    if(!p.isPlaceTaken(position.V_row+1, position.V_col-1)
        && !p.isPlaceTaken(position.V_row+1, position.V_col)
            && !p.isPlaceTaken(position.V_row+1, position.V_col+1)
                && !p.isPlaceTaken(position.V_row+1, position.V_col+2)
                    && !p.isPlaceTaken(position.V_row+1, position.V_col+3)){
                    return true;
    }
        return false;
}