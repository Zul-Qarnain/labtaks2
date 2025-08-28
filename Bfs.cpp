#include <iostream>
using namespace std;

#define N 6   // number of nodes

int adj[N][N];   // adjacency matrix
bool visited[N]; // visited array

// -------- BFS function --------
void bfs(int start) {
    int q[100], front = 0, rear = 0;

    visited[start] = true;
    q[rear++] = start;

    cout << "BFS Traversal: ";
    while (front < rear) {
        int u = q[front++];
        cout << u << " ";

        for (int v = 0; v < N; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                q[rear++] = v;
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

    // Run BFS from node 0
    bfs(0);

    return 0;
}