#include <iostream>
#include <cstdlib>
#include "Car.h"
#include <deque>
#include <ctime>

using namespace std;
const int INITIAL_SIZE = 2;

const int NUM_LANES = 4;
const int MAX_INITIAL = 2;
const double PROB_PAY = 0.46;
const double PROB_JOIN = 0.39;
const double PROB_SWITCH = 0.15;
const int SIMULATION_TIMES = 20;
deque<Car> lanes[NUM_LANES];

//does_foo() set the toll que with amount of cars
//return integer

class Car{
private:
    string make;
    int year;
    int id;

public:
    Car(string m = "Default", int y = 2000, int i = 0) : make(m), year(y), id(i) {}
    
    friend ostream& operator<<(ostream& os, const Car& car) {
        os << car.year << " " << car.make << " (" << car.id << ")";
        return os;
    }

}

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
        do{
            new_lane = rand() % NUM_LANES;
        } while (new_lane == current_lane);
        Car car_to_move = lanes[current_lane].back();
        lanes[current_lane].pop_back();
        lanes[new_lane].push_back(car_to_move);
        cout << "Lane" << current_lane + 1 << " Switched: [" << car_to_move << "] to Lane " << new_lane + 1 << endl;
    }
}

int main() {
    //random time
    srand(time(0));
    //set variable
    int time_step = 1;
    deque<Car> lanes[NUM_LANES];
    initialize_lanes(lanes, NUM_LANES);

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

    for (int time =1; time <= SIMULATION_TIMES; time ++){
        cout << "Time: " << time << endl;
        for (int lane = 0; lance < NUM_LANES; lanes++){
            if(!lanes[lane].empty()){
                double rand_val= (double)rand() / RAND_MAX;

                if (rand_val < PROB_PAY){
                    Car car = lanes[lane].front();
                    lanes[lane].pop_front();

                    cout << "Lane " << lane + 1 << " Paid: [" << car << "]" << endl;
                }

                else if(rand_val < PROB_PAY + PROB_JOIN){
                    
                }
            }
        }
    }
}