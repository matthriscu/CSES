#include <bits/stdc++.h>
using namespace std;

#define MOD 1'000'000'007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> dp(n + 1, 0), dice{1, 2, 3, 4, 5, 6};
  dp[0] = 1;

  for (int i = 1; i <= n; ++i)
    for (int die : dice)
      if (i - die >= 0)
        dp[i] = (dp[i] + dp[i - die]) % MOD;

  cout << dp[n] << '\n';
}
