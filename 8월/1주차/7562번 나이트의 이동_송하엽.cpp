#pragma once
//10달전 풀이
#include <iostream>
#include <cstring>
#include <queue>


using namespace std;

int N, l, x, y, ax, ay;
int arr[301][301];
bool visited[301][301];
int dx[] = { -1, -2 , -2, -1 , 1, 2, 2, 1 };
int dy[] = { -2, -1 , 1, 2 , -2, -1, 1, 2 };
queue<pair<int, int>> q;

void BFS(int a, int b) {
	q.push(make_pair(a, b));
	visited[a][b] = true;

	while (!q.empty()) {
		int x2 = q.front().first;
		int y2 = q.front().second;
		q.pop();

		if (x2 == ax && y2 == ay) {
			cout << arr[x2][y2] << "\n";

			while (!q.empty()) {
				q.pop();
			}
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x2 + dx[i];
			int ny = y2 + dy[i];

			if (0 <= nx && nx < l && 0 <= ny && ny < l) {
				if (visited[nx][ny] == false) {
					visited[nx][ny] = true;
					arr[nx][ny] = arr[x2][y2] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> l;
		cin >> x >> y >> ax >> ay;
		BFS(x, y);
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}
}


//새로운 풀이.