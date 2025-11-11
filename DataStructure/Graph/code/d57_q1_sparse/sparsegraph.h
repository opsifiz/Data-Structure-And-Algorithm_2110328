#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include<vector>
#include<unordered_set>
using namespace std;

class SparseGraph{
public:
    vector<unordered_set<int>> edges;
    int n;
    SparseGraph() {
        // Your code here
        n = 3;
        edges.resize(n);
        for(int i=0;i<n;i++) edges[i].clear();
    }

    SparseGraph(int n_in) {
        // Your code here
        n = n_in;
        edges.resize(n);
        for(int i=0;i<n;i++) edges[i].clear();
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        edges = G.edges;
        n = G.n;

    }

    void AddEdge(int a, int b) {
        // Your code here
        edges[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code her
        edges[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return edges[a].count(b);

    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph T(n);
        for(int u=0;u<n;u++){
            for(int v : edges[u]){
                T.edges[v].insert(u);
            }
        }
        return T;
    }

protected:
    // Your code here
};
#endif // __SPARSE_GRAPH_H__

