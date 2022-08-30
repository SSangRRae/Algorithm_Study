#include <iostream>
#include <queue>
using namespace std;

struct Node {
   int y;
   int x;
};
int m, n;
int arr[1001][1001];
int directY[4] = { -1, 1, 0, 0 };
int directX[4] = { 0, 0, -1, 1 };
queue<Node> q;

int main()
{
   int cnt = 0;
   int time = 0;

   cin >> m >> n;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> arr[i][j];
         if (arr[i][j] == 1)
         {
            q.push({ i, j });
            cnt++;
         }
         else if (arr[i][j] == -1) cnt++;
      }
   }

   while (!q.empty())
   {
      Node now = q.front();
      q.pop();

      time = arr[now.y][now.x];

      for (int i = 0; i < 4; i++)
      {
         int ny = now.y + directY[i];
         int nx = now.x + directX[i];

         if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
         if (arr[ny][nx] != 0) continue;

         arr[ny][nx] = arr[now.y][now.x] + 1;
         cnt++;
         q.push({ ny, nx });
      }
   }

   if (cnt == m * n) cout << time-1;
   else cout << -1;

   return 0;
}