#pragma once
//1년전 풀이.
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, cnt = 0;
int arr[1001][1001];
bool visited[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

queue<pair<pair<int, int>, int>> q;

void BFS(void) {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
			if (arr[nx][ny] == 0 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				visited[i][j] = true;
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	BFS();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				cnt = -1;
				break;
			}
		}
	}

	cout << cnt;

}






//새로운 풀이.