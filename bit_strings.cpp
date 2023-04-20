#include <bits/stdc++.h>
using namespace std;

#define MOD 1'000'000'007

int exp(int b, int e) {
  int ans = 1;

  while (e) {
    if (e & 1)
      ans = (1LL * ans * b) % MOD;

    b = (1LL * b * b) % MOD;
    e >>= 1;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << exp(2, n) << '\n';
}
