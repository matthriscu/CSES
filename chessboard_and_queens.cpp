#include <bits/stdc++.h>
using namespace std;

#define N 8

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  array<string, N> board;
  for (string &row : board)
    cin >> row;

  bitset<N> cols;
  bitset<2 * N - 1> main_diag, sec_diag;

  function<int(int)> bkt = [&](int line) {
    if (line == N)
      return 1;

    int sum = 0;

    for (int i = 0; i < N; ++i)
      if (!(board[line][i] == '*' || cols[i] || main_diag[line - i + N] ||
            sec_diag[line + i])) {
        cols[i] = main_diag[line - i + N] = sec_diag[line + i] = true;
        sum += bkt(line + 1);
        cols[i] = main_diag[line - i + N] = sec_diag[line + i] = false;
      }

    return sum;
  };

  cout << bkt(0) << '\n';
}
