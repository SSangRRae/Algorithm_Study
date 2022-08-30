#include <iostream>
#include <queue>
using namespace std;

struct Node {
   int y, x;
};
int test_case;
int n;
int startY, startX, endY, endX;
int map[301][301];
int directY[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int directX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main()
{
   cin >> test_case;

   for (int i = 0; i < test_case; i++)
   {
      queue<Node> q;
      int used[301][301] = { 0, };
      cin >> n >> startY >> startX >> endY >> endX;
      
      q.push({ startY, startX });
      used[startY][startX] = 1;

      while (!q.empty())
      {
         Node now = q.front();
         q.pop();

         if (now.y == endY && now.x == endX)
         {
            cout << used[now.y][now.x] - 1 << "\n";
            break;
         }

         for (int i = 0; i < 8; i++)
         {
            int ny = now.y + directY[i];
            int nx = now.x + directX[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (used[ny][nx] != 0) continue;

            used[ny][nx] = used[now.y][now.x] + 1;
            q.push({ ny, nx });
         }
      }
   }

   return 0;
}