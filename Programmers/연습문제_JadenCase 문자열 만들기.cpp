#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int a = 0;
    s.push_back(' ');
    
    while(1)
    {
        int b = s.find(" ", a);
        if (b == -1) break;
        
        if (a != s.size() - 1)
        {
            if (s[a] >= 'a' && s[a] <= 'z')
            {
               s[a] -= 'a' - 'A';
            }
            answer.push_back(s[a]);   
        }
        
        for (int i = a + 1; i <= b; i++)
        {
            if (i == s.size() - 1) continue;
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 'a' - 'A';
            }
            answer.push_back(s[i]);
        }
        
        a = b + 1;
    }
    
    return answer;
}