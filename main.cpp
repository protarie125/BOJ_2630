#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi pad;
vi ans = vi(2, 0);

void solve(int x, int y, int n) {
	const auto& b = pad[y][x];

	if (1 == n) {
		++ans[b];

		return;
	}

	auto isAll = bool{ true };
	for (auto i = 0; i < n && isAll; ++i) {
		const auto& ny = y + i;
		for (auto j = 0; j < n && isAll; ++j) {
			const auto& nx = x + j;

			if (b != pad[ny][nx]) {
				isAll = false;
				break;
			}
		}
	}

	if (isAll) {
		++ans[b];

		return;
	}

	const auto& hn = n / 2;
	solve(x, y, hn);
	solve(x + hn, y, hn);
	solve(x, y + hn, hn);
	solve(x + hn, y + hn, hn);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; cin >> n;
	pad = vvi(n, vi(n, 0));
	for (auto y = 0; y < n; ++y) {
		for (auto x = 0; x < n; ++x) {
			cin >> pad[y][x];
		}
	}

	solve(0, 0, n);

	cout << ans[0] << '\n' << ans[1];

	return 0;
}