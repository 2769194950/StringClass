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

char &String::operator[](int n) const {
    return str[n];
}

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
