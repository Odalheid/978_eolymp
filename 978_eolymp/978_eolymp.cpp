#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void dfs(const int &vertex, vector<pair<int, int>> &v, vector <bool> &used) {
	used[vertex - 1] = true;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first == vertex && !used[v[i].second - 1]) {
			cout << v[i].first << ' ' << v[i].second << endl;
			dfs(v[i].second, v, used);
		}
		else if (v[i].second == vertex && !used[v[i].first - 1]) {
			cout << v[i].second << ' ' << v[i].first << endl;
			dfs(v[i].first, v, used);
		}
	}
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	vector<pair<int, int>> v(edges);
	vector<bool> used(vertices, false);
	for (int i = 0; i < edges; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}
	dfs(1, v, used);
    return 0;
}

