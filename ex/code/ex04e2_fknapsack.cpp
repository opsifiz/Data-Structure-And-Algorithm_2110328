#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
double w[N+5], v[N+5];

void mains(){
    priority_queue<pair<double,int>> pq;
    int n; double cap;
    cin>>cap>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++){
        cin>>w[i];
        pq.push({v[i]/w[i],i});
    }

    double sum = 0;
    while(cap > 0 && !pq.empty()){
        double vv = pq.top().first;
        int i = pq.top().second; pq.pop();
        if(cap > w[i]){
            sum +=v[i];
            cap -= w[i];
        }else{
            sum += cap*vv;
            cap = 0;
        }
    }
    cout<<fixed<<setprecision(4)<<sum;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 