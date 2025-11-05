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
    int n, m, st;
    cin>>n>>m>>st;
    qs[0] = st;
    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        mp[x] = y;
    }
    int add = st;
    for(int i=1;i<=1e5;i++){
        if(mp.find(i) != mp.end()) add = mp[i];
        qs[i] = qs[i-1]+add;
    }
    while(m--){
        int val, day;
        cin>>val>>day;
        int idx = -1;
        if(val <= qs[day]){
            idx = lower_bound(qs,qs+day+1,val)-qs;
        }else{
            idx = lower_bound(qs,qs+(int)1e5+1,qs[day]+val)-qs;
        }
        cout<<idx<<' ';
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