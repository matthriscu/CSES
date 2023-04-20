#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	size_t best = 0, current = 1;
	for (size_t i = 1; i < s.size(); ++i)
		if (s[i] == s[i - 1])
			++current;
		else {
			best = max(current, best);
			current = 1;
		}

	cout << max(current, best) << '\n';
}
