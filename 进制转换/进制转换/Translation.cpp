#include <iostream>
using namespace std;

#include <string>

// x,y进制数   x>=2,y<=36
// s x进制数，每一位的第 10~35 用A~Z表示  为了方便计算
string transform(int x, int y, string s)
{
	string result = "";
	int sum = 0;

	//先将待转换的数转化为十进制的数
	for (size_t i = 0; i < s.length(); ++i)
	{
		//如果待转换数为负数
		if (s[i] == '-')
			continue;
		//如果第 i 位是十进制的数
		if (s[i] >= '0'&&s[i] <= '9')
		{
			sum = sum * x + s[i] - '0';
		}
		//如果第 i 位是其他进制的数
		else
		{
			sum = sum * x + s[i] - 'A' + 10;
		}
	}
	while (sum)
	{
		char tmp = sum % y;
		sum /= y;
		if (tmp <= 9)
		{
			tmp += '0';
		}
		else
		{
			tmp = tmp - 10 + 'A';
		}
		result += tmp;
	}
	if (result.length() == 0)
		result = "0";
	if (s[0] == '-')
		result = '-' + result;
	//小端存储
	cout << "x进制数s对应的y进制数：" << s << " " << x << " " << y << endl;
	cout << "结果为：" << result << endl;
	return result;
}

int main()
{
	transform(10, 16, "1234");
	return 0;
}