#include<iostream>
#include<string>
using namespace std;

//A simple Complex class
class Complex {
	private:
		double re, imag;
	public:
        //Parametric constructor
		Complex(double re, double imag) {
			this->re = re;
			this->imag = imag;
		}

        //Overloading operator ==
        bool operator==(Complex &comp2) {
            if (this->re == comp2.re && this->imag == comp2.imag) {
                return true;
            }
            return false;
        }
};

//Template function to search the array for an element and return its index
template <class T>
int array_search(T arr[], int size, T elem) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return -1;
}

int main () {
    //Test using integer arrays
    int int_arr[] = {1,2,3};
    int int_2arr[] = {4,5,6};
    int number_to_find = 2;

    cout << "int_arr content: 1, 2, 3" << endl;
    cout << "int_2arr content: 4, 5, 6" << endl;

    cout << "Checking if 2 is in int_arr: ";
    cout << array_search(int_arr, 3, number_to_find) << endl;
    cout << "Checking if 2 is in int_2arr: ";
    cout << array_search(int_2arr, 3, number_to_find) << endl;

    //Test using string arrays
    string str_arr[] = {"one", "two", "three"};
    string str_2arr[] = {"four", "five", "six"};
    string word_to_find = "three";

    cout << "str_arr content: 'one', 'two', 'three'" << endl;
    cout << "str_2arr content: 'four', 'five', 'six'" << endl;

    cout << "Checking if 'three' is in str_arr: ";
    cout << array_search(str_arr, 3, word_to_find) << endl;
    cout << "Checking if 'three' is in str_2arr: ";
    cout << array_search(str_2arr, 3, word_to_find) << endl;

    //Test using Complex arrays
    Complex comp_arr[] = {Complex(1,1), Complex(2,2), Complex(3,3)};
    Complex comp_2arr[] = {Complex(4,4), Complex(5,5), Complex(6,6)};
    Complex comp_to_find(1,1);

    cout << "comp_arr content: '1+1i', '2+2i', '2+2i'" << endl;
    cout << "comp_2arr content: '4+4i', '5+5i', '6+6i'" << endl;

    cout << "Checking if '1+1i' is in comp_arr: ";
    cout << array_search(comp_arr, 3, comp_to_find) << endl;
    cout << "Checking if '1+1i' is in comp_2arr: ";
    cout << array_search(comp_2arr, 3, comp_to_find) << endl;

    return 0;
}