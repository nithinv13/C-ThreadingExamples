#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int> > Vec;
vector<bool> visited;

void dfs_r(int s) {
    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < Vec[s].size(); i++) {
        if (visited[Vec[s][i]] == false) {
            dfs_r(Vec[s][i]);
        }
    }
}

void dfs(const vector<vector<int> >& Vec, int s) {
    std::stack<int> Stk;
    Stk.push(s);
    visited[s] = true;
    while (!Stk.empty()) {
        int node = Stk.top();
        Stk.pop();
        cout << "Visited: " << node << " ";
        for (int i=0; i<Vec[node].size(); ++i) {
            if (!visited[Vec[node][i]]) {
                Stk.push(Vec[node][i]);
                visited[Vec[node][i]] = true;
            }
        }
    }
}

void initialize() {
    for (int i=0; i < visited.size(); ++i) {
        visited[i] = false;
    }
}

int main() {
    int nodes, edges, x, y;
    cin >> nodes;
    cin >> edges;
    Vec.resize(nodes+1);
    visited.resize(nodes+1);
    for (int i = 0; i < edges; ++i) {
        cin >> x >> y;
        Vec[x].push_back(y);
        Vec[y].push_back(x);
    }
    initialize();
    dfs(Vec, 1);
    return 0;
}