#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    vector<int> prime_number;
    unordered_map<int, int> um;
    
    for (int i = 2; i <= 100; i++)
    {
        int flag = 0;
        
        for (int j = 2; j < i; j++)
        {
            if (j % i == 0) flag = 1;
        }
        
        if (flag == 0)
        {
            prime_number.push_back(i);
            um[i] = 0;
        }
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < prime_number.size(); j++)
        {
            if (arr[i] % prime_number[j] != 0) continue;
            
            int cnt = 0;
            
            while (arr[i] % prime_number[j] == 0)
            {
                arr[i] /= prime_number[j];
                cnt++;
            }
            
            if (cnt > um[prime_number[j]]) um[prime_number[j]] = cnt;
            
            if (arr[i] == 1) break;
        }
    }
    
    for (int i = 0; i < prime_number.size(); i++)
    {
        if (um[prime_number[i]] == 0) continue;
        
        answer *= pow(prime_number[i], um[prime_number[i]]);
    }
    
    return answer;
}