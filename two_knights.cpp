#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cout << (1LL * i * i * i * i - 9 * i * i + 24 * i - 16) / 2 << '\n';
}
