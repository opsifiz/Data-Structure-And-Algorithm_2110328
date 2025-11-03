#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5];
vector<int> vec;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=1;i<=n&&cin>>a[i];i++){
        vec.push_back(a[i]);
    }
    sort(vec.begin(),vec.end());
    while(m--){
        int p; cin>>p;
        // cout<<p-k<<' '<<p+k<<'\n';
        // cout<<upper_bound(vec.begin(),vec.end(),p+k)-vec.begin()<<' '<<lower_bound(vec.begin(),vec.end(),p-k)-vec.begin()<<'\n';
        // cout<<vec[upper_bound(vec.begin(),vec.end(),p+k)-vec.begin()]<<' '<<vec[lower_bound(vec.begin(),vec.end(),p-k)-vec.begin()]<<'\n';
        cout<<upper_bound(vec.begin(),vec.end(),p+k)-lower_bound(vec.begin(),vec.end(),p-k)<<' ';
    }
}