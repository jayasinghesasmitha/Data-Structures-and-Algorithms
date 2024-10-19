#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    string input_number_list;
    getline(cin, input_number_list);

    vector<int> arr;
    stringstream ss(input_number_list);
    int element;

    
    while (ss >> element) {
        arr.push_back(element);
    }

    int length_of_array = (int) arr.size();
    int i=1;


    while(i<length_of_array){
        int key_element = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key_element) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key_element;
	    i++;
    }
    
    
    for (int k = 0; k < length_of_array; k++) {
        cout << arr[k] << " ";
    }
}