#include <iostream>

int pow(int x, int y) {
  if (y == 0) {
    return 1;
  }
  return x * pow(x, y-1);
}

int main() {
  auto p = pow(5,3);
  std::cout << p << std::endl;
}
