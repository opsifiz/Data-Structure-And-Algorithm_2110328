#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];

void dfs(int u){
    if(vis[u]) return;
    vis[u] = 1;
    for(int v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void mains(){
    int q; cin>>q;
    map<int,int> mp;
    while(q--){
        int cmd;
        int l, r;
        cin>>cmd;
        if(cmd == 1){
            cin>>l>>r;
            auto it = mp.lower_bound(l);
            if(it != mp.begin()){
                it--;
                if(it->second+1 < l) it++; //ไม่เอาตัวก่อนหน้า
            }

            int newL = l;
            int newR = r;

            vector<int> toErase;

            while(it != mp.end() && it->first <= newR+1){
                if(it->second+1 < newL){
                    it++;
                    continue;
                }
                newL = min(newL,it->first);
                newR = max(newR,it->second);
                toErase.push_back(it->first);
                it++;
            }
            for(int key : toErase){
                mp.erase(key);
            }
            mp[newL] = newR;

        }else if(cmd == 2){
            cout<<mp.size()<<'\n';
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 