#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > Vec;
vector<bool> visited;

void bfs(int node) {
    queue<int> lst;
    lst.push(node);
    visited[node] = true;
    while (!lst.empty()) {
        node = lst.front();
        lst.pop();
        cout << node << " ";
        for (int i=0; i<Vec[node].size(); i++) {
            if (!visited[Vec[node][i]]) {
                lst.push(Vec[node][i]);
                visited[Vec[node][i]] = true;
            }
        }
    }
}

int main() {
    int N, u, v;
    cin >> N;

    Vec.resize(N+1);
    visited.resize(N+1);

    while (N--) {
        cin >> u >> v;
        Vec[u].push_back(v);
        Vec[v].push_back(u);
    }

    bfs(1);
    return 0;
}