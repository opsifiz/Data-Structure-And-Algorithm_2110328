#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5], p[N+5], d[N+5];
bool vis[N+5];
vector<int> g[N+5];
map<int,int> mp;

void mains(){
    int n, m, w;
    cin>>n>>w>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int available = -1;
    int i = 1, cnt = 0;
    while(i<=n){
        int newAvailable = a[i]+w+w;
        cnt++;
        // cout<<newAvailable<<'\n';
        while(i<=n && a[i]<=newAvailable) i++;
        available = newAvailable;
    }
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