#include <iostream>
#include <string>
#include "aplusb.h"

using std::cin;
using std::cout;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    cout<<sum(a,b);
    return 0;
}