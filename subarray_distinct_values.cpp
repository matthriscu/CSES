#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  size_t k;
  cin >> n >> k;

  vector<int> v(n);
  for (int &x : v)
    cin >> x;

  int i = 0, j = 0;
  long long ans = 0;
  map<int, int> freq;
  while (j < n) {
    ++freq[v[j++]];

    while (freq.size() > k) {
      auto it = freq.find(v[i++]);

      if (it->second > 1)
        --it->second;
      else
        freq.erase(it);
    }

    ans += j - i;
  }

  cout << ans << '\n';
}
