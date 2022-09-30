#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;
    int cnt_zero = 0;
    
    while (s != "1")
    {
        int len = 0;
        long long temp = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1') len++;
        }
        
        cnt_zero += s.size() - len;
        
        int k = 0;
        
        while(len > 0)
        {
            int ret = len % 2;
            len /= 2;
            
            temp += ret * pow(10, k);
            k++;
        }
        
        s = to_string(temp);
        
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(cnt_zero);
    
    return answer;
}