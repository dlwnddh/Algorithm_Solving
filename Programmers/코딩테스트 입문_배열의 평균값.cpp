#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    double sum_all = 0;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        sum_all += numbers[i];
    }
    
    answer = sum_all / (numbers.size());
    
    return answer;
}