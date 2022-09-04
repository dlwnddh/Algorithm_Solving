#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<int> ret;
    
    for (int i = 0; i < arr1.size(); i++)   // 비트 연산(OR)을 진행한 vector 생성
    {
        int a = arr1[i] | arr2[i];  // 비트 연산 OR
        ret.push_back(a);
    }
    
    for (int i = 0; i < ret.size(); i++)    // 1을 #으로, 0을 빈칸으로 변경
    {
        string str = "";
        int now = ret[i];
        for (int j = 0; j < ret.size(); j++)    // 실제 2진수 길이가 아닌 배열의 크기만큼 출력되어야 한다.
        {
            int num = 0;
            
            num = now % 2;  // 2진수로 변환하는 과정
            now /= 2;
            
            // 2진수로 처리하면서 게속 앞에 값이 쌓여야 한다.
            // stack을 사용해도 좋다.
            if (num == 0) str = " " + str;
            else str = "#" + str;
        }
        answer.push_back(str);
    }
    
    return answer;
}