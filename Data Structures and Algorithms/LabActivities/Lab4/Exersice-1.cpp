#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void quickSort(vector<int> arr) {
    
    //define an integer to keep the length of the given array
    int length=(int)arr.size();
    
    //define a vector array to keep the outputs
    vector<int> result_arr;
    
    //define and initialize the integer pivot
    int pivot=arr[0];
    
    //define two vector arrays to keep the right and left outputs
    vector<int>right_arr;
    vector<int>left_arr;
    
    //seperate values to the given order
    for(int i=1;i<length;i++){
        if(arr[i]>pivot){
            right_arr.push_back(arr[i]);
        }else{
            left_arr.push_back(arr[i]);
        }
    }
    
    //enter the output values to relevent vector arrays
    for(int i=0;i<(int)left_arr.size();i++){
        result_arr.push_back(left_arr[i]);
    }
    result_arr.push_back(pivot);
    for(int i=0;i<(int)right_arr.size();i++){
        result_arr.push_back(right_arr[i]);
    }
    
    //display the output array
    for(int i=0;i<length;i++){
		cout<<result_arr[i]<<" ";
	}
}

int main() {
    
    //define a string to take the size
    string arr_size;
    getline(cin,arr_size);

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
	quickSort(arr);
}

