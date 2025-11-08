#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int n, k;

int cur = 0;
string s;

void sol(int i, int v){
    if(i == n){
        if(cur == k){
            cout<<s<<'\n';
        }
        return;
    }
    if(cur > k) return;
    s += "0";
    sol(i+1,v);
    s.pop_back();
    cur += 1;
    s += "1";
    sol(i+1,v+1);
    cur -= 1;
    s.pop_back();
}

void mains(){
    cin>>k>>n;
    sol(0,0);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 