#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_map<string, vector<string>> alert;
	unordered_map<string, int> is_alert;

	for (int i = 0; i < report.size(); i++)
	{
		int a = report[i].find(" ");
		string from = report[i].substr(0, a);
		string to = report[i].substr(a + 1, report[i].size());

		int flag = 0;

		if (alert.count(from))
		{
			vector<string> now = alert[from];
			for (int j = 0; j < now.size(); j++)
			{
				if (alert[from][j] == to)
				{
					flag = 1;
					break;
				}
			}
		}

		if (flag == 1) continue;

		alert[from].push_back(to);
		is_alert[to]++;
	}

	for (string name : id_list)
	{
		vector<string> now = alert[name];
		int cnt = 0;
		for (int j = 0; j < now.size(); j++)
		{
			if (is_alert[now[j]] >= k) cnt++;
		}
		answer.push_back(cnt);
	}
    
    return answer;
}