#include <iostream>
#include <deque>
#include <iterator>

using namespace std;

int main () {
    deque<float> A;     //initialize float deque

    while (true) {
        float num;

        cin >> num;             //ask for input
        if (num == 0) break;    //if input is 0, the loop is broken

        //if the number is postive, it is pushed back
        //if the number is negative, it is pushed to the front
        (num > 0) ? A.push_back(num) : A.push_front(num);
    }

    //print the elements on stdout
    for (auto elemA : A) {
        cout << elemA << " ";
    }
    cout << endl << endl;

    //loop that finds the first postive value in the vector
    for (auto it = A.begin(); it != A.end(); it++) {
        if (*it > 0) {          //check if iterator has reached it
            A.insert(it, 0);    //if so, 0 is insterted and loop is broken
            break;
        }
    }

    //print out the contenet of the dequeue again
    for (auto it = A.begin(); it != A.end(); it++) {
        if (*it == A.back()) {      //if statement that makes sure no trailing
            cout << *it << endl;    //"," is left
        }
        else {
            cout << *it << "; ";
        }
    }

    return 0;
}