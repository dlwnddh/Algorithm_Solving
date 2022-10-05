#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int temp = 0;
    int j = 1;
    
    for (int i = 1; i <= n; i++)
    {
        temp += i;
        if (temp == n) answer++;
        while (temp > n)
        {
            temp -= j;
            if (temp == n) answer++;
            j++;
        }
    }
    
    return answer;
}