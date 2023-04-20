#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int &x : coins)
    cin >> x;

  vector<int> dp(x + 1, INF);
  dp[0] = 0;

  for (int i = 1; i <= x; ++i)
    for (int coin : coins)
      if (i - coin >= 0)
        dp[i] = min(dp[i - coin] + 1, dp[i]);

  cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
}
