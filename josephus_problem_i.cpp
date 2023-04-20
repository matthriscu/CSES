#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int a = 1, b = 0; n; a *= 2, n /= 2) {
    for (int i = 2; i <= n; i += 2)
      cout << a * i + b << ' ';

    if (n % 2 == 0)
      b -= a;
    else {
      cout << a + b << ' ';
      b += a;
    }
  }

  cout << '\n';
}
