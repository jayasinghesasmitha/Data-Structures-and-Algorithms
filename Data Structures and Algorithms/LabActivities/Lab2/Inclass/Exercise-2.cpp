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

    //using bubble sort to sort the given data
    bool swapped=true;
    int arr_length = (int)arr.size();

    while(swapped){
        swapped = false;
	    int i=1;
        while(i<arr_length){
            if (arr[i - 1] > arr[i]) {
                int tempary_element = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = tempary_element;
                swapped = true;
            }
	        i++;
        }
    }
    
    //displaying the sorted array of data
    for (int k = 0; k < arr_length; k++) {
        cout << arr[k] << " ";
    } 
}

