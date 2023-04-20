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

  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && v[st.top()] >= v[i])
      st.pop();

    cout << (st.empty() ? 0 : st.top() + 1) << ' ';

    st.push(i);
  }

  cout << '\n';
}
