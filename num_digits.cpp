#include <iostream>

int num_digits(int num) {
  if (num == 0) {
    return 0;
  }
  return 1 + num_digits(num/10);
}

int main() {
  auto n = num_digits(90012400);
  std::cout << n << std::endl;
}
