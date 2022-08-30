#include <iostream>
#include <queue>
using namespace std;

struct Coord {
	int y, x, lev;
};

int main()
{
	int dirY[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int dirX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };


	int T = 0;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int map[300][300] = { 0 };
		int N = 0, cnt = 0;;
		cin >> N;

		Coord start, dest;
		cin >> start.y >> start.x;
		cin >> dest.y >> dest.x;

		queue<Coord> q;
		q.push({ start.y, start.x, 0 });
		map[start.y][start.x] = 1;

		while (!q.empty()) {
			Coord now = q.front();
			q.pop();

			if (now.y == dest.y && now.x == dest.x) {
				cout << now.lev << "\n";
				break;
			}

			for (int i = 0; i < 8; i++) {
				int ny = now.y + dirY[i];
				int nx = now.x + dirX[i];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (map[ny][nx] == 1) continue;
				map[ny][nx] = 1;
				q.push({ ny, nx, now.lev + 1 });
			}
		}
	}
	return 0;
}
