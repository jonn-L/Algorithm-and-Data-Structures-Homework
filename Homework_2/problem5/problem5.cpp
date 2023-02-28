#include <iostream>
#include <set>
#include <iterator>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
using a set container is the best choice here due to two reasons:
(1) - it does not allow the insertion of duplicate elements
(2) - it auto sorts its elements into ascending order
*/

int main () {
    set<int> lotto;     //initalize the set

    srand(time(0));
    while (lotto.size() < 6) {      //check if the set has 6 elements
        int num = rand() % 49 + 1;  //generate random number
        lotto.insert(num);          //insert it
    }

    //iterate using an iterator
    for (auto it = lotto.begin(); it != lotto.end(); it++) {
        cout << *it << " ";     //print the numbers
    }

    return 0;
}