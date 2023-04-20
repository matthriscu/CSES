#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;

    if (a > b)
      swap(a, b);

    cout << (b <= 2 * a && (a + b) % 3 == 0 ? "YES\n" : "NO\n");
  }
}
