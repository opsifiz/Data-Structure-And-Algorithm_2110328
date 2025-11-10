#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sol(vector<vector<int>> &a, int n, int k){
    if(n == 0){
        return {{1,0},{0,1}};
    }
    vector<vector<int>> temp = sol(a,n/2,k);
    vector<vector<int>> t(2, vector<int>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int l=0;l<2;l++){
                t[i][j] += (temp[i][l]*temp[l][j])%k;
                t[i][j] %= k;
            }
        }
    }
    
    if(n&1){
        vector<vector<int>> b(2, vector<int>(2,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int l=0;l<2;l++){
                    b[i][j] += (t[i][l]*a[l][j])%k;
                    b[i][j] %= k;
                }
            }
        }
        t = b;
    }

    return t;
}

int main(){
    vector<vector<int>> a(2, vector<int>(2,0));
    int n, k;
    cin>>n>>k;
    for(int i=0;i<2;i++){
        vector<int> m;
        for(int j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> b = sol(a,n,k);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<b[i][j]<<' ';
        }
    }
}