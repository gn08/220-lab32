#include <iostream>
#include <cstdlib>
#include "Car.h"
#include <deque>
#include <ctime>

using namespace std;
const int INITIAL_SIZE = 2;

int main() {
    srand(time(0));
    int time_step = 1;

    deque<Car> toll_queue;
    for (int i=0; i< INITIAL_SIZE; ++i){
        toll_queue.push_back(Car());
    }

    cout << "Initial queue: ";
    for (const Car& car: toll_queue){
        car.print();
    }
    cout << endl;

    while (!tollQueue.empty()){
        int operation = rand() % 100 + 1;

        if (operation <= 55){
            cout << "Time" << time_step << "Operation: Car paid: ";
            toll_queue.front().print();
            toll_queue.pop_front();
        } else {
            Car new_car;
            cout << "Time" << time_step << "Operation: Joined lane: ";
            new_car.print();
            toll_queue.push_back(new_car);
        }

        cout << "Queue: " << endl;

        if(toll_queue.empty()){
            cout << "   Empty" << endl;
        }else{
            for (const Car& car: toll_queue){
                car.print();
            }
        }
        cout << endl;

        ++time_step;
    }
    return 0;
}