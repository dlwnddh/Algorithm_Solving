#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<>());
    
    int back_number = people.size() - 1;
    
    for (int i = 0; i < people.size(); i++)
    {
        if (i > back_number) break;
        
        int sum_weight = people[i];
        
        while (1)
        {
            if (back_number == i) break;
            sum_weight += people[back_number];
            if (sum_weight > limit) break;
            back_number--;
        }
        answer++;
    }
    
    return answer;
}