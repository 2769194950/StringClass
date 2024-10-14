#include "String.h"


//���캯��
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

//��������
String::String(const String& s)
{
	length = s.length;
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = s.str[i];
	}
}

//��ֵ����
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

//��������
String::~String()
{
	delete[] str;
}

void String::Strncpy(const String& copy, const int& n)
{
    length = n;
    if (n < 0)
    {
        throw invalid_argument("n������������");
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
        throw out_of_range("Ŀ���ַ������Ȳ���");
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
        throw out_of_range("pos������Χ");
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
}//������

int String::To_int() const
{
    int result = 0;
    for (int i = 0; i < this->length; ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            throw invalid_argument("���ַ������ڷ������ַ���");
        }
        for (int i = 0; i < this->length; ++i)
        {
            result = result * 10 + (str[i] - '0');
        }
        return result;
    }
}

//ɾ���ַ�(��)
void String::Delete(const int& pos)
{
	if (length == 0)//��ѯ������ɾ�ַ�
	{
		throw - 1;
		
	}
	int i = 0;
    char* newStr = new char[length - 1];//�½���Դ�ռ�
    for ( i ; i < pos; i++)
    {
        newStr[i] = str[i];
    }
	for ( i = pos; i < length - 1; i++)//�տ���ɾ���ַ�
	{
        newStr[i] = str[i + 1];
	}
	length = length - 1;
    delete[]str;//ɾ��ԭ����Դ�ռ�
    str = newStr;//�����µ���Դ�ռ�

}

void String::Delete(const int& pos, const char& goal)
{
	if (length == 0 || pos == length ||length == 1)//��ѯ������ɾ�ַ�
	{
		throw -1;
		
	}
	if (str[pos+1] != goal)//��ɾ�ַ���Ŀ���ַ���ͬ
	{
		throw 'e';
        
	}
	Delete(pos + 1);
	
}

void String::Delete(const int& pos, const String& goal)
{
	if ((length-1-pos) < goal.GetLen())//��ѯ�����㹻�Ĵ�ɾ�ַ�
	{
		throw -1;
		
	}
	int flag = 0, i, j = 0;
	for ( i = pos+1; i < pos+1+goal.GetLen(); i++)//��ɾ��������Ŀ�괮��ͬ
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

//�����ַ�(��)
void String::Insert(const int &pos, const char &goal) {
    // �׳��쳣
    if (pos < 0 || pos > length) {
        throw out_of_range("����λ�ò��ڷ�Χ��");
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
    // �׳��쳣
    if (pos < 0 || pos > length) {
        throw out_of_range("����λ�ò��ڷ�Χ��");
    }

    int goalLength = goal.length;
    int newLength = length + goalLength;

    // �����µ�str
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

//�����ַ�(��)
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
    // KMP�㷨
    // ��һ���������ǰ׺��
    int *next = new int[goal.length];
    next[0] = 0;
    // ��׺ĩβ
    int endPostfix;
    // ǰ׺ĩβ
    int endPrefix = 0;
    for (endPostfix = 1; endPostfix < goal.length; ++endPostfix) {
        // ��ƥ��
        while (str[endPostfix] != str[endPrefix] && endPrefix > 0) {
            // ����
            endPrefix = next[endPrefix - 1];
        }
        // ƥ�� ǰ׺��׺ͬʱ����
        if (str[endPrefix] == str[endPostfix]) {
            endPrefix++;
        }
        next[endPostfix] = endPrefix; // ��j��ǰ׺�ĳ��ȣ�����next[i]
    }

    // �ڶ���������ǰ׺��ƥ���ַ���
    int j = 0;
    for (int i = pos; i < length; ++i) {
        // �����ǰû��ƥ��
        while (str[i] != goal[j] && j > 0) {
            j = next[j - 1];
        }
        // ƥ��Ļ��������Ƚ���һ���ַ�
        if (str[i] == goal[j]) {
            ++j;
        }
        // j���ߵ�goal��ĩβ��֤��ƥ�����
        if (j == goal.length) {
            delete []next;
            return (i - j + 1);
        }
    }
    delete []next;
    return -1;
}

//�滻�ַ�(��)
void String::Replace(const int &pos, const char &goal) {
    if (pos < 0 || pos >= length) {
        throw out_of_range("�滻λ�ò��ڷ�Χ��");
    }
    str[pos] = goal;
}

void String::Replace(const int &pos, const String &goal) {
    if (pos < 0 || pos > length - goal.length) {
        throw out_of_range("�滻λ�ò��ڷ�Χ��");
    }
    for (int i = pos ,j = 0; i < goal.length + pos; ++i ,++j) {
        str[i] = goal[j];
    }
}

//Ӣ�Ĵ�Сдת��
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

//������1��С����-1
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

//���������
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

// ����������Ƚ�
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

// ����������ӷ�
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

// ��Ԫ������ӷ�
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

// �����±������
char& String::operator[](int n) const
{
    return str[n];
}

