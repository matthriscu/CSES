#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a, b;
  cin >> n >> a >> b;

  vector<long long> v(n + 1);
  v[0] = 0;

  for (int i = 1; i <= n; ++i)
    cin >> v[i];

  partial_sum(v.begin(), v.end(), v.begin());

  long long mx = LLONG_MIN;
  deque<long long> dq;
  for (int i = a; i <= n; ++i) {
    while (!dq.empty() && dq.front() < i - b)
      dq.pop_front();

    while (!dq.empty() && v[dq.back()] >= v[i - a])
      dq.pop_back();

    dq.push_back(i - a);

    mx = max(v[i] - v[dq.front()], mx);
  }

  cout << mx << '\n';
}
