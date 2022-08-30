#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct node {
	int y;
	int x;
	int lv;
};

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int dy[] = { -2,-2,-1, 1, 2, 2, 1, -1 };
	int dx[] = { -1, 1, 2, 2, 1,-1,-2, -2 };

	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int N, startY, startX, endY, endX;
		cin >> N >> startY >> startX >> endY >> endX;

		vector<vector<int>> used(N, vector<int>(N, 0));
		queue<node> q;
		q.push({ startY, startX, 0 });
		used[startY][startX] = 1;
		
		while (!q.empty()) {
			node now = q.front();
			q.pop();
			if (now.y == endY && now.x == endX) {
				cout << now.lv << "\n";
				break;
			}
			for (int i = 0; i < 8; i++) {
				int ny = dy[i] + now.y;
				int nx = dx[i] + now.x;

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (used[ny][nx] == 1) continue;
				used[ny][nx] = 1;

				q.push({ ny, nx, now.lv + 1 });
			}
		}
	}
}