#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 20;

int t[N+5];
int p[N+5];
int h[N+5];

void mains(){
    int n, m, k, w;
    cin>>n>>m>>k>>w;
    for(int i=1;i<=m;i++) cin>>p[i];
    for(int i=1;i<=m;i++) cin>>h[i];
    for(int i=1;i<=k;i++) cin>>t[i];
    int sum = 0;
    for(int i=1;i<=m;i++) sum += h[i];
    for(int j=1;j<=k;j++){
        int cnt = 0;
        for(int i=1;i<=m;i++){
            if(h[i] > 0 && t[j]-w <= p[i] && p[i] <= t[j]+w){
                h[i] -= 1;
                sum -= 1;
                cnt++;
                break;
            }
        }
    }
    cout<<sum;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 