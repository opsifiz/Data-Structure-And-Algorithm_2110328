#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::deque<std::vector<std::queue<int>>> b;
    while(!a.empty()){
        b.push_front(a.top());
        a.pop();
    }
    for(std::vector<std::queue<int>> &vqi : b){
        for(std::queue<int> &qi : vqi){
            int sz = qi.size();
            while(sz--){
                if(qi.front() == from){
                    qi.push(to);
                }else{
                    qi.push(qi.front());
                }
                qi.pop();
            }
        }
        a.push(vqi);
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto &[_, ppqi] : a){
        auto &[pq, i] = ppqi;
        if(i == from) i = to;
        int sz = pq.size();
        std::vector<int> temp(sz);
        for(int i=0;i<sz;i++){
            temp[i] = pq.top(); pq.pop();
            if(temp[i] == from) temp[i] = to;
        }
        for(int x : temp){
            pq.push(x);
        }
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> newA;

    for(auto &plimipis : a){
        auto [li, mipis] = plimipis;
        int sz = li.size();
        std::list<int> cp;
        for(auto &x : li){
            if(x == from){
                cp.push_back(to);
            }else{
                cp.push_back(x);
            }
        }
        
        std::map<int, std::pair<int, string>> newMap;
        for(auto &[key, val] : mipis){
            int newKey = key==from?to:key;
            int pf = val.first==from?to:val.first;
            string ps = val.second;

            newMap[newKey] = {pf, ps};
        }

        newA.insert({cp,newMap});
    }
    a = newA;
}

#endif
