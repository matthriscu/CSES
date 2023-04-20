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

  map<int, int> freq;
  int best = 0;
  for (int l = 0, r = 0; l < n; ++l) {
    for (; r < n && freq[v[r]] == 0; ++r)
      ++freq[v[r]];

    best = max(r - l, best);

    --freq[v[l]];
  }

  cout << best << '\n';
}
