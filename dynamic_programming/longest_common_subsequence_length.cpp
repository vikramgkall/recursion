#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <string_view>
#include <array>
#include <limits>
#include <cassert>

/* Time complexity - 
For abc - number of subsequences is 7 - a, b, c, ab, ac, bc, abc
For abcd - number of subsequences is 15 - a, b, c, d, ab, ac, ad, bc, bd, cd, abc, abd, acd, bcd, abcd
For a string of length n, the number of subsequences in 2^n - 1.
Length of seq1 is m and seq2 is n. O(2^(m+n))
For every letter in seq1, there can be 2^n subsequences of seq2 and vice versa.

Another explanation:
Given two strings of length m and n, at each recursive call LCS(i, j):
If characters match: make 1 recursive call: LCS(i-1, j-1)
If not: make 2 recursive calls:
LCS(i-1, j)
LCS(i, j-1)
So in the worst case (no characters match), every call splits into 2 recursive calls — like a binary tree.

Let’s visualize just the structure of calls for LCS(m, n) in the worst case:

                LCS(m, n)
                /       \
         LCS(m-1, n)   LCS(m, n-1)
          /     \         /     \
LCS(m-2, n)  LCS(m-1, n-1) ...   ...

Each recursive call reduces either m or n (or both).
The maximum depth of recursion is when we reduce both m and n down to 0 — so the maximum depth = m + n.
Now at each level of recursion, we can spawn up to 2 recursive calls.

Imagine the recursion tree as a binary tree with depth = m + n.

In a binary tree of depth d, the maximum number of nodes is:

Total nodes ≤ 2^(𝑑+1) − 1
So if the depth is m + n, the number of recursive calls is: 𝑂(2^(𝑚+𝑛))
This is an upper bound — in practice, not every path will be taken because:
Sometimes we make only 1 recursive call (on match),
Base cases stop recursion early.
But we still use the worst-case for time complexity, and that’s when:
No characters match, so we always take both branches.
*/

std::size_t LCSLengthRecursion(std::string_view seq1, std::string_view seq2) {
  //std::cout << seq1 << " " << seq2 << std::endl;
  if (seq1.size() == 0 || seq2.size() == 0) {
    return 0;
 }
 if (seq1[0] == seq2[0]) {
   seq1.remove_prefix(1);
   seq2.remove_prefix(1);
   return 1 + LCSLength(seq1, seq2);
 } else {
   std::string_view tmp = seq2;
   seq2.remove_prefix(1);
   std::size_t len_1 = LCSLength(seq1, seq2);
   seq1.remove_prefix(1);
   return std::max(LCSLength(seq1, tmp), len_1);
 }
}

/* The number of distinct subproblems is limited, because we only call LCS(i, j) for values of 0 ≤ i ≤ m and 0 ≤ j ≤ n.

So:

The total number of unique subproblems is at most 
(m+1)×(n+1)=O(mn)

Each subproblem LCS(i, j) is computed at most once and takes constant time apart from its recursive calls.
*/

template<std::size_t M, std::size_t N>
std::size_t LCSLength(std::string_view seq1, std::string_view seq2, std::array<std::array<std::size_t, M>, N>& arr,
                      std::size_t row_index, std::size_t col_index)
{
    //std::cout << seq1 << " " << seq2 << std::endl;
    if (seq1.empty() || seq2.empty()) { return 0;}
    assert(row_index <= M);
    assert(col_index <= N);
    if (arr[row_index][col_index] != std::numeric_limits<std::size_t>::max()) {
        auto stored_len = arr[row_index][col_index];
        //std::cout << __LINE__ << " Hit: arr[" << row_index << "][" << col_index << "] " << stored_len << std::endl;
        return stored_len;
    }
    if (seq1[0] == seq2[0]) {
      seq1.remove_prefix(1);
      seq2.remove_prefix(1);
      return 1 + LCSLength(seq1, seq2, arr, row_index + 1, col_index + 1);
    }
    auto tmp = seq2;
    seq2.remove_prefix(1);
    auto len1 = LCSLength(seq1, seq2, arr, row_index+1, col_index);
    seq1.remove_prefix(1);
    auto len2 = LCSLength(seq1, tmp, arr, row_index, col_index+1);
    arr[row_index][col_index] = std::max(len1, len2);
    //std::cout << __LINE__ << " Set: arr[" << row_index << "][" << col_index << "] " << std::max(len1, len2) << std::endl;
    return arr[row_index][col_index];
}

int main() {
  //std::cout << LCSLength("bacd", "cdab") << std::endl;
  std::array<std::array<std::size_t, 5>, 4> arr = {{ {{0, 0, 0, 0, 0}}, {{0,0,0,0}} }};
  arr.fill({std::numeric_limits<std::size_t>::max()});
  for (std::size_t i = 0; i < 4; i++) {
    std::fill(arr[i].begin(), arr[i].end(), std::numeric_limits<std::size_t>::max());
    std::cout << std::endl;
  }
  std::cout << LCSLength("aebcd", "bcod", arr, 0, 0) << std::endl; 
}
