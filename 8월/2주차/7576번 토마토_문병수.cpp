#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct node {
	int y;
	int x;
	int state;
	int day;
};

void check(vector<vector<node>> V, int day) {
	bool flag = false;

	for (vector<node> v : V) {
		for (node n : v) {
			if (n.state == 0) flag = true;
		}
	}

	if (flag) cout << -1;
	else cout << day;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int dy[] = {  0, 0, -1, 1 };
	int dx[] = { -1, 1,  0, 0 };
	int row, col, startY, startX;
	cin >> col >> row;
	
	vector<vector<node>> map(row, vector<node>(col));
	queue<node> q;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int state;
			cin >> state;
			map[i][j] = { i, j, state };
			if (state == 1) q.push({ i, j, -2, 0 });
		}
	}

	while (1) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
			if (map[ny][nx].state != 0) continue;
			map[ny][nx].state = -2;
			q.push({ ny, nx, -2, now.day + 1 });
		}

		if (q.empty()) {
			check(map, now.day);
			break;
		}
	}
}