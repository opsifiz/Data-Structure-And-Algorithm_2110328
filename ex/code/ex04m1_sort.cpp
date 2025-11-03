#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

map<int,int> mp, tp;
int a[N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int cnt=0;
    for(int i=1;i<=n&&cin>>a[i];i++) mp[a[i]]++;

    for(int i=1;i<=mp[1];i++){
        if(a[i] != 1){
            tp[a[i]]++;
            a[i] = 1;
            cnt++;
        }
    }
    for(int i=mp[1]+1;i<=n;i++){
        if(a[i] == 1){
            if(tp[2]){
                tp[2]--;
                a[i] = 2;
            }else{
                tp[3]--;
                a[i] = 3;
            }
        }
    }

    tp.clear();
    for(int i=mp[1]+1;i<=mp[1]+mp[2];i++){
        if(a[i] != 2){
            // tp[a[i]]++;
            // a[i] = 2;
            cnt++;
        }
    }
    // for(int i=mp[1]+1;i<=n;i++){
    //     if(a[i] == 1){
    //         if(tp[2]){
    //             tp[2]--;
    //             a[i] = 2;
    //         }else{
    //             tp[3]--;
    //             a[i] = 3;
    //         }
    //     }
    // }

    cout<<cnt;
}