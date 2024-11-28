
#include <iostream>

void copy(const char* src, char* dst) {
  if (src == nullptr) { return; }
  if (*src == '\0') { return; }
  *dst = *src;
  copy(src + 1, dst + 1);
}

int main() {
  char dst[7];
  copy("abc d", dst);
  std::cout << dst << std::endl;
}
