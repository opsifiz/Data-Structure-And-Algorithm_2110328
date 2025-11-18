#include<bits/stdc++.h>
using namespace std;

const int N = 20, M = 1000;

bitset<M> a[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int mn = 1e9;
    int n, m;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        while(k--){
            int x; cin>>x;
            a[i] |= 1<<(x-1);
        }
    }
    for(int mask=0;mask<(1<<n);mask++){
        if(__builtin_popcount(mask) > mn) continue;
        bitset<M> days;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                days |= a[i];
            }
        }
        if(days.count() == m){
            mn = min(mn,__builtin_popcount(mask));
        }
    }
    cout<<mn;
}