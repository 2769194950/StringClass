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
		i++;
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
		
	}
	int i = 0;
    char* newStr = new char[length - 1];//新建资源空间
    for ( i ; i < pos; i++)
    {
        newStr[i] = str[i];
    }
	for ( i = pos; i < length - 1; i++)//空开待删除字符
	{
        newStr[i] = str[i + 1];
	}
	length = length - 1;
    delete[]str;//删除原本资源空间
    str = newStr;//链接新的资源空间

}

void String::Delete(const int& pos, const char& goal)
{
	if (length == 0 || pos == length ||length == 1)//查询不到待删字符
	{
		throw -1;
		
	}
	if (str[pos+1] != goal)//待删字符与目标字符不同
	{
		throw 'e';
        
	}
	Delete(pos + 1);
	
}

void String::Delete(const int& pos, const String& goal)
{
	if ((length-1-pos) < goal.GetLen())//查询不到足够的待删字符
	{
		throw -1;
		
	}
	int flag = 0, i, j = 0;
	for ( i = pos+1; i < pos+1+goal.GetLen(); i++)//待删除部分与目标串不同
	{
		if (str[i] != goal[j])
		{
			flag = 1;
			throw 'e';
			
		}
		j++;
	}
	if (flag != 1)
	{
		for ( i = pos+1; i < pos + 1 + goal.GetLen(); i++)
		{
			Delete(pos + 1);
		}
	}

}

char &String::operator[](int n) const {
    return str[n];
}

void String::Insert(const int &pos, const char &goal) {
    // 抛出异常
    if (pos < 0 || pos > length) {
        throw out_of_range("插入位置不在范围内");
    }

    char* newStr = new char[length + 1];
    for (int i = 0; i < pos; ++i) {
        newStr[i] = str[i];
    }
    newStr[pos] = goal;
    for (int i = pos; i < length; ++i) {
        newStr[i + 1] = str[i];
    }

    delete[] str;
    str = newStr;
    length++;
}

void String::Insert(const int &pos, const String &goal) {
    // 抛出异常
    if (pos < 0 || pos > length) {
        throw out_of_range("插入位置不在范围内");
    }

    int goalLength = goal.length;
    int newLength = length + goalLength;

    // 构建新的str
    char* newStr = new char[newLength];
    for (int i = 0; i < pos; ++i) {
        newStr[i] = str[i];
    }
    for (int i = pos, j = 0; i < pos + goalLength; ++i, ++j) {
        newStr[i] = goal[j];
    }
    for (int i = pos + goalLength, j = pos; i < newLength; ++i, ++j) {
        newStr[i] = str[j];
    }

    delete[] str;
    str = newStr;
    length = newLength;
}

int String::Find(const char &goal, const int &pos) {
    for (int i = pos; i < length; ++i) {
        if (str[i] == goal) {
            return i;
        }
    }
    return -1;
}

int String::FindFinally(const char &goal, const int &pos) {
    for (int i = length; i > pos - 1; --i) {
        if (str[i] == goal) {
            return i;
        }
    }
    return -1;
}

int String::Find(const String &goal, const int &pos) {
    // KMP算法
    // 第一步：构造出前缀表
    int *next = new int[goal.length];
    next[0] = 0;
    // 后缀末尾
    int endPostfix;
    // 前缀末尾
    int endPrefix = 0;
    for (endPostfix = 1; endPostfix < goal.length; ++endPostfix) {
        // 不匹配
        while (str[endPostfix] != str[endPrefix] && endPrefix > 0) {
            // 回退
            endPrefix = next[endPrefix - 1];
        }
        // 匹配 前缀后缀同时后移
        if (str[endPrefix] == str[endPostfix]) {
            endPrefix++;
        }
        next[endPostfix] = endPrefix; // 将j（前缀的长度）赋给next[i]
    }

    // 第二部：根据前缀表匹配字符串
    int j = 0;
    for (int i = pos; i < length; ++i) {
        // 如果当前没有匹配
        while (str[i] != goal[j] && j > 0) {
            j = next[j - 1];
        }
        // 匹配的话，继续比较下一个字符
        if (str[i] == goal[j]) {
            ++j;
        }
        // j能走到goal的末尾则证明匹配完成
        if (j == goal.length) {
            delete []next;
            return (i - j + 1);
        }
    }
    delete []next;
    return -1;
}

void String::Replace(const int &pos, const char &goal) {
    if (pos < 0 || pos >= length) {
        throw out_of_range("替换位置不在范围内");
    }
    str[pos] = goal;
}

void String::Replace(const int &pos, const String &goal) {
    if (pos < 0 || pos > length - goal.length) {
        throw out_of_range("替换位置不在范围内");
    }
    for (int i = pos ,j = 0; i < goal.length + pos; ++i ,++j) {
        str[i] = goal[j];
    }
}

String &String::Strupr() {
    for (int i = 0; i < length; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return *this;
}

String &String::Strlwr() {
    for (int i = 0; i < length; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return *this;
}

ostream &operator<<(ostream &out, const String &s) {
    for (int i = 0; i < s.length; ++i) {
        out << s[i];
    }
    return out;
}
