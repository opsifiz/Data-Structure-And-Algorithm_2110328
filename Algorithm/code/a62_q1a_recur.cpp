#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 1000;

int board[1<<8+1][1<<8+1];

void sol(int i, int j, int k, int l, int a, int b){
    if(i == k && j == l){
        board[i][j] = b;
        return;
    }
    int ni = (i+k)/2, nj = (j+l)/2;
    sol(i,j,ni,nj,a-1,b);
    sol(i,nj+1,ni,l,a-1,b-1);
    sol(ni+1,j,k,nj,a-1,b+1);
    sol(ni+1,nj+1,k,l,a-1,b);
}

void mains(){
    int a, b; cin>>a>>b;
    sol(0,0,(1<<a)-1,(1<<a)-1,a,b);
    for(int i=0;i<1<<a;i++){
        for(int j=0;j<1<<a;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 