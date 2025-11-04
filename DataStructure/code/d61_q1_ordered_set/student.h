#include <vector>
#include<set>
#include<algorithm>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    v = vector<T>(A.begin(), A.end());
    set<T> s(A.begin(), A.end());
    for(int x : B){
        if(s.find(x) == s.end()){
            v.push_back(x);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s(B.begin(), B.end());
    for(int x : A){
        if(s.find(x) != s.end()){
            v.push_back(x);
        }
    }
    return v;
}
