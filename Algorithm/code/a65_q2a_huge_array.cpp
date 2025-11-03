#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
vector<pii> vec;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin>>n>>q;
    vec.push_back({0,0});
    for(int i=1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    sort(vec.begin(), vec.end());
    for(int i=1;i<=n;i++){
        qs[i] = vec[i].second+qs[i-1];
    }
    while(q--){
        int idx; cin>>idx;
        int i = lower_bound(qs+1,qs+n+1,idx)-qs;
        cout<<vec[i].first<<'\n';
    }
}