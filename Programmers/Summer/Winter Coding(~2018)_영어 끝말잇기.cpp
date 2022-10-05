#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_map<string, int> um;
    
    int cnt = 1;
    int flag = 0;
    char final;
    
    for (int i = 0; i < words.size(); i++)
    {
        string now = words[i];
        
        if((um[now] == 1 || now[0] != final) && i > 0)
        {
            answer.push_back(i % n + 1);
            answer.push_back(cnt);
            flag = 1;
            break;
        }
        um[now] = 1;
        if ((i + 1) % n == 0)cnt++;
        
        final = now[now.size() - 1];
    }
    
    if(flag == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}