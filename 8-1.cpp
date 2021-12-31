/**
 * @Author: George Lu
 * @Date:   2021-12-21 16:52:44
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 15:07:17
 */
#include <iostream>
#include <vector>
using namespace std;
int find(int *fa, int x);
int main() {
	int n, m;
	vector<char> res;
	cin >> n >> m;
	int *fa = new int[n];
	for (int i = 0; i < n; i++) fa[i] = i + 1;
	for (int i = 0; i < m; i++) {
		int z, x, y;
		cin >> z >> x >> y;
		if (z == 1) {
			fa[find(fa, x)-1] = find(fa, y);
		}
		if (z == 2) {
			if (find(fa, x) == find(fa, y)) {
				res.push_back('Y');
			}
			else {
				res.push_back('N');
			}
		}
	}
	int t = res.size();
	for (int i = 0; i < t; i++) {
		cout << res[i] << endl;
	}
	delete fa;
	return 0;
}

int find(int *fa, int x) {
	if (x == fa[x - 1]) return x;
	else {
		fa[x - 1] = find(fa, fa[x - 1]);
		return fa[x - 1];
	}
}