#include <iostream>
using namespace std;

#include <string>

// x,y������   x>=2,y<=36
// s x��������ÿһλ�ĵ� 10~35 ��A~Z��ʾ  Ϊ�˷������
string transform(int x, int y, string s)
{
	string result = "";
	int sum = 0;

	//�Ƚ���ת������ת��Ϊʮ���Ƶ���
	for (size_t i = 0; i < s.length(); ++i)
	{
		//�����ת����Ϊ����
		if (s[i] == '-')
			continue;
		//����� i λ��ʮ���Ƶ���
		if (s[i] >= '0'&&s[i] <= '9')
		{
			sum = sum * x + s[i] - '0';
		}
		//����� i λ���������Ƶ���
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
	//С�˴洢
	cout << "x������s��Ӧ��y��������" << s << " " << x << " " << y << endl;
	cout << "���Ϊ��" << result << endl;
	return result;
}

int main()
{
	transform(10, 16, "1234");
	return 0;
}