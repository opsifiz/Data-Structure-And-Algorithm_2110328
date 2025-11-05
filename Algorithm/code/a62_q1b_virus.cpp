#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];
int k;

bool sol(string s){
    int N = s.size();
    if(N == 2) return s == "01";
    int n = N/2;
    string t = s.substr(n);
    string a = s.substr(0,n);
    string b = a;
    reverse(b.begin(),b.end());
    return (sol(a)||sol(b))&&sol(t);
}

void mains(){
    string s;
    for(int i=0;i<(1<<k);i++){
        char c; cin>>c;
        s += c;
    }
    // cout<<s<<" : ";
    
    cout<<(sol(s)?"yes\n":"no\n");
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    cin>>tc>>k;
    while(tc--){
        mains();
    }
} 