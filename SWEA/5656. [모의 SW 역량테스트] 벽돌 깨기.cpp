#include <iostream>

#include <queue>
using namespace std;

int n, w, h;
int arr[15][12];  // 입력 배열을 저장할 배열 선언
int arr_copy[4][15][12];  // 이전 level의 배열을 level 별로 backup해 둘 배열 선언
                          // n이 최대 4이므로 총 4개의 level을 다룰 수 있는 3차원 배열 선언

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

struct Node // 좌표와 폭발 세기 저장
{
    int y, x;
    int power;
};

queue<Node> q;
int mini = 21e8;

void gravity(int lev) // 중력 작용(아래에 0이 있으면 내려줌)
{
    for (int x = 0; x < w; x++)
    {
        int y_change = h - 1;
        for (int y = h - 1; y >= 0; y--)
        {
            if (arr_copy[lev][y][x] != 0)
            {
                int temp = arr_copy[lev][y][x];
                arr_copy[lev][y][x] = arr_copy[lev][y_change][x];
                arr_copy[lev][y_change][x] = temp;
                y_change--;
            }
        }
    }
}

int check(int y0, int x0, int lev)  // level별 boom을 진행해 주기 위한 함수
{
    if (lev == 0)
    {
        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
        // level 0일 때, 시작은 항상 초기 입력 배열로 초기화
                arr_copy[0][y][x] = arr[y][x];
            }
        }
    }
    else
    {
        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
        // 시작은 항상 이전 level의 값에서 시작하므로, 이전 level 배열 값으로 초기화
                arr_copy[lev][y][x] = arr_copy[lev - 1][y][x];
            }
        }
    }

  // BFS 진행
    q.push({ y0, x0, arr_copy[lev][y0][x0] });
    arr_copy[lev][y0][x0] = 0;

while (!q.empty())
{
    Node now = q.front();
    q.pop();

    for (int i = 1; i < now.power; i++) // 해당 좌표의 power만큼의 상하좌우 범위로 boom
    {
        for (int j = 0; j < 4; j++)
        {
            int ny = now.y + dy[j] * i;
            int nx = now.x + dx[j] * i;

            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (arr_copy[lev][ny][nx] == 0) continue;
            if (arr_copy[lev][ny][nx] == 1)
            {
      // 좌표의 값이 1인 경우, 상하좌우 퍼지지 않고 해당 좌표만 터지므로, queue에 push할 필요 없다.
                arr_copy[lev][ny][nx] = 0;
                continue;
            }

            q.push({ ny, nx, arr_copy[lev][ny][nx] });
            arr_copy[lev][ny][nx] = 0;
        }
    }
}
  // 더이상 터트릴 필요 없을 때, 남은 벽돌 수 count
    if (lev + 1 == n)
    {
        int cnt = 0;
        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                if (arr_copy[lev][y][x] != 0) cnt++;
            }
        }

    return cnt;
}
  // 터트린 후 중력 작용
    gravity(lev);

int flag = 0;

for (int x = 0; x < w; x++)
{
    for (int y = 0; y < h; y++)
    {
        if (arr_copy[lev][y][x] != 0) // 좌표값이 0이라면 터트릴 필요 x
        {
            int ret = check(y, x, lev + 1);
            
     // 벽돌이 최소로 남을 때의 벽돌 수 계산
     // 최대 level이 아닌 경우도 ret으로 들어오지만, 최대 level의 최솟값보다는 작아질 수 없다.
    if (ret < mini) mini = ret;

    // 터트릴 것이 없을 때를 대비해 flag 설정
    // 해당 단계에서 모두 터져 0이 되면, ret 값이 계산되지 않음을 방지
            flag = 1;
            break;
        }
    }
}
  // level이 최대로 가기 전에 모두 터진다면 0을 반환
    if (flag == 0) return 0;

return mini;
}

int main()
{
    int test;
    cin >> test;

    for (int t = 1; t <= test; t++)
    {
        cin >> n >> w >> h;
        mini = 21e8;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            cin >> arr[y][x];
            arr_copy[0][y][x] = arr[y][x];
        }
    }

    int ans = 21e8;

// 가장 위의 벽돌을 터트릴 수 있으므로, 모든 열에서 좌표값이 0이 아닌 가장 작은 열을 check해야 한다.
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            if (arr[y][x] != 0)
            {
                int ret = check(y, x, 0);
                if (ret < ans) ans = ret;
                break;
            }
        }
    }

    cout << "#" << t << " " << ans << "\n";
}

return 0;
}