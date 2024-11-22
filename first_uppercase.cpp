#include <iostream>
#include <cctype>

std::optional<std::size_t>
first_upper_case_idx(const char* arr) {
  if (arr == nullptr) { return std::nullopt; }
  if (std::isupper(*arr)) { return 0; }
  return 1 + *first_upper_case_idx(arr + 1);
}

std::optional<char>
first_upper_case_letter(const char* arr) {
  if (arr == nullptr) { return std::nullopt; }
  if (*arr == '\0') { return std::nullopt; }
  if (std::isupper(*arr)) { return *arr; }
  return *first_upper_case_letter(arr + 1);
}

int main() {
  std::cout << *first_upper_case_idx("abC") << std::endl;
  std::cout << *first_upper_case_letter("acb1~BC") << std::endl;
}
