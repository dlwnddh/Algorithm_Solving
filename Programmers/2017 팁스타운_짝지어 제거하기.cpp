#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    
    if (s.size() % 2 == 1) answer = 0;
    else
    {
        stack<char> st;
        st.push(s[0]);
    
        int i = 1;
    
        while(i < s.size())
        {
            char now = st.top();
            
            if (st.empty())
            {
                st.push(s[i]);
                i++;
                continue;
            }
            
            if (s[i] == now) st.pop();
            else st.push(s[i]);
            
            i++;
        }
    
        if (st.empty()) answer = 1;
        else answer = 0;
    }
    
    return answer;
}