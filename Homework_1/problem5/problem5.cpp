#include<iostream>
#include<string>
#include<iterator>
#include<vector>

using namespace std;

int main () {
    string input = "temp";          //input variable with temporary value
    vector<string> words;           //vector that will hold the inputted words

    while (input != "END") {        //while loop that ends when input is "END"
        getline(cin, input);        //use getline to include spaces in input
        if (input != "END") {
            words.push_back(input);
        }
    }

    if (words.size() >= 5) {        //check if there are 5 or more elements
        //if so, swap elements in positon 2 and 5
        string temp = words[2]; 
        words[2] = words[5];
        words[5] = temp;
    }

    words[words.size()-1] = "???";  //change the last element to "???"

    //for loop that uses index to print
    for (unsigned int i = 0; i < words.size(); i++) {
        if (i == words.size()-1) {  //check if loop reached the last word
            cout << words[i] << endl;    //if so, print the word without a ","
        }
        else {
            cout << words[i] << ", ";    //otherwise, print it with a ","
        }
    }

    vector<string>::iterator iwords;    //declaring an iterator

    //for loop that uses an iterator to print
    for (iwords = words.begin(); iwords < words.end(); iwords++) {
        if (iwords == words.end()-1) {  //check if loop reached the last word
            cout << *iwords << endl;    //if so, print the word without a ","
        }
        else {
            cout << *iwords << "; ";    //otherwise, print it with a ","
        }
    }

    vector<string>::reverse_iterator iwords2;    //declaring an iterator

    //for loop that uses a reverse iterator to print
    for (iwords2 = words.rbegin(); iwords2 != words.rend(); iwords2++) {
        cout << *iwords2 << " ";
    }

    return 0;
}