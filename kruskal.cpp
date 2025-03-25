#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int src, dest, weight;
};

int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);
    
    if (xroot != yroot) {
        parent[xroot] = yroot;
    }
}


void kruskal(int n, vector<Edge>& edges) {
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    
    cout << "Edges in the Minimum Spanning Tree (MST):" << endl;
    int mstWeight = 0;
    
    for (auto edge : edges) {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);

        if (x != y) {
            cout << edge.src + 1 << " - " << edge.dest + 1 << " : " << edge.weight << endl;
            mstWeight += edge.weight;
            unionSets(parent, x, y);
        }
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    
    vector<Edge> edges(m);
    
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        edges[i].src--;
        edges[i].dest--; 
    
    kruskal(n, edges);
    
    return 0;
}
}
