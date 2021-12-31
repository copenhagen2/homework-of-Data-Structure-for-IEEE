/**
 * @Author: George Lu
 * @Date:   2021-12-21 16:53:07
 * @Last Modified by:   George Lu
 * @Last Modified time: 2021-12-24 15:07:18
 */
#include <iostream>
using namespace std;
int findLCA(int *parent, int *level, int x, int y);
int main() {
	int n, m;
	cin >> n >> m;
	int *parent = new int[n+1], *level = new int[n+1];
	int *res = new int[m];
	level[1] = 0;
	parent[1] = -1;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		parent[i] = x;
		level[i] = level[x] + 1;
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		int x;
		cin >> x;
		for (int j = 1; j < k; j++) {
			int y;
			cin >> y;
			x = findLCA(parent, level, x, y);
		}
		res[i] = x;
	}
	for (int i = 0; i < m; i++) {
		cout << res[i] << endl;
	}
	delete parent; 
	delete level;
	delete res;
	return 0;
}
int findLCA(int *parent, int *level, int x, int y) {
	int u = (level[x] > level[y])? x : y;
	int v = (level[x] <= level[y])? x : y;
	while (level[u] != level[v]) u = parent[u]; //跳到同一层级
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}