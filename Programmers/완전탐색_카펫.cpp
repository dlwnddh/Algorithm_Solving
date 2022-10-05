#include <string>
#include <vector>

using namespace std;

// x * y == (brown + yellow)
// (x - 2) * (y - 2) == yelow
// x >= y

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int x, y;
    
    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i != 0) continue;
        y = i;
        x = yellow / i;
        
        if((x + 2) * (y + 2) == (brown + yellow)) break;
    }
    
    answer.push_back(x + 2);
    answer.push_back(y + 2);
    
    return answer;
}