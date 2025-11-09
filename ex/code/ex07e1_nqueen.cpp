#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 20;

map<int,int> da, db;
int row[N+5], col[N+5];
int cnt = 0, n;

vector<pii> memo;

void sol(int i){
    if(i == n+1){
        // for(auto [x, y] : memo){
        //     cout<<x<<' '<<y<<'\n';
        // }
        // cout<<'\n';
        cnt++;
        return;
    }
    // for(auto [x, y] : memo){
    //     cout<<x<<' '<<y<<'\n';
    // }
    // cout<<'\n';
    for(int j=1;j<=n;j++){
        if(col[j]==0 && da[i-j]==0 && db[i+j]==0){
            col[j] = 1;
            // memo.push_back({i,j});
            da[i-j] = 1;
            db[i+j] = 1;

            sol(i+1);
            
            col[j] = 0;
            // memo.pop_back();
            da[i-j] = 0;
            db[i+j] = 0;
        }
    }
}

void mains(){
    cin>>n;
    sol(1);
    cout<<cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 