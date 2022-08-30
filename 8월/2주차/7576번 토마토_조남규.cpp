#include <iostream>
#include <queue>
using namespace std;

struct Coord {
	int y, x, lev;
};

void printMap(int map[1000][1000], int N, int M)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	int dirY[4] = { -1, 1, 0, 0 };
	int dirX[4] = { 0, 0, -1, 1 };

	int M = 0, N = 0, cnt = 0;
	cin >> M >> N;
	int cnt0 = 0;

	int map[1000][1000] = { 0 };


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	queue<Coord> q;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				q.push({ i, j, 0 });
			}
			if (map[i][j] == 0) {
				cnt0++;
			}
		}

	while (!q.empty()) {
		Coord now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dirY[i];
			int nx = now.x + dirX[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == 1) continue;
			if (map[ny][nx] == -1) continue;
			map[ny][nx] = 1;
			q.push({ ny, nx, now.lev + 1 });
			cnt = now.lev + 1;
			cnt0--;
			//printMap(map, N, M);
			//cout << cnt << " : " << cnt0 << "\n";
		}

	}

	if (cnt0 == 0)
		cout << cnt;
	else
		cout << -1;

	return 0;
}
