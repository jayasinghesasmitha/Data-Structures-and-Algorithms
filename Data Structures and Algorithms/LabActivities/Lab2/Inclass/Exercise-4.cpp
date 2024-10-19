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
    
    //using selection sort to sort the given data
    int i=0;

    while(i < length_of_array - 1){
        int minimum_index = i;
	int j=i+1;
        while(j < length_of_array) {
            if (arr[j] < arr[minimum_index]) {
                minimum_index = j;
            }
	        j++;
        }
        int tempary_element = arr[i];
        arr[i] = arr[minimum_index];
        arr[minimum_index] = tempary_element;
	    i++;
    }

    //displaying the sorted array of data
    for (int k = 0; k < length_of_array; k++) {
        cout << arr[k] << " ";
    }
}