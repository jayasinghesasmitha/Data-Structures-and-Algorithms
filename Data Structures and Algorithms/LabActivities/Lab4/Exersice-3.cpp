#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> closestNumbers(vector<int> arr) {
    
    //use inbuild function to sort the given vector array
    sort(arr.begin(), arr.end());
    
    //define an integer to keep the length of the given vectoe array 
    int length=(int)arr.size();
    
    //if array length is less than 2 return the empty array
     if (length < 2) {
         return {};
    }
    
    //define a vector array to keep the outputs
    vector<int> result_arr;
    
    //define the minimum integer and give it the highest value that integer can keep.
    int minimum_difference=(int)pow((double)2,(double)32);
    
    for(int i = 1; i < length; i++){
        
        //get the minimum difference to calculate.And keep the current inimum difference
        if(arr[i] - arr[i-1] < minimum_difference){
            minimum_difference = arr[i] - arr[i-1];
            result_arr = {arr[i-1], arr[i]};
        }
        else if(arr[i] - arr[i-1] == minimum_difference){
            result_arr.insert(result_arr.end(), {arr[i-1], arr[i]});
        }
    }
    //return the result array
    return result_arr;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
