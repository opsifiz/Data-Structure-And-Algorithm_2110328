#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

int a[N+5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--){
        int target, cnt = 0;
        cin>>target;
        for(int i=1;i<=n;i++){
            cnt += a[i]>target;
            if(target == a[i]) break;
        }
        cout<<cnt<<'\n';
    }
}