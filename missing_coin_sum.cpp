#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (int &x : v)
    cin >> x;

  sort(v.begin(), v.end());

  long long s = 0;
  for (int x : v) {
    if (x > s + 1) {
      cout << s + 1 << '\n';
      return 0;
    }

    s += x;
  }

  cout << s + 1 << '\n';
}
