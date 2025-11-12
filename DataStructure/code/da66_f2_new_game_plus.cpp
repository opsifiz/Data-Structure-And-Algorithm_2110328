#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 500, mod = 100000007;

int board[N+5][N+5], a[N+5][N+5];
int dp[N+5][N+5][3];

int n, m;

int modpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

void mains(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
        }
        if(board[i][1] == 0){
            dp[i][1][0] = 1;
            dp[i][1][1] = 1;
            dp[i][1][2] = 1;
        }
    }

    for(int j=2;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(board[i][j] == 0){
                if(i>1){
                    dp[i][j][0] = (dp[i-1][j-1][1]+dp[i-1][j-1][2])%mod;
                }
                dp[i][j][1] = (dp[i][j-1][0]+dp[i][j-1][2])%mod;
                if(i<n){
                    dp[i][j][2] = (dp[i+1][j-1][0]+dp[i+1][j-1][1])%mod;
                }
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //             cout<<"("<<sol(i,j,0)<<", "<<sol(i,j,1)<<", "<<sol(i,j,2)<<") ";   
    //             // cout<<"("<<dp[i][j][0]<<", "<<dp[i][j][1]<<", "<<dp[i][j][2]<<") ";   
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';

    int sum = 0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<3;k++){
            sum = (sum+dp[i][m][k])%mod;
        }
    }
    cout<<(sum*modpow(2,mod-2))%mod;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 