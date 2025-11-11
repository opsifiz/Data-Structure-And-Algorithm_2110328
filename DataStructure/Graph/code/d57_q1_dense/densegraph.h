#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    vector<vector<int>> g;
    DenseGraph() {
        // Your code here
        n = 3;
        g = vector<vector<int>>(n,vector<int>(n,0));
    }
    
    DenseGraph(int n_in) {
        // Your code here
        n = n_in;
        g = vector<vector<int>>(n,vector<int>(n,0));
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        g = G.g;
        n = G.n;
    }

    void AddEdge(int a, int b) {
        // Your code here
        g[a][b] = 1;
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        g[a][b] = 0;
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return g[a][b];
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph ng;
        ng.g = g;
        ng.n = n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ng.g[j][i] = g[i][j];
            }
        }
        return ng;
    }

protected:
    int n;
    // Your code here
};
#endif // __DENSE_GRAPH_H__
