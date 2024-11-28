
#include <iostream>
#include <optional>

std::optional<int> max_in_array(int *arr, std::size_t length) {
  if (length == 0) { return std::nullopt; }
  if (length == 1) { return *arr; }
  return std::max(*arr, *max_in_array(arr + 1, length - 1));
}

int main() {
  int arr[7] = {1244, 234, 34, 53, 0, 82, 2352};
  std::cout << *max_in_array(arr, 7) << std::endl;
}
