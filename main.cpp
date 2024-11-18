#include <iostream>
#include <cstdlib>
#include "Car.h"
#include <deque>
#include <ctime>

using namespace std;
const int INITIAL_SIZE = 2;

const int NUM_LANES = 4;
const int MAX_INITIAL = 2;
deque<Car> lanes[NUM_LANES];

//does_foo() set the toll que with amount of cars
//return integer

void initialize_lanes(deque<Car< lanes[], int num_lanes){
    for (int i = 0; i < num_lanes; i ++){
        int num_cars = ran() % MAX_INITIAL + 1;
        for (int j = 0; j < num_cars; j++){
            lanes[i].push_back(Car());
        }
    }
}

void switch_lane(){
    if (lanes[current_lane].size() > 1){
        int new_lane;
    }
}

int main() {
    //random time
    srand(time(0));
    //set variable
    int time_step = 1;

    deque<Car> toll_queue;
    for (int i=0; i< INITIAL_SIZE; ++i){
        toll_queue.push_back(Car());
    }
//current que
    cout << "Initial queue: ";
    for (const Car& car: toll_queue){
        car.print();
    }
    cout << endl;
//toll booth for each time step
    while (!toll_queue.empty()){
        int operation = rand() % 100 + 1;
// if less than or equal to 55 leave que
        if (operation <= 55){
            cout << "Time" << time_step << "Operation: Car paid: ";
            toll_queue.front().print();
            toll_queue.pop_front();
        // new car joins
        } else {
            Car new_car;
            cout << "Time" << time_step << "Operation: Joined lane: ";
            new_car.print();
            toll_queue.push_back(new_car);
        }

        cout << "Queue: " << endl;
//print current state
        if(toll_queue.empty()){
            cout << "   Empty" << endl;
        }else{
            for (const Car& car: toll_queue){
                car.print();
            }
        }
        cout << endl;
//increment time
        ++time_step;
    }
    return 0;
}