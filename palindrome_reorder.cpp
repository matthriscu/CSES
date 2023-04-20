#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int freq[26]{};
  for (char c : s)
    ++freq[c - 'A'];

  bool odd = 0;
  char center = '\0';

  for (int i = 0; i < 26; ++i)
    if (freq[i] % 2 == 1) {
      if (odd) {
        cout << "NO SOLUTION\n";
        return 0;
      } else {
        odd = true;
        center = i + 'A';
      }
    }

  for (char c = 'A'; c <= 'Z'; ++c)
    for (int j = 1; j <= freq[c - 'A'] / 2; ++j)
      cout << c;

  if (odd)
    cout << center;

  for (char c = 'Z'; c >= 'A'; --c)
    for (int j = 1; j <= freq[c - 'A'] / 2; ++j)
      cout << c;

  cout << '\n';
}
