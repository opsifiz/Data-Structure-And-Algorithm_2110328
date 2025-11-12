#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

int a[N+5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    while(q--){
        int tar; cin>>tar;
        bool f = 0;
        int l=1, r=n;
        while(l<r){
            int cur = a[l]+a[r];
            if(cur == tar){ f=1; break;}
            else if(cur < tar) l++;
            else r--;
        }
        cout<<(f?"YES\n":"NO\n");
    }
}