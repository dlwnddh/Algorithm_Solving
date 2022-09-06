#include <iostream>
#include <string>
using namespace std;

char map[5][5];
int dat[100] = { 0 };

string input, key;

struct Node
{
	int y, x;
};

Node find_where(char ch)
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (map[y][x] == ch) return { y, x };
		}
	}
}

void step1()
{
	int a = 0;

	while (1)
	{
		if (a == input.length()) break;

		if (a + 1 == input.length())
		{
			input.push_back('X');
		}
		else
		{
			// 1. 두 글자 분리
			string div = input.substr(a, 2);

			// 2. 같은 글자인지 확인
			if (div[0] == div[1])
			{
				if (div[0] == 'X')
				{
					div = "XQ";
					input.insert(a + 1, "Q");
				}
				else
				{
					string ret = "";
					ret.push_back(div[0]);
					ret.push_back('X');
					div = ret;
					input.insert(a + 1, "X");
				}
			}
		}

		a = a + 2;
	}
}

void step2()
{
	int a = 0;

	while (a < input.length())
	{
		string div = input.substr(a, 2);

		// 3. 암호화
		Node div0 = find_where(div[0]);
		Node div1 = find_where(div[1]);

		if (div0.y == div1.y)
		{
			if (div0.x + 1 == 5)
			{
				input[a] = map[div0.y][0];
			}
			else
			{
				input[a] = map[div0.y][div0.x + 1];
			}

			if (div1.x + 1 == 5)
			{
				input[a + 1] = map[div1.y][0];
			}
			else
			{
				input[a + 1] = map[div1.y][div1.x + 1];
			}
		}
		else if (div0.x == div1.x)
		{
			if (div0.y + 1 == 5)
			{
				input[a] = map[0][div0.x];
			}
			else
			{
				input[a] = map[div0.y + 1][div0.x];
			}

			if (div1.y + 1 == 5)
			{
				input[a + 1] = map[0][div1.x];
			}
			else
			{
				input[a + 1] = map[div1.y + 1][div1.x];
			}
		}
		else
		{
			input[a] = map[div0.y][div1.x];
			input[a + 1] = map[div1.y][div0.x];
		}

		a = a + 2;
	}
}

int main()
{
	cin >> input >> key;

	int x0 = 0;
	int y0 = 0;

	for (int i = 0; i < key.length(); i++)
	{
		char tar = key[i];
		if (dat[tar] == 1) continue;
		dat[tar]++;
		map[y0][x0] = tar;

		if (x0 == 4)
		{
			x0 = 0;
			y0++;
		}
		else
		{
			x0++;
		}
	}

	int start = 'A';
	dat['J'] = 1;

	for (int y = 0; y < 5; y++)
	{
		if (y < y0) continue;
		for (int x = 0; x < 5; x++)
		{
			if (y == y0 && x < x0) continue;
			while (dat[start] == 1)
			{
				start++;
			}

			map[y][x] = start;
			start++;
		}
	}

	step1();
	step2();

	cout << input;

	return 0;
}