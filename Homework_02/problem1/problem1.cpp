#include <iostream>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

int main () {
    list<int> A, B;     //initialize list A and B

    while (true) {
        int num;

        cin >> num;
        if (num <= 0) break;    //if the input is 0 or less, break out of loop

        //push the inputed integer
        A.push_back(num);
        B.push_front(num);
    }

    //print the elements of list A
    for (int elemA : A) {
        cout << elemA << " ";
    }
    cout << endl;

    //print the elements of list B into a file
    ofstream file;
    if (!file.is_open()) {
        exit(0);
    }
    file.open("listB.txt");
    for (int elemB : B) {
        file << elemB << " ";
    }
    file.close();
    cout << endl;
    
    //Move the first element of A and B to the back
    A.push_back(*A.begin());
    A.pop_front();
    B.push_back(*B.begin());
    B.pop_front();

    for (auto it = A.begin(); it != A.end(); it++) {
        if (*it == A.back()) {      //check if the loop has reached the end
            cout << *it << endl;    //if so, print element without a ","
        }
        else {
            cout << *it << ", ";    //otherwise, print element with a ","
        }
    }

    //the same as the for loop for A
    for (auto it = B.begin(); it != B.end(); it++) {
        if (*it == B.back()) {
            cout << *it << endl;
        }
        else {
            cout << *it << ", ";
        }
    }

    cout << endl;

    //merge the lists into A and then sort it
    A.merge(B);
    A.sort();

    //print the new merged list
    for (int elemA : A) {
        cout << elemA << " ";
    }

    return 0;
}