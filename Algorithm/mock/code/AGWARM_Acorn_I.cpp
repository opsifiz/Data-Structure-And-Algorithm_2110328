#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2000, mod = 1e9+7;

int qs[N+5][N+5];
int cnr[N+5][N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    cnr[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char temp; cin>>temp;
            qs[i][j] = (qs[i-1][j]+qs[i][j-1])%mod-qs[i-1][j-1]+(temp=='a');
            while(qs[i][j] < 0) qs[i][j] += mod;
        }
    }

    for(int i=0;i<=N;i++){
        cnr[i][0] = cnr[i][i] = 1;
        // cout<<1<<' ';
        for(int j=1;j<i;j++){
            cnr[i][j] = (cnr[i-1][j]+cnr[i-1][j-1])%mod;
            // cout<<cnr[i][j]<<' ';
        }
        // if(i>0) cout<<1;
        // cout<<'\n';
    }

    int q; cin>>q;
    while(q--){
        int a, b, x, y, r;
        cin>>a>>b>>x>>y>>r;
        int acorn = qs[x][y]-qs[x][b-1]-qs[a-1][y]+qs[a-1][b-1];
        if(acorn < r){
            cout<<"-1\n";
        }else{
            cout<<cnr[acorn][r]<<'\n';
        }
    }
}