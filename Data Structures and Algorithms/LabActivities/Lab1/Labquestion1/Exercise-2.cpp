#include <iostream>
using namespace std;

int main() {
    int number_1,number_2;//define two integers
    
    //input two integers
    cin>>number_1;
    cin>>number_2;
    
    //run a for loop to give the asked output
    for(int number=number_1;number<=number_2;number++){
        if(number==1){
            cout<<"one"<<endl;
        }
        else if(number==2){
            cout<<"two"<<endl;
        }
        else if(number==3){
            cout<<"three"<<endl;
        }
        else if(number==4){
            cout<<"four"<<endl;
        }
        else if(number==5){
            cout<<"five"<<endl;
        }
        else if(number==6){
            cout<<"six"<<endl;
        }
        else if(number==7){
            cout<<"seven"<<endl;
        }
        else if(number==8){
            cout<<"eight"<<endl;
        }
        else if(number==9){
            cout<<"nine"<<endl;
        }
        
        //This part is added to display that the value what are larget than 9 are even or odd
        else{
            if(number%2==0){
                cout<<"even"<<endl;
            }
            else{
                cout<<"odd"<<endl;
            }
        }
    }
}   