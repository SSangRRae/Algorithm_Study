#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int cntRow, cntCol;
int cntZero = 0, cntOne = 0;
int map[1010][1010] = { 0 };
int used[1010][1010] = { 0 };
int dr[4] = { 0,  0, -1,  1 };
int dc[4] = { 1,   -1, 0,  0 };
struct Node {
	int y; int x; int times;
};
int main() {
	cin >> cntCol >> cntRow;
	queue<Node> q;
	//값 입력받음
	for (int i = 0; i < cntRow; i++) {
		for (int j = 0; j < cntCol; j++) {
			int tmp; cin >> tmp;
			if (tmp == 0) cntZero++;
			else if (tmp == 1) { 
				cntOne++;
				q.push({i, j, 0});
				used[i][j] = 1;
			}
			map[i][j] = tmp;
		}
	}
	//전부 익은토마토 이면 "0"출력후 종료
	if (cntZero == 0) { 
		cout << 0;  return 0; }
	//bfs 시작. Node.times 에 도달하는데 몇번 걸렸는지가 저장된다.
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int t = 0; t < 4; t++) {
			int R = now.y + dr[t];
			int C = now.x + dc[t];
			if (R < 0 || C < 0 || R >= cntRow || C >= cntCol) continue;
			if (map[R][C] != 0) continue;
			if (used[R][C] == 1) continue;
			used[R][C] = 1;
			int times = now.times + 1;
			q.push({R, C, times});
			cntZero--;
			if (cntZero == 0) { 
				cout << times; 
				return 0;
			}
		}
	}

	cout << -1;
	return 0;
}
