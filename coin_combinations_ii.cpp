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

  sort(coins.begin(), coins.end());

  vector<int> dp(x + 1, 0);

  for (int i = 0; i <= x; i += coins[0])
    dp[i] = 1;

  for (int i = 1; i < n; ++i)
    for (int j = coins[i]; j <= x; ++j)
      dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;

  cout << dp[x] << '\n';
}
