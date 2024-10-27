#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    
    // Create adjacency list representation of the graph
    vector<vector<int>> adjacencyList(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); 
    }

    // define int vector array to store distances from start node
    vector<int> distances(n + 1, -1);
    // define boolean vector array to track visited nodes
    vector<bool> visited(n + 1, false);

    // define an integer queue for BFS
    queue<int> q;
    
    // Enqueue the start node and mark it as visited
    q.push(s);
    visited[s] = true;
    distances[s] = 0;

    // BFS traversal
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Explore all adjacent vertices of u
        for (int v : adjacencyList[u]) {
            // If vertex v is not visited yet
            if (!visited[v]) {
                // Mark v as visited
                visited[v] = true;
                // Update distance to v
                distances[v] = distances[u] + 6; // Assuming each edge weighs 6 units
                // Enqueue v for further exploration
                q.push(v);
            }
        }
    }

    //define an integer vector to keep the outputs
    vector<int> result;
    
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            result.push_back(distances[i]);
        }
    }
    return result;
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

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
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
