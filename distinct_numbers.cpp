#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (int &x : v)
    cin >> x;

  sort(v.begin(), v.end());

  cout << distance(v.begin(), unique(v.begin(), v.end())) << '\n';
}
