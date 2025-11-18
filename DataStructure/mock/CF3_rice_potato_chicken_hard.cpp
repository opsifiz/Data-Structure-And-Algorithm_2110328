#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define inf 1e18
using namespace std;

deque<pii> dq;
set<pii> superdq, toDel;

int l =  1, r = -1;
int df = 0;

int32_t main(){
    int n, m, query, val;
    cin>>n>>query;
    for(int i=1;i<=n;i++){
        cin>>val;
        dq.push_back({val,i});
        superdq.insert({val,i});
    }
    r = n;
    while(query--){
        int cmd; cin>>cmd;
        if(cmd == 1){
            cin>>val;
            dq.push_back({val-df,++r});
            superdq.insert({val-df,r});
        }else if(cmd == 2){
            while(toDel.count(dq.front())){
                toDel.erase(dq.front());
                dq.pop_front();
                l++;
            }
            superdq.erase(dq.front());
            dq.pop_front();
            l++;
        }else if(cmd == 3){
            while(toDel.count(dq.back())){
                toDel.erase(dq.back());
                dq.pop_back();
                r--;
            }
            superdq.erase(dq.back());
            dq.pop_back();
            r--;
        }else if(cmd == 4){
            cin>>val;
            df += val;
        }else if(cmd == 5){
            cin>>val;
            auto cur = superdq.begin();
            while(cur != superdq.end()){
                if(cur->first+df >= val) break;
                toDel.insert(*cur);
                cur = superdq.erase(cur);
            }

            // for(pii x : toDel){
            //     cout<<x.first<<' '<<x.second<<'\n';
            // }
        }else if(cmd == 6){
            cin>>m;
            int sum = 0, tmp = m;
            while(tmp--){
                while(toDel.count(dq.back())){
                    toDel.erase(dq.back());
                    dq.pop_back();
                }
                sum += dq.back().first+df;
                superdq.erase(dq.back());
                dq.pop_back();
                r--;
            }
            dq.push_front({sum-df,--l});
            superdq.insert({sum-df,l});
        }

        // for(pii x : dq){
        //     if(toDel.count(x)) continue;
        //     cout<<x.first+df<<' ';
        // }
        // cout<<'\n';
    }
    int cnt = 0, sum = 0;
    for(pii &x : dq){
        if(toDel.count(x)) continue;
        sum += x.first+df;
        cnt++;
    }
    cout<<cnt<<' '<<sum;
}