#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 20;

map<int,int> mp;
bool vis[N+5];
int a[N+5];

int n;

void sol(int idx){
    if(idx == n){
        for(int i=0;i<n;i++) cout<<a[i]<<' '; cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(mp.find(i)==mp.end() || vis[mp[i]]){
                vis[i] = 1;
                a[idx] = i;
                sol(idx+1);
                vis[i] = 0;
            }
        }
    }
}

void mains(){
    int q;
    cin>>n>>q;
    vector<int> v(n);
    vector<pii> p;
    for(int i=0;i<n;i++) v[i]=i;
    while(q--){
        int a, b; cin>>a>>b;
        mp[b] = a;
    }
    sol(0);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 