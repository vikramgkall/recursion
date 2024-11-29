
#include <iostream>
#include <string>

void permutations_of_string(std::string arr, std::size_t s_index) {
  // Permute a string of length 5 =>
  // Hold the char at 0th index and permute the rest, swap the 0th index with 1st and permute the rest,
  // swap the 0th index with 2nd and permute the rest, swap the 0th index with 3rd and permute the rest
  // Can also generalize the first part as
  // Swap the 0th index with 0th and permute the rest
  //
  // Swap the 0th index with each of the "length" indices and permute the rest of the string
  // permute => swap and print
  if (arr.size() == s_index) {
    for (std::size_t i = 0; arr[i] != '\0'; i++) {
      std::cout << arr[i];
    }
    std::cout << std::endl;
    return;
  }
  for (std::size_t i = s_index; i < arr.size(); i++) {
    std::swap(arr[s_index], arr[i]);
    permutations_of_string(arr, s_index + 1);
    std::swap(arr[s_index], arr[i]);
  }
}

int main() {
  std::string str = "abcd";
  permutations_of_string(str, 0);
}
