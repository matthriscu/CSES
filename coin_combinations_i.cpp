#include <bits/stdc++.h>
using namespace std;

#define MOD 1'000'000'007

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int &x : coins)
    cin >> x;

  vector<int> dp(x + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= x; ++i)
    for (int coin : coins)
      if (i - coin >= 0)
        dp[i] = (dp[i] + dp[i - coin]) % MOD;

  cout << dp[x] << '\n';
}
