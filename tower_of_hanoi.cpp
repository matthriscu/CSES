#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << (1 << n) - 1 << '\n';

  function<void(int, int, int, int)> hanoi = [&hanoi](int from, int via, int to,
                                                      int steps) {
    if (steps == 0)
      return;

    hanoi(from, to, via, steps - 1);
    cout << from << ' ' << to << '\n';
    hanoi(via, from, to, steps - 1);
  };

  hanoi(1, 2, 3, n);
}
