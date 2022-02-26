#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n, k, x;
	cin >> n >> k >> x;
	if (x > k) {
		cout << -1 << '\n';
		return;
	}
	int cur = 0;
	int a[n] = {0};
	for (int i = 0; i < k; i++) {
		if (i == x) { // skip the assigned MEX
			cur++;
		}
		a[i] = cur;
		cur++;
	}
	for (int i = k; i < n; i++) {
		a[i] = a[i - k]; // re-create the subarray of length K
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
