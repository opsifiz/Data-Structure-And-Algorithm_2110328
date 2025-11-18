#include <iostream>
#include <vector>
#include "aplusb.h"

using std::cin;
using std::cout;

int main() {
  int n;
  cin>>n;
  std::vector<int>a;
  std::vector<int>b;
  for(int i=0;i<n;i++){
    int input;
    cin>>input;
    a.push_back(input);
  }
  for(int i=0;i<n;i++){
    int input;
    cin>>input;
    b.push_back(input);
  }
  initialize(a,b);
  int q;
  cin>>q;
  for(int k=0;k<q;k++){
    int i,j;
    cin>>i>>j;
    cout<<answer_question(i,j)<<"\n";
  }
}
