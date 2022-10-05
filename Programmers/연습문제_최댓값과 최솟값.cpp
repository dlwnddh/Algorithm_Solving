#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    
    s.push_back(' ');
    int a = 0;
    
    while(1)
    {
        int b = s.find(" ", a);
        if (b == -1) break;
        
        string str = s.substr(a, b - a);
        int temp = stoi(str);
        
        v.push_back(temp);
        
        a = b + 1;
    }
    
    sort(v.begin(), v.end());
    
    int min_i = v[0];
    int max_i = v[v.size() - 1];
    
    string min_s = to_string(min_i);
    string max_s = to_string(max_i);
    
    answer = min_s + " " + max_s;
    
    return answer;
}