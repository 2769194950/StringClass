#pragma once
#include <iostream>
using namespace std;

class String
{
public:
	//构造函数
	//c字符串构造函数
	String(const char* s = NULL);

	String(const char* s, const int& len);
	
	//深拷贝构造
	String(const String& s);

	//深赋值运算
	String& operator=(const String& s);

	int GetLen() const;//获取串长度

	//*************************************************************************************************林容昌
	void Strncpy(const String& copy, const int& n);//复制前n个数，不足复制原串

	void StrCat(const String& s) ; //本串与输入串拼接
	void StrnCat(const String& s, const int& n);//输入串前n个数拼接到前串

	String SubStr(const int& pos, const int& n);//返回从下标pos后n个数的串，若剩余不足n个，则全部返回，注意访问超出的异常处理

	int Compare(const String& s) const;//大于返回1，小于返回-1，等于返回0

	int To_int() const;//将0-9字符转化为数字，注意判断是不是只含0-9
	//*************************************************************************************************杨一帆
	void Insert(const int& pos, const char& goal);//将目标字符插入到下标pos，注意原串为空和pos为length的异常处理
	void Insert(const int& pos, const String& goal);

    // pos越界也均返回-1
	int Find(const char& goal, const int& pos = 0);//从pos开始查找，返回第一次出现goal的下标 未找到则返回-1
	int FindFinally(const char& goal, const int& pos = 0);//从pos开始查找，返回最后一次出现goal的下标
	int Find(const String& goal, const int& pos = 0);//查找第一次出现goal，返回对应goal首字符的小标

	void Replace(const int& pos, const char& goal);//替换下标字符
	void Replace(const int& pos, const String& goal);//替换下标后的goal.length个字符，注意异常处理

	String& Strupr();//英文小写转大写
	String& Strlwr();//英文大写转小写

	//*************************************************************************************************王永涛
	void Delete(const int& pos);//删除下标对应的字符，注意原串为空的异常处理
	void Delete(const int& pos, const char& goal);//注意pos下标后是否与待删除相同以及原串为空，pos为length的异常处理
	void Delete(const int& pos, const String& goal);


	//*************************************************************************************************杨弘毅
	//抽取和插入运算符重载
	friend ostream& operator<< (ostream& out, const String& s);
	friend istream& operator>> (istream& in, String& s);

	//重载运算符
	bool operator> (const String& s) const;
	bool operator< (const String& s) const;
	bool operator== (const String& s) const;
	bool operator!= (const String& s) const;
	bool operator>= (const String& s) const;
	bool operator<= (const String& s) const;

	String operator+ (const String& s);//String+String
	String operator+ (const char& s);//String+char
	friend String operator+ (const char &c,const String &s);//char+String
	
	//下标运算符
	char& operator[] (int n) const;//注意对超出访问进行异常处理
	//析构函数
	~String();

private:
	int length;
	char* str;
};

