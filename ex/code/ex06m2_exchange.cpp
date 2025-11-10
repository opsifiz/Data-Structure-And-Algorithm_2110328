#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 500;

double g[N+5][N+5];
double dis[N+5];

void mains(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    bool f = 0;
    for(int st=1;st<=n && !f;st++){
        for(int i=0;i<=n;i++) dis[i] = 0;
        dis[st] = 1;
        for(int i=1;i<=n;i++){
            bool upd = 0;
            for(int u=1;u<=n;u++){
                for(int v=1;v<=n;v++){
                    if(u == v) continue;
                    double w = g[u][v];
                    if(dis[u] != inf && dis[v] < dis[u]*w){
                        dis[v] = dis[u]*w;
                        upd = 1;
                        if(i == n){
                            f = 1;
                            break;
                        }
                    }
                }
                if(f){
                    break;
                }
            }
            if(f || !upd){
                break;
            }
        }
        if(f){
            break;
        }
    }
    cout<<(f?"YES\n":"NO\n");
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    cin>>tc;
    while(tc--){
        mains();
    }
} 