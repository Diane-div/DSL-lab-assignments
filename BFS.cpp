#include <iostream>
#include <stdlib.h>
using namespace std;

int cost[10][10], n, qu[10], front, rear, v, visit[10], visited[10];
int stk[10], top, visit1[10], visited1[10];

void BFS(int startVertex) {
    for (int i = 0; i < n; i++) {
        visited1[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        visit1[i] = 0;
    }

    cout << startVertex + 1 << " ";
    visited[startVertex] = 1;
    qu[rear++] = startVertex;
    front = 0;
    
    while (front != rear) {
        v = qu[front++];
        for (int j = 0; j < n; j++) {
            if (cost[v][j] != 0 && visited[j] == 0) {
                visited[j] = 1;
                qu[rear++] = j;
                cout << j + 1 << " ";
            }
        }
    }
}

void DFS(int startVertex) {
    for (int i = 0; i < n; i++) {
        visited1[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        visit1[i] = 0;
    }

    cout << startVertex + 1 << " ";
    visited1[startVertex] = 1;
    stk[top++] = startVertex;
    
    while (top > 0) {
        v = stk[--top];
        for (int j = n - 1; j >= 0; j--) {
            if (cost[v][j] != 0 && visited1[j] == 0) {
                visited1[j] = 1;
                stk[top++] = j;
                cout << j + 1 << " ";
            }
        }
    }
}

void DFSRecursive(int vertex) {
    visited1[vertex] = 1;
    cout << vertex + 1 << " ";
    
    for (int j = 0; j < n; j++) {
        if (cost[vertex][j] != 0 && visited1[j] == 0) {
            DFSRecursive(j);
        }
    }
}

void BFSRecursiveHelper(int vertex) {
    visited[vertex] = 1; 
    cout << vertex + 1 << " ";
    

    for (int j = 0; j < n; j++) {
        if (cost[vertex][j] != 0 && visited[j] == 0) { 
            cout << "Going to vertex " << j + 1 << endl;  
            BFSRecursiveHelper(j); 
        }
    }
}

void BFSRecursive(int startVertex) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0; 
    }

    cout << "Starting BFS Recursive from vertex " << startVertex + 1 << endl;
    BFSRecursiveHelper(startVertex);  
}


int main() {
    int m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    
    cout << "\nEDGES:\n";
    for (int k = 1; k <= m; k++) {
        int i, j;
        cin >> i >> j;
        cost[i - 1][j - 1] = 1;
        cost[j - 1][i - 1] = 1;
    }

    cout << "The adjacency matrix of the graph is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
    
    cout << "Enter initial vertex for BFS (1 to " << n << "): ";
    cin >> v;
    v--;
    cout << "The BFS of the Graph is\n";
    BFS(v);
    
    cout << endl << "Enter initial vertex for DFS (1 to " << n << "): ";
    cin >> v;
    v--;
    cout << "The DFS of the Graph is\n";
    DFS(v);

    cout << endl << "Enter initial vertex for Recursive DFS (1 to " << n << "): ";
    cin >> v;
    v--;
    cout << "The Recursive DFS of the Graph is\n";
    fill(begin(visited1), end(visited1), 0);
    DFSRecursive(v);

    cout << endl << "Enter initial vertex for Recursive BFS (1 to " << n << "): ";
    cin >> v;
    v--;
    cout << "The Recursive BFS of the Graph is\n";
    BFSRecursive(v);

    return 0;
}
