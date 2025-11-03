#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 100;

int memo[N+5][N+5];
bool vis[N+5][N+5];

int target_sum = 0;

int sol(int last, int sum){
    if(sum > target_sum) return 0;
    if(sum == target_sum) return 1;
    if(vis[last][sum]) return memo[last][sum];
    vis[last][sum] = 1;
    for(int cur=last;sum+cur<=target_sum;cur++){
        memo[last][sum] += sol(cur, sum+cur);
    }
    return memo[last][sum];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>target_sum;
    cout<<sol(1,0);
}