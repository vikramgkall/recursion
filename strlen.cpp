#include <iostream>

int strLen(const char* arr)
{
  if (arr == nullptr) {
    return 0;
  }
  if (*arr == '\0') {
    return 0;
  }
  return 1 + strlen(arr + 1);
}

int main() {
  std::cout << strLen("abc") << std::endl;
}
