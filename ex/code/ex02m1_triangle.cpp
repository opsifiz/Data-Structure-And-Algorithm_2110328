#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int dp[N+5][N+5];
int board[N+5][N+5];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>board[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            dp[i][j] = board[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    cout<<dp[1][1];
}