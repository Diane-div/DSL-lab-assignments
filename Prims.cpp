#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define MAX 100

int findMinKey(int key[], bool mstSet[], int n){
    int min = INT_MAX;
    int minIndex = -1;  

    for(int v = 0; v < n; v++){
        if(!mstSet[v] && key[v] < min){ 
            min = key[v]; 
            minIndex = v; 
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[MAX][MAX], int n){
    int totalCost = 0;
    cout << "Edge \tWeight\n";
    for(int i = 1; i < n; i++){
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
        totalCost += graph[i][parent[i]];
    }
    cout << "Total Minimum Cost: " << totalCost << endl;
}

void primMST(int graph[MAX][MAX], int n){
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for(int i = 0; i < n; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < n - 1; count++){
        int u = findMinKey(key, mstSet, n);  
        mstSet[u] = true;  

        for(int v = 0; v < n; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, n);
}

int main(){
    int n;
    int graph[MAX][MAX];

    cout << "Enter number of offices [nodes]: " << endl;
    cin >> n;

    cout << "Enter the cost adjacency matrix (enter 0 if no direction connection): " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    primMST(graph, n); 
    return 0;
}
