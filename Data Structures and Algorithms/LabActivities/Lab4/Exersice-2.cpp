#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
    
    //define a map to keep the outputs
    map<int, int> m;
    
    //define an integer to keep the length
    int length=(int)arr.size();
    
    vector<int> sorted_arr= arr;
    vector<int> arr1=arr;
    
    int no_of_swaps_1=0,no_of_swaps_2=0;
    
    //sort the given array
    for (int i = 1; i < length; ++i) {
        int key = sorted_arr[i];
        int j = i - 1;
        while (j >= 0 && sorted_arr[j] > key) {
            sorted_arr[j + 1] = sorted_arr[j];
            j--;
        }
        sorted_arr[j + 1] = key;
    }
    
    //finding the minimum swaps
    for(int i=0;i<length;i++)
        m[arr[i]]=i;
    for(int i=0;i<length;i++)
    {
        if(arr[i]!=sorted_arr[i])
        {
            no_of_swaps_1++;
            m[arr[i]]=m[sorted_arr[i]];
            swap(arr[i],arr[m[sorted_arr[i]]]);
        }
    }
    
    reverse(arr1.begin(), arr1.end());

    for(int i=0;i<length;i++)
        m[arr1[i]]=i;
    for(int i=0;i<length;i++)
    {
        if(arr1[i]!=sorted_arr[i])
        {
            no_of_swaps_2++;
            m[arr1[i]]=m[sorted_arr[i]];
            swap(arr1[i],arr1[m[sorted_arr[i]]]);
        }
    }
    
    return min(no_of_swaps_1, no_of_swaps_2);
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

    int result = lilysHomework(arr);

    cout << result << "\n";

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
