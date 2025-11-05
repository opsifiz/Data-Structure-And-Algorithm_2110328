#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
map<string,int> mp;
vector<int> vec;

void mains(){
    int n, k;
    string s;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s;
        mp[s]++;
    }

    for(auto x : mp){
        vec.push_back(x.second);
    }
    
    sort(vec.begin(),vec.end(),greater<int>());

    cout<<vec[min((int)vec.size()-1,k-1)];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 