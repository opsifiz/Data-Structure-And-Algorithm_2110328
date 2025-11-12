#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;

const int N = 2e5;

int a[N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, mn = inf;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mn = min(mn,a[i]);
    }
    while(q--){
        int l = 1, r = inf;
        int idx; cin>>idx;
        if(idx <= n){
            cout<<"0\n";
            continue;
        }
        while(l<r){
            int mid = l+(r-l)/2;
            int sum = 0;
            for(int i=1;i<=n;i++){
                sum += 1+mid/a[i];
            }
            if(sum >= idx) r = mid;
            else l = mid+1;
        }
        cout<<l<<'\n';
    }
}