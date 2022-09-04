#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Node
{
    int y, x;
};

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            int cnt = 0;
            if (picture[y][x] != 0)
            {
                queue<Node> q;

                q.push({y, x});
                int check = picture[y][x];  // 확인해야할 색상 값 저장

                picture[y][x] = 0;  // 함몰시키기

                while (!q.empty())
                {
                    Node now = q.front();
                    q.pop();
                    cnt++;  // 영역 크기 계산

                    for (int i = 0; i < 4; i++)
                    {
                        int ny = now.y + dy[i];
                        int nx = now.x + dx[i];
                        if (ny < 0 || nx < 0 || ny >= m || nx >= n)
                            continue;
                        if (picture[ny][nx] != check)   // 같은 색상일때만 pass
                            continue;

                        picture[ny][nx] = 0;
                        q.push({ny, nx});
                    }
                }

                number_of_area++;   // 영역의 수 계산

                if (cnt > max_size_of_one_area) // 가장 큰 영역의 크기 계산
                    max_size_of_one_area = cnt;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}