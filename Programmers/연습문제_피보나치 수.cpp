#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long answer = 0;
    
    vector<long long> fibonacci;
    
    fibonacci.push_back(0);
    fibonacci.push_back(1);
    
    for (int i = 2; i <= n; i++)
    {
        long long sum = (fibonacci[i - 2] + fibonacci[i - 1]) % 1234567;
        fibonacci.push_back(sum);
    }
    
    answer = fibonacci[n];
    
    return answer;
}