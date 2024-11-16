#include <iostream>
#include <cstdlib>
#include "Car.h"

using namespace std;

int main() {
    srand(time(0));
    int time = 1;

    deque<Cae> toll_queue;
    for (int i=0; i< initial_size; ++i){
        toll.Queue.push_back();
    }

    cout << "Initial queue: ";
    for (const Car& car: toll_que){
        car.print();
    }

    while (!tollQueue.empty()){
        int operation = rand() % 100 + 1;

        if (operation <= 55){
            cout << "Time" << time << "Operation: Car paid: ";
            tollQueue.front().print();
            tollQueue.pop_front();
        } else {
            Car new_car;
            cout << "Time" << time << "Operation: Joined lane: ";
            new_car.print();
            tollQueue.push_back(new_car);
        }

        if(){

        }else{

        }
    }
}