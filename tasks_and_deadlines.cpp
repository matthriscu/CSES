#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  long long dl_sum = 0;
  vector<long long> durations(n);
  for (long long duration : durations) {
    long long dl;
    cin >> duration >> dl;
    dl_sum += dl;
  }

  sort(durations.begin(), durations.end());
  partial_sum(durations.begin(), durations.end(), durations.begin());

  cout << dl_sum - reduce(durations.begin(), durations.end()) << '\n';
}
