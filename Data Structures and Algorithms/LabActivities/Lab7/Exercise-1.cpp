#include <cmath>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    
    //declare int STDIN to take the value of no of operations
    int STDIN;
    cin >> STDIN;
    
    //clear the new line
    cin.ignore(); 

    //define an int variable to store the minimum value
    int minimum_value;
    
    //define a vector named heap to store the data
    vector<int> heap;

    //running the loop till satisfy the no of operations
    for (int i = 0; i < STDIN; i++) {
        
        //taking inputs
        string input_number_list;
        getline(cin, input_number_list);

        //define an array to store inputs
        vector<int> arr;
        stringstream ss(input_number_list);

        int element;

        while (ss >> element) {
            arr.push_back(element);
        }
        
        //if the command is 1 then add the next given value to the heap
        if(arr[0]==1){
           heap.push_back(arr[1]); 
        }
        
        //if the command is 2 then delete the next given value from the heap
        if(arr[0]==2){
           heap.erase(remove(heap.begin(), heap.end(), arr[1]), heap.end()); 
        }
        
        //if the command is 3 then display the minimum value of the heap
        if(arr[0]==3){
            
            //check whether the heap is empty or not
            if (!heap.empty()) {
                    
                    //assign the first number to the minimum value
                    minimum_value = heap[0];
                    
                    //running a loop to find the actual minimum value out of all elements
                    for (int k = 1; k <(int) heap.size(); k++) {
                        if (minimum_value > heap[k]) {
                            minimum_value = heap[k];
                        }
                    }
                    cout << minimum_value << endl;
                } 
        }
    }

    return 0;
}
