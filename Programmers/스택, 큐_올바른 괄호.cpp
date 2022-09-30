#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    queue<char> q;
    for (int i = 0; i < s.size(); i++)
    {
        q.push(s[i]);
    }
    
    int cnt = 0;
    
    while(!q.empty())
    {
        char now = q.front();
        q.pop();
        
        if (now == ')') cnt--;
        else cnt++;
        
        if (cnt < 0) return false;
    }
    
    if (cnt != 0) answer = false;

    return answer;
}