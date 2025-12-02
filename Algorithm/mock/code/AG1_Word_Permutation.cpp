#include<bits/stdc++.h>
using namespace std;

const int N = 12;

string s;
int n;

set<string> st;
map<char,bool> used;

void sol(int i){
    if(i == n){
        st.insert(s);
        return;
    }
    for(int j=i;j<n;j++){
        if(j>i && s[j-1] == s[j]){
            continue;
        }
            swap(s[i],s[j]);
            sol(i+1);
            swap(s[i],s[j]);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    n = s.size();
    sort(s.begin(),s.end());
    sol(0);
    cout<<st.size()<<'\n';
    for(auto &word : st){
        cout<<word<<'\n';
    }
}