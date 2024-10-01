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

int String::GetLen()
{
	return length;
}

String::~String()
{
	delete[] str;
}

