#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

map<int,int> p;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int u, v;
        cin>>u>>v;
        p[v] = u;
    }
    while(m--){
        int a, b;
        cin>>a>>b;
        bool f = a!=b;
        if(p.find(a) == p.end()) f = 0;
        else{
            a = p[a];
            if(p.find(a) == p.end()) f = 0;
            else{
                a = p[a];
            }
        }

        if(p.find(b) == p.end()) f = 0;
        else{
            b = p[b];
            if(p.find(b) == p.end()) f = 0;
            else{
                b = p[b];
            }
        }
        cout<<(f&&a==b?"YES\n":"NO\n");
    }
}