#include <iostream>
#include "String.h"
using namespace std;

bool IsSelectTrue(const String& select)
{
	if ()
	{

	}
}

int main()
{
	String select;
	while (true)
	{
		cout << "----String操作面板----" << endl;
		cout << "1-----------复制字符串" << endl;
		cout << "2-----------拼接字符串" << endl;
		cout << "3-----------字符串对比" << endl;
		cout << "4-------------插入字符" << endl;
		cout << "5-------------寻找字符" << endl;
		cout << "6-------------替换字符" << endl;
		cout << "7-------------删除字符" << endl;
		cout << "8-------------字符运算" << endl;
		cout << "----请选择进行操作----" << endl;
		cin >> select;
		if (select.GetLen() > 1)
		{
			cout << "输入错误" << endl;
			break;
		}

	}

}