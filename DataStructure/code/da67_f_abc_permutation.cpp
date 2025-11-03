#include<bits/stdc++.h>
using namespace std;

int a, b, c;
int n;

vector<string> res;

string cur;

void sol(int i, int x, int y, int z){
    if(i>n || x>a || y>b || z>c) return;
    // cout<<cur<<'\n';
    if(i == n){
        res.push_back(cur);
        return;
    }
    if(x<a){
        cur.push_back('A');
        sol(i+1,x+1,y,z);
        cur.pop_back();
    }
    if(y<b){
        cur.push_back('B');
        sol(i+1,x,y+1,z);
        cur.pop_back();
    }
    if(z<c){
        cur.push_back('C');
        sol(i+1,x,y,z+1);
        cur.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>a>>b>>c;
    sol(0,0,0,0);
    cout<<res.size()<<'\n';
    for(string x : res){
        cout<<x<<'\n';
    }
}