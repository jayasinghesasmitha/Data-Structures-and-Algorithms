#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */



//function with four arguments.number is used to get the integer count from 1,X means the digit,N means the power of the digit,answer is used to keep the powersum
int powerSum(int number,int X, int N,int& answer) 
{
    
    //if digit is zero then the answer is returned
    if(X == 0)
    {
        answer++;
        return answer ;
    }
    
    //if the power of the number is larger than digit then the answer is returned
    if(pow(number, N) > X)
        return answer;
    
    //recurrsion part
    powerSum(number + 1, X, N, answer);
    powerSum(number + 1, X - pow(number, N), N, answer);
    
    return answer;
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));
    
    //define an integer value answer to keep the powerSum
    int answer=0;

    //call the function 
    int result = powerSum(1,X, N,answer);

    cout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
