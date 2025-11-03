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
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i != a[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}