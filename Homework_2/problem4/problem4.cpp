#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main () {
    vector<int> v;                  //initalize the integer vector
    for (int i = 1; i < 31; i++) {  //loop through 1 to 30
        v.push_back(i);             //add them to the vector
    }
    v.push_back(5);     //also push back 5

    reverse(v.begin(), v.end());    //reverse the vector 

    for (auto it = v.begin(); it != v.end(); it++) {    //iterate the vector
        cout << *it << " ";     //print each element with a space after
    }
    cout << endl;

    replace(v.begin(), v.end(), 5, 129);    //change all "5" entries to "129"

    //print out the content of the vector to stdout again
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}