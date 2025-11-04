#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5];
bool vis[N+5];
vector<int> g[N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        int val; cin>>val;
        if(val < a[1]) cout<<"-1\n";
        else if(val >= a[n]) cout<<a[n]<<'\n';
        else{
            int l = 1, r = n;
            while(l<r){
                int mid = l+(r-l)/2;
                if(val <= a[mid]) r = mid;
                else l = mid+1;
            }
            int idx = l;
            if(val == a[idx]) cout<<a[idx]<<'\n';
            else cout<<a[idx-1]<<'\n';
        }
    }
}