#include <iostream>
#include <algorithm>
#include <numeric>
#include "WindGauge.h"

using namespace std;

//constructor
WindGauge::WindGauge(int period) {
    this->period = period;
}

//add the current wind speed
void WindGauge::currentWindSpeed(int speed) {
    speeds.push_back(speed);
    if (period == (int) speeds.size()) {    //check if history is longer
        speeds.pop_front();     //if so, pop the oldest entry
    }
}

//return the current highest speed
int WindGauge::highest() const {
    return *max_element(speeds.begin(), speeds.end());
}

//return the current lowest speed
int WindGauge::lowest() const {
    return *min_element(speeds.begin(), speeds.end());
}

//return the current average speed
int WindGauge::average() const {
    return accumulate(speeds.begin(), speeds.end(), 0)/speeds.size();
}

//print function that dumps statistics of the current wind speeds
void WindGauge::printSpeeds() const {
    cout << "Highest speed: " << highest() << endl;
    cout << "Lowest speed: " << lowest() << endl;
    cout << "Average speed: " << average() << endl;
}