#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main () {
    map<string, string> names_birthdays;    //intialize map

    //open the file for reading
    ifstream file;
    file.open("names_birthdays.txt");
    if (!file.is_open()) {
        exit(0);
    }

    string input;
    while (getline(file, input)) {      //read file line by line until eof
        //get "name" by using substr
        string name = input.substr(0, input.find(" || "));
        input.erase(0, name.size()+4);  //delete "name" from "input"
        string birthday = input;        //get "birthday"

        names_birthdays[name] = birthday;   //add them to the map
    }
    file.close();

    cout << "Enter 'exit' to break loop" << endl;
    while (true) {
        string findName;

        getline(cin, findName);         //ask for name
        if (findName == "exit") break;  //break loop if name is "exit"

        //determine if name is in the map
        if (names_birthdays.find(findName) == names_birthdays.end()) {
            cout << "Name not found!" << endl;      //if not, print message
        }
        else {
            cout << names_birthdays[findName] << endl;  //if yes, give birthday
        }
    }

    return 0;
}