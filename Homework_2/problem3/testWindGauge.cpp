#include <iostream>
#include "WindGauge.h"

using namespace std;

int main () {
    WindGauge gauge1(12);           //intialize gauge

    //add the speeds
    gauge1.currentWindSpeed(15);
    gauge1.currentWindSpeed(16);
    gauge1.currentWindSpeed(12);
    gauge1.currentWindSpeed(15);
    gauge1.currentWindSpeed(15);

    cout << "Before adding the new speeds: " << endl;
    gauge1.printSpeeds();           //print out the wind speed statistics

    //add new speeds
    gauge1.currentWindSpeed(16);
    gauge1.currentWindSpeed(17);
    gauge1.currentWindSpeed(16);
    gauge1.currentWindSpeed(16);
    gauge1.currentWindSpeed(20);
    gauge1.currentWindSpeed(17);
    gauge1.currentWindSpeed(16);
    gauge1.currentWindSpeed(15);
    gauge1.currentWindSpeed(16);
    gauge1.currentWindSpeed(20);

    cout << "After adding the new speeds: " << endl;
    gauge1.printSpeeds();           //print out the new wind statistics

    return 0;
}