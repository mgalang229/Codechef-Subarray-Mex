#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n, k, x;
	cin >> n >> k >> x;
	if (k < x) {
		cout << -1 << '\n';
		return;
	}
	// we need to produce the same subarray of length K for all 0 <= i <= N - 1
	// example:
	// let N = 6, K = 3
	// sequence = {a, b, c, a, b, c}
	// 1st subarray = {a, b, c}
	// 2nd subarray = {b, c, a}
	// 3rd subarray = {c, a, b}
	// MEX(a, b, c) = MEX(b, c, a) = MEX(c, a, b) = MEX(a, b, c)
	// note: it is impossible to do if the value of K (subarray size) < X (MEX)
	vector<int> a(n, 0);
	int val = 0;
	for (int i = 0; i < n; i++) {
		int index = i;
		while (index < min(i + k, n)) {
			a[index++] = val;
			if (val < x - 1) {
				val++;
			} else {
				val = 0; // don't forget to reset to 0
			}
		}
		i = index - 1;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 1;
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		TestCase();
	}
	return 0;
}
