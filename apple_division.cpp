#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  for (int &x : p)
    cin >> x;

  long long best = LLONG_MAX;

  for (int i = 0; i < (1 << n); ++i) {
    long long diff = 0;

    for (int j = 0; j < n; ++j)
      if (i & (1 << j))
        diff += p[j];
      else
        diff -= p[j];

    best = min(abs(diff), best);
  }

  cout << best << '\n';
}

