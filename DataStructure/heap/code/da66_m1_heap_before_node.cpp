#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin>>n>>x;
    vector<int> s;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == x) continue;
        s.push_back(u);
        if(2*u+1 < n) q.push(2*u+1);
        if(2*u+2 < n) q.push(2*u+2);
        
    }
    cout<<s.size()<<'\n';
    for(int y : s) cout<<y<<' ';
}