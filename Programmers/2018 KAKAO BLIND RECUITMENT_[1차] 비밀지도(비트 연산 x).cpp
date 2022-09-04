#include <string>
#include <vector>

using namespace std;

vector<string> change(vector<int> v)    // 정수를 배열 크기에 맞춰 2진수 문자열로 변경
{
    vector<string> ans;

    for (int i = 0; i < v.size();i++)
    {
        string num_2 = "";  // 2진수 문자열을 저장한 string 변수 생성
        int num = v[i];
        int cnt = 0;
        while(cnt != v.size())  // 배열 크기에 맞추기 위해 배열 크기만큼 반복
        {
            // 그냥 2진수일 경우, 몫이 0이 되면 종료되지만, while문으로 인해 반복
            int ret = num % 2;
            num /= 2;

            string ret_string = to_string(ret);
            num_2 = ret_string + num_2;

            cnt++;
        }

        ans.push_back(num_2);
    }

    return ans;   
}

vector<string> sum(vector<string> v1, vector<string> v2)    // 두 2진수 문자열을 합
{
    vector<string> ans;

    for (int i = 0; i < v1.size();i++)
    {
        string ret = "";
        for (int x = 0; x < v1[i].length(); x++)
        {
            if (v1[i][x] == '0' && v2[i][x] == '0') ret += " "; // 두 2진수의 동일 비트가 모두 0일 경우, 빈칸
            else ret += "#";    // 하나라도 1인 경우, #
        }
        ans.push_back(ret);
    }

    return ans;   
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    vector<string> ret1 = change(arr1);
    vector<string> ret2 = change(arr2);

    answer = sum(ret1, ret2);

    return answer;
}