#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  if (n % 4 == 1 || n % 4 == 2) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n" << (n + 1) / 2 << '\n';

  if (n % 2)
    cout << "1 2 ";

  for (int i = n % 2 ? 4 : 1; i < n; i += 4)
    cout << i << ' ' << i + 3 << ' ';

  cout << '\n' << n / 2 << '\n';

  if (n % 2)
    cout << "3 ";

  for (int i = n % 2 ? 5 : 2; i < n; i += 4)
    cout << i << ' ' << i + 1 << ' ';

  cout << '\n';
}
