#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<vector<int>> pic;    // 전역변수를 별도로 설정

struct Node
{
    int y, x;
};

int FloodFill(int y, int x, int m, int n)
{
    queue<Node> q;

    q.push({y, x});
    int cnt = 0;
    int check = pic[y][x];

    pic[y][x] = 0;

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            if (pic[ny][nx] != check) continue;

            pic[ny][nx] = 0;
            q.push({ny, nx});
        }
    }

    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    pic = picture;  // 입력될 picture 값을 같은 형태의 별도 전역 변수에 입력

    for (int y = 0; y < m; y++)
    {
       for (int x = 0; x < n; x++)
       {    
           int cnt = 0;
           if (pic[y][x] != 0)
           {
               int ret = FloodFill(y, x, m, n);
               number_of_area++;

               if (ret > max_size_of_one_area) max_size_of_one_area = ret;
           }
       } 
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}