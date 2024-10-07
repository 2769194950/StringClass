#include <iostream>
#include "String.h"
using namespace std;

void testInsert1(String& str, int pos, const char goal) {
    try {
        str.Insert(pos, goal);
    }
    catch (const out_of_range& e) {
        cerr << "Exception: " << e.what() << endl;
    }
}
void testInsert2(String& str, int pos, const String& goal) {
    try {
        str.Insert(pos,goal);
    } catch (const out_of_range& e) {
        cerr << "Exception: " << e.what() << endl;
    }
}
void testFind1(String string, const char& goal, const int& pos = 0) {
    int result = string.Find(goal, pos);
    cout << "从位置 " << pos << " 开始查找字符 '" << goal << "'，";
    if (result != -1) {
        cout << "首次出现的位置是：" << result << endl;
    }
    else {
        cout << "未找到字符 '" << goal << "'" << endl;
    }
}
void testFindFinally(String string, const char& goal, const int& pos = 0) {
    int result = string.FindFinally(goal, pos);
    cout << "从位置 " << pos << " 开始查找字符 '" << goal << "'，";
    if (result != -1) {
        cout << "最后一次出现的位置是：" << result << endl;
    }
    else {
        cout << "未找到字符 '" << goal << "'" << endl;
    }
}
void testFind2(String string, const String& goal, const int& pos = 0) {
    int result = string.Find(goal, pos);
    cout << "从位置 " << pos << " 开始查找字符串 \"" << goal << "\"，";
    if (result != -1) {
        cout << "首次出现的位置是：" << result << endl;
    }
    else {
        cout << "未找到字符串 \"" << goal << "\"" << endl;
    }
}

void testYYF() {
    cout << "==============================================================" << endl;
    String string1("abc");
    cout << "1 测试两种插入功能：" << endl;
    cout << "1.1 void Insert(const int& pos, const char& goal);" << endl;
    cout << "将A插入到位置1处" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    testInsert1(string1, 1, 'A');
    cout << string1;
    cout << endl << endl;

    String string2("abc");
    cout << "1.2 void Insert(const int& pos, const String& goal);" << endl;
    cout << "将12插入到位置1处" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    testInsert2(string2, 1, "12");
    cout << string2;
    cout << endl << endl;

    cout << "异常处理展示:" << endl;
    String string3("abc");
    cout << "将A插入到abc的位置4处（产生越界）" << endl;
    testInsert1(string3, 4, 'A');
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t" << string3 << endl;

    cout << "==============================================================" << endl;

    String string4("abcabc");
    cout << "2. 测试查找字符：" << endl;
    cout << "2.1 int Find(const char& goal, const int& pos = 0);" << endl;
    cout << "在 abcabc 中查找字符 'b'" << endl;
    testFind1(string4, 'b', 0);
    cout << endl;

    cout << "2.2 int FindFinally(const char& goal, const int& pos = 0);" << endl;
    cout << "在 abcabc 中查找字符 'b'，从最后开始查找" << endl;
    testFindFinally(string4, 'b', 0);
    cout << endl;

    String substring("ab");
    cout << "2.3 int Find(const String& goal, const int& pos = 0);" << endl;
    cout << "在 abcabc 中查找字符串 \"ab\"" << endl;
    testFind2(string4, substring, 0);

    cout << "==============================================================" << endl;

    String string5("abc");
    cout << "3 测试两种替换功能：" << endl;
    cout << "3.1 void Replace(const int& pos, const char& goal);" << endl;
    cout << "将A与位置1处字符替换" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    string5.Replace(1, 'A');
    cout << string5;
    cout << endl << endl;

    String string6("abc");
    cout << "3.2 void Replace(const int& pos, const String& goal);" << endl;
    cout << "将12从位置1处开始替换" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    string6.Replace(1, "12");
    cout << string2;
    cout << endl << endl;

    cout << "异常处理展示:" << endl;
    String string7("abc");
    cout << "将12从位置2处开始替换（产生越界）" << endl;
    try {
        string6.Replace(2, "12");
    }
    catch (const out_of_range& e) {
        cerr << "Exception: " << e.what() << std::endl;
    }
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t" << string3 << endl;

    cout << "==============================================================" << endl;
    String string8("abc");
    cout << "4 测试大小写功能：" << endl;
    cout << "4.1 String& Strupr();" << endl;
    cout << "将字符串转化成大写" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    string8.Strupr();
    cout << string8;
    cout << endl << endl;

    cout << "4.2 String& Strlwr();" << endl;
    cout << "将字符串转化成小写" << endl;
    cout << "原字符串\tABC" << endl;
    cout << "现字符串\t";
    string8.Strlwr();
    cout << string8 << endl;
    cout << "==============================================================" << endl;

}

void testDelete1(String& str, const int& pos)//测试删除下标对应的字符
{
    try
    {
        str.Delete(pos);
    }
    catch (int)
    {
        cout << "未查询到待删字符位置" << endl;
    }
}
void testDelete2(String& str, const int& pos, const char& goal)
{
    try
    {
        str.Delete(pos, goal);
    }
    catch (int)
    {
        cout << "未查询到待删字符位置" << endl;
    }
    catch (char)
    {
        cout << "待删字符与实际字符不符" << endl;
    }
}
void testDelete3(String& str, const int& pos, const String& goal)
{
    try
    {
        str.Delete(pos, goal);
    }
    catch (int)
    {
        cout << "未查询到待删字符位置" << endl;
    }
    catch (char)
    {
        cout << "待删字符与实际字符不符" << endl;
    }
}

void testWYT()
{
    cout << "==============================================================" << endl;
    cout << "测试三种删除功能" << endl;
    cout << endl;

    String str1("abcde");
    cout << "1.1void Delete(const int& pos)" << endl;
    cout << "删除下标2对应字符" << endl;
    cout << "原字符串:\t" << str1 << endl;
    testDelete1(str1, 2);
    cout << "现字符串:\t" << str1 << endl;
    cout << endl;

    String str2("abcdefj");
    cout << "1.2void Delete(const int& pos, const char& goal)" << endl;
    cout << "删除下标1后'c’字符" << endl;
    cout << "原字符串:\t" << str2 << endl;
    testDelete2(str2, 1, 'c');
    cout << "现字符串:\t" << str2 << endl;
    cout << endl;

    String str3("abcdefj");
    cout << "1.3void Delete(const int& pos, const String& goal)" << endl;
    cout << "删除下标1后‘cd'字符串" << endl;
    String goal("cd");
    cout << "原字符串:\t" << str3 << endl;
    testDelete3(str3, 1, goal);
    cout << "现字符串:\t" << str3 << endl;
    cout << endl;

    String str4("abcde");
    cout << "异常处理展示" << endl;
    cout << "删除下标1后'd'字符" << endl;
    cout << "原字符串:\t" << str4 << endl;
    testDelete2(str4, 1, 'd');
    cout << "现字符串:\t" << str4 << endl;


}

int main()
{
    //testYYF();
    testWYT();
    
    
    //system("pause");
	/*while (true)
	{
		cout << "----String操作面板----" << endl;
		cout << "" << endl;
	}*/
}