#include <iostream>
#include <cstdlib>
#include "Car.h"
#include <deque>
#include <ctime>

using namespace std;

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

};

void initialize_lanes(deque<Car< lanes[], int num_lanes){
    for (int i = 0; i < num_lanes; i ++){
        int num_cars = ran() % MAX_INITIAL + 1;
        for (int j = 0; j < num_cars; j++){
            lanes[i].push_back(Car("CarMake" + to_string(rand() % 100), 1990 + rand() % 34, rand() % 10000));
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
    deque<Car> lanes[NUM_LANES];
    initialize_lanes(lanes, NUM_LANES);

    deque<Car> toll_queue;
//current que
    cout << "Initial queue: ";

    for (int lane = 0; lane < NUM_LANES; lane++){
        cout << "Lane " << lane + 1 << " Queue: ";
        if(lanes[lane].empty()){
            cout << "empty";
        } else {
            for(const Car& car : lanes[lane]){
                cout << "[" << car << "]";
            }
        }
        cout << endl;
    }

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
                    Car new_car("CarMake" + to_string(rand() % 100), 1990 + rand() % 34, rand() % 10000);
                    lanes[lane].push_back (new_car);
                    cout << "Lane" << lane + 1 << " Joined: [" << new_car << "]" << endl;
                } else if(rand_val < PROB_PAY + PROB_JOIN + PROB_SWITCH){
                    switch_lane(lanes, lane);
                }
            }
        }
    }

    for (int lane = 0; lane< NUM)

}