#include<bits/stdc++.h>
using namespace std;

map<string,string> name2event;
set<string> names;
map<string,set<string>> event;
vector<pair<pair<string,bool>,pair<string,string>>> stk;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int query; cin>>query;
    while(query--){
        string cmd, name, e;
        cin>>cmd;
        
        if(cmd == "ADDEVENT"){
            cin>>e;
        }else if(cmd == "REGISTER"){
            cin>>e>>name;
            if(name2event.find(name) == name2event.end() || name2event[name] == ""){
                name2event[name] = e;
                event[e].insert(name);

                names.insert(name);
                stk.push_back({{cmd,1},{e,name}});
            }else{
                stk.push_back({{cmd,0},{e,name}});
            }
        }else if(cmd == "CANCEL"){
            cin>>e>>name;
            if(event[e].count(name)){
                name2event[name] = "";
                event[e].erase(name);
                stk.push_back({{cmd,1},{e,name}});
            }else{
                stk.push_back({{cmd,0},{e,name}});

            }
        }else if(cmd == "SHOW"){
            cin>>e;
            for(string name : event[e]){
                cout<<name<<' ';
            }
            cout<<'\n';
        }else if(cmd == "UNDO"){
            if(!stk.empty()){
                auto top = stk.back();
                stk.pop_back();
    
                auto [cmd, todo] = top.first;
                auto [e, name] = top.second;
    
                if(todo){
                    if(cmd == "REGISTER"){//to CANCEL
                        name2event[name] = "";
                        event[e].erase(name);
                    }else{//to REGISTER
                        name2event[name] = e;
                        event[e].insert(name);
                    }
                }
            }
        }
    }
}