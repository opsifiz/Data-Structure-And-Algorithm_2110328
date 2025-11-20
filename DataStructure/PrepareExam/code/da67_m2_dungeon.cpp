#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5, D = 2e5, T = 1e9, Z = 1000;

priority_queue<int> pq[Z+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d, t, z;
    int ans = 0;
    cin>>n>>d>>t>>z;
    while(d--){
        int x, y;
        cin>>x>>y;
        pq[y].push(-x);
    }
    while(n--){
        int sz; cin>>sz;
        vector<int> v(sz);
        for(int &x : v) cin>>x;
        int curT = 0;
        bool can = 1;
        for(int &x : v){
            if(pq[x].empty()){
                can = 0;
                break;
            }
            curT += -pq[x].top(); pq[x].pop();
            if(curT > t){
                can = 0;
                break;
            }
        }
        if(can){
            t -= curT;
            ans++;
        }else{
            break;
        }
    }
    cout<<ans;
}