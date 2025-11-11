#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> zuma;
    int n, pos, val; cin>>n>>pos>>val;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        zuma.push_back(x);
    }

    auto p = zuma.begin();
    advance(p,pos);
    zuma.insert(p,val);
    p = prev(p);

    bool bomb = 1;
    while(bomb){
        bomb = 0;
        int cnt = 1;
        int target = *p;
        auto l = p;
        auto r = p;
        
        if(l != zuma.begin()){
            while(l != zuma.begin() && *prev(l) == target){
                cnt++;
                l = prev(l);
            }
        }

        if(next(r) != zuma.end()){
            while(next(r) != zuma.end() && *next(r) == target){
                cnt++;
                r= next(r);
            }
        }
        
        if(cnt >= 3){
            auto after_r = next(r);
            bomb = 1;
            zuma.erase(l,after_r);
            if(after_r != zuma.begin()){
                p = prev(after_r);
            }else{
                p = after_r;
            }
        }
    }
    
    for(int x : zuma) cout<<x<<" ";
}