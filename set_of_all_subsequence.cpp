
#include <iostream>
#include <string_view>
#include <cassert>
#include <cstring>

void AllSubsequences(const char* str, std::size_t len, 
                     std::size_t subseq_len, std::string substr, int stack_depth) {
  //std::cout << "Stack Depth: " << stack_depth << ", " << len << ", " << subseq_len << std::endl;
  if (subseq_len == 1) {
    assert(len >= subseq_len);
    for (std::size_t i = 0; i < len; i++) {
      std::cout << substr;
      std::cout << *(str + i) << std::endl;
    }
    //std::cout << std::endl;
    return;
  }
  for (std::size_t i = 0; i <= len - subseq_len; i++) {
    substr += *(str + i);
    AllSubsequences(str + i + 1, len - i - 1, subseq_len - 1, substr, stack_depth + 1);
    substr.pop_back();
  }
}

int main() {
  char arr[6] = "abcde";
  AllSubsequences(arr, strlen(arr), 1, "", 0);
  std::cout << std::endl;
  AllSubsequences(arr, strlen(arr), 2, "", 0);
  std::cout << std::endl;
  AllSubsequences(arr, strlen(arr), 3, "", 0);
  std::cout << std::endl;
  AllSubsequences(arr, strlen(arr), 4, "", 0);
  std::cout << std::endl;
  AllSubsequences(arr, strlen(arr), 5, "", 0);
}
