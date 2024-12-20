#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    
    //chacking that cost of building c_libs is smaller or equal to the cost of building c_road 
    if (c_lib <= c_road) {
        return n*c_lib;
    }

    //defining two vectors.
    //defining 2D integer vector to represent the graph where each node has a vector of its neighbors
    vector<vector<int>> adjacency_list(n + 1); 
    
    //defining boolean vector to mark whether a node has been visited during traversal.
    vector<bool> visited(n + 1, false); 

    long total_cost = 0;

    //defining a function to do the depth first searching
    function<long(int)> depth_first_search = [&](int node) {
        long connected_nodes = 1; 
        visited[node] = true;
        for (int neighbor : adjacency_list[node]) {
            if (!visited[neighbor]) {
                connected_nodes += depth_first_search(neighbor);
            }
        }
        return connected_nodes;
    };

    // this loop is used to add both directions of each road, as the graph is undirected
    for (const auto& road : cities) {
        adjacency_list[road[0]].push_back(road[1]);
        adjacency_list[road[1]].push_back(road[0]);
    }

    //this loop is used to iterate through all nodes
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            long connected_nodes = depth_first_search(i);
            total_cost += c_lib; 
            total_cost += c_road * (connected_nodes - 1); 
        }
    }
    return total_cost;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

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
