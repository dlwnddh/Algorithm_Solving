#include <string>
#include <vector>

using namespace std;

int count_1(int x)
{
    int cnt = 0;
    int a = 1;
    
    while(a < x)
    {
        if(x & a) cnt++;
        a <<= 1;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int num = count_1(n);
    
    while(1)
    {
        n++;
        int temp = count_1(n);
        if (num == temp) break;
    }
    
    answer = n;
    
    return answer;
}