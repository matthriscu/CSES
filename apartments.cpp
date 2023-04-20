#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> budgets(n);
  for (int &x : budgets)
    cin >> x;

  vector<int> apartments(m);
  for (int &x : apartments)
    cin >> x;

  sort(budgets.begin(), budgets.end());
  sort(apartments.begin(), apartments.end());

  int i = 0, j = 0, ans = 0;
  while (i < n && j < m) {
    if (abs(budgets[i] - apartments[j]) <= k) {
      ++ans;
      ++i;
      ++j;
    } else if (budgets[i] > apartments[j])
      ++j;
    else
      ++i;
  }

  cout << ans << '\n';
}
