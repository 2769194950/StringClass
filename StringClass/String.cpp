#include "String.h"


//构造函数
String::String(const char* s)
{
    if (s == NULL)
    {
        length = 0;
        str = NULL;
        return;
    }
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

//拷贝构造
String::String(const String& s)
{
	length = s.length;
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = s.str[i];
	}
}

//赋值运算
String& String::operator=(const String& s)
{
    /*if (*this == s)
    {
        return *this;
    }*/
    delete[] str;
    length = s.length;
    str = new char[length];
    for (int i = 0; i < length; i++)
    {
        str[i] = s.str[i];
    }
    return *this;
}

int String::GetLen() const
{
	return length;
}

//析构函数
String::~String()
{
	delete[] str;
}

void String::Strncpy(const String& copy, const int& n)
{
    length = n;
    if (n < 0)
    {
        throw invalid_argument("n必须是正整数");
    }
    if (n > copy.GetLen())
    {
        length = copy.GetLen();
    }
    delete[] str;
    str = new char[length];
    for (int i = 0; i < n; i++)
    {
        str[i] = copy.str[i];
    }
}
void String::StrCat(const String& s) 
{
    String temp;
    temp = *this;
    length = length + s.length;
    delete str;
    str = new char[length];
    int i = 0;
    for ( i ; i < temp.length; i++)
    {
        str[i] = temp[i];
    }
    int j = 0;
    for ( i ; i < length; i++)
    {
        str[i] = s[j];
        j++;
    }
    
}

void String::StrnCat(const String& s, const int& n)
{
    if (s.length < n)
    {
        throw out_of_range("目标字符串长度不足");
    }
    String temp;
    temp.length = n;
    temp.str = new char[n];
    int i = 0;
    for ( i ; i < n; i++)
    {
        temp[i] = s[i];
    }
    this->StrCat(temp);
    
}

String String::SubStr(const int& pos, const int& n)
{
    String result;
    result.length = n;
    if (pos < 0 || pos > this->length)
    {
        throw out_of_range("pos超出范围");
    }
    if (pos + n > this->length)
    {
        result.length = this->length - pos - 1;
    }
    result.str = new char[result.length];
    int j = 0;
    for (int i = pos; i <= pos + result.length - 1; ++i)
    {
        result[j] = str[i];
        j++;
    }
    return result;
}//有问题

int String::To_int() const
{
    int result = 0;
    for (int i = 0; i < this->length; ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            throw invalid_argument("该字符串存在非数字字符！");
        }
        for (int i = 0; i < this->length; ++i)
        {
            result = result * 10 + (str[i] - '0');
        }
        return result;
    }
}

//删除字符(串)
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

//插入字符(串)
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

//查找字符(串)
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

//替换字符(串)
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

//英文大小写转化
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

//大于是1，小于是-1
int String::Compare(const String& s) const
{
    int minLength = (length > s.length ? s.length : length);
    for (int i = 0; i < minLength; i++)
    {
        if (str[i] < s.str[i])
            return -1;
        else if (str[i] > s.str[i])
            return 1;
    }
    if (length > s.length)
    {
        return 1;
    }
    if (length == s.length)
    {
        return 0;
    }
    return -1;
}

//运算符重载
ostream& operator<<(ostream& out, const String& s) {
    for (int i = 0; i < s.length; ++i)
    {
        out << s.str[i];
    }
    return out;
}

istream& operator>>(istream& in, String& s)
{
    delete s.str;
    s.str = new char[256];
    in >> s.str;
    int i = 0;
    while (s.str[i] != NULL)
    {
        i++;
    }
    s.length = i;
    return in;
}

// 重载运算符比较
bool String::operator>(const String& s) const {
    return (Compare(s) == 1) ? 1 : 0;
}

bool String::operator<(const String& s) const {
    return (Compare(s) == -1) ? 1 : 0;
}

bool String::operator==(const String& s) const {
    return !Compare(s) ? 1 : 0;
}

bool String::operator!=(const String& s) const {
    return !(*this == s);
}

bool String::operator>=(const String& s) const {
    return !(*this < s);
}

bool String::operator<=(const String& s) const {
    return !(*this > s);
}

// 重载运算符加法
String String::operator+(const String& s) {
    int i;
    String newStr;
    newStr.str = new char[length + s.length];
    newStr.length = length + s.length;
    for (i = 0; i < length; i++)
    {
        newStr.str[i] = str[i];
    }
    for (i = 0; i < s.length; i++)
    {
        newStr.str[length + i] = s.str[i];
    }
    return newStr;
}

String String::operator+(const char& c) {
    int i;
    String newStr;
    newStr.str = new char[length + 1];
    newStr.length = length + 1;
    for (i = 0; i < length; i++)
    {
        newStr.str[i] = str[i];
    }
    newStr[length] = c;
    return newStr;
}

// 友元运算符加法
String operator+(const char& c, const String& s)
{
    int i;
    String newStr;
    newStr.str = new char[s.length + 1];
    newStr.length = s.length + 1;
    newStr[0] = c;
    for (i = 1; i < s.length + 1; i++)
    {
        newStr.str[i] = s.str[i];
    }
    return newStr;

}

// 重载下标运算符
char& String::operator[](int n) const
{
    return str[n];
}

