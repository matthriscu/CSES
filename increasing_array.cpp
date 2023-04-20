#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, last, current;
	cin >> n >> last;

	long long ans = 0;

	for (int i = 1; i < n; ++i) {
		cin >> current;
		ans += max(last - current, 0);
		last = max(current, last);
	}

	cout << ans << '\n';
}
