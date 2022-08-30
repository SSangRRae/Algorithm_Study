#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct Node {
	int y; int x;
};


int cntSize;
int dr[8] = {-1, -2, -2, -1,  1, 2, 2, 1};
int dc[8] = {-2, -1,  1,  2,  2, 1, -1, -2};
int map[310][310] = { 0 };
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> cntSize;
		int a, b;
		cin >> a >> b;
		
		Node tar;
		cin >> tar.y >> tar.x;
		if (a == tar.y && b == tar.x) {
			cout << "0\n";
			continue;
		}
		int flag = 0;
		queue<Node> q;
		q.push({ a, b });
		map[a][b] = 1;
		while (!q.empty()) {
			if (flag == 1) {
				cout << map[tar.y][tar.x] - 1 << "\n";
				break;
			}
			Node now = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				int R = now.y + dr[i];
				int C = now.x + dc[i];
				if (R < 0 || C < 0 || R >= cntSize || C >= cntSize) continue;
				if (map[R][C] != 0) continue;
				map[R][C] = map[now.y][now.x] + 1;
				q.push({ R, C });
				if (R == tar.y && C == tar.x) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) cout << "0\n";
		for (int k = 0; k < cntSize; k++) {
			for (int l = 0; l < cntSize; l++) {
				map[k][l] = 0;
			}
		}
	}
	return 0;
}
