#include <vector>

std::vector<int> x, y;

void initialize(std::vector<int> A, std::vector<int> B) {
  //you code here
  x = A;
  y = B;
  return;
}

int answer_question(int i, int j) {
  // you code here
  return x[i]+y[j];
}
