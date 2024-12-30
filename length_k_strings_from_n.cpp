
#include <iostream>
#include <cstdint>
#include <string>

template <std::size_t arr_length, std::size_t out_length>
void nchoosek(std::array<char, arr_length>& str,
              int k,
              std::array<char, out_length>& out,
              int index,
              int start)
{
  for (std::size_t i = start; i < str.size(); i++) {
    if (index == k - 1) {
      out[index] = str[i];
      for (std::size_t j = 0; j < out.size(); j++) {
        std::cout << out[j];
      }
      std::cout << std::endl;
      continue;
    }
    out[index] = str[i];
    nchoosek(str, k, out, index + 1, std::max(i, std::size_t(index)) + 1);
  }
}

int main() {
  std::array<char, 2> out_str;
  std::array<char, 4> arr = {'a', 'b', 'c', 'd'}; 
  nchoosek(arr, 2, out_str, 0, 0);
}
