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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(m--){
        int ans = -1;
        int val; cin>>val;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(a[mid] <= val) l = mid+1, ans = mid;
            else r = mid-1;
        }
        cout<<ans<<'\n';
        
    }
}