#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    //define a string to take the inputs
    string input_number_list;
    getline(cin, input_number_list);

    //define a vector array and store inputs
    vector<int> arr;
    stringstream ss(input_number_list);
    int element;

    
    while (ss >> element) {
        arr.push_back(element);
    }

    int length_of_array = (int) arr.size();

    //using optimized bubble sort to sort the given data
    int i=0;

    while(i < length_of_array - 1) {
        int j=0;
        while( j < length_of_array - i - 1){
            if (arr[j] > arr[j + 1]) {
                int tempary_element = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempary_element;


            }
	        j++;
        }
	    i++;
    } 

    //displaying the sorted array of data
    for (int k = 0; k < length_of_array; k++) {
        cout << arr[k] << " ";
    }
}