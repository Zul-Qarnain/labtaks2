#include <iostream>
using namespace std;

#define N 6   // number of nodes

int adj[N][N];   // adjacency matrix
bool visited[N]; // visited array

// -------- DFS function --------
void dfs(int start) {
    int st[100], top = -1;

    st[++top] = start;

    cout << "DFS Traversal: ";
    while (top >= 0) {
        int u = st[top--];
        if (!visited[u]) {
            visited[u] = true;
            cout << u << " ";

            for (int v = N - 1; v >= 0; v--) {
                if (adj[u][v] && !visited[v]) {
                    st[++top] = v;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    // Initialize adjacency matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            adj[i][j] = 0;

    // Add edges
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][5] = adj[5][2] = 1;

    // Run DFS from node 0
    dfs(0);

    return 0;
}