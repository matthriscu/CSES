#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> index_of(n);

  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    index_of[x - 1] = i;
  }

  int ans = 1;
  for (int i = 1; i < n; ++i)
    ans += (index_of[i - 1] > index_of[i]);

  cout << ans << '\n';
}
