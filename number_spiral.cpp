#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int y, x;
		cin >> y >> x;

		int mx = max(y, x);
		long long c = 1LL * mx * (mx - 1) + 1;

		cout << (mx % 2 ? c - y + x : c + y - x) << '\n';
	}
}
