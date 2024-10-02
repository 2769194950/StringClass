#include "String.h"



String::String(const char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	length = i;
	str = new char[length];
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
	}
}

String::String(const char* s, const int& len)
{
	length = len;
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = s[i];
	}
}

String::String(const String& s)
{
	length = s.length;
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = s.str[i];
	}
}

String& String::operator=(const String& s)
{
	String x(s);
	return x;
}

int String::GetLen() const
{
	return length;
}

String::~String()
{
	delete[] str;
}

void String::Delete(const int& pos)
{
	if (length == 0)//查询不到待删字符
	{
		throw - 1;
		return;
	}
	int i = 0;
	String temp(*this);//拷贝构造
	for ( i = pos; i < length - 1; i++)//空开待删除字符
	{
		str[i] = temp[i+1];//[]运算符重载
	}
	length = length - 1;
}

void String::Delete(const int& pos, const char& goal)
{
	if (length == 0 || pos == length ||length == 1)//查询不到待删字符
	{
		throw - 1;
		return;
	}
	if (str[pos+1] != goal)//待删字符与目标字符不同
	{
		throw 'e';
		return;
	}
	Delete(pos + 1);
	
}

void String::Delete(const int& pos, const String& goal)
{
	if ((length-1-pos) < goal.GetLen())//查询不到足够的待删字符
	{
		throw - 1;
		return;
	}
	int flag = 0, i, j = 0;
	for ( i = pos+1; i < pos+1+goal.GetLen(); i++)//待删除部分与目标串不同
	{
		if (str[i] != goal[j])
		{
			flag = 1;
			throw 'e';
			break;
		}
		j++;
	}
	if (flag != 1)
	{
		for ( i = pos+1; i < pos + 1 + goal.GetLen(); i++)
		{
			Delete(i);
		}
	}

}
