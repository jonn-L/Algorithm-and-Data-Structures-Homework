#include<iostream>
#include<string>
#include<iterator>
#include<vector>

using namespace std;

int main () {
    string input = "temp";  //string variable with a temporary value
    vector<string> words;   //vector that will hold the inputed words

    while(input != "END") {         //while loop that ends when input is "END"
        cin >> input;               //ask for input
        if (input != "END") {
            words.push_back(input); //add input to vector
        }
    }

    for (unsigned int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";                //using the index to print
    }
    cout << endl;

    vector<string>::iterator iwords;    //declaring an iterator

    //for loop that uses an iterator
    for (iwords = words.begin(); iwords < words.end(); iwords++) {
        if (iwords == words.end()-1) {  //check if loop reached the last word
            cout << *iwords << endl;    //if so, print the word without a ","
        }
        else {
            cout << *iwords << ", ";    //otherwise, print it with a ","
        }
    }

    return 0;
}