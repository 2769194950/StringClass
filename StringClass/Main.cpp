#include <iostream>
#include "String.h"
using namespace std;

String testString(const char* c = nullptr)
{
    try
    {
        return String(c);
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "内存申请失败:" << e.what() << std::endl;
    }
}

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
void testFind1(String& string, const char& goal, const int& pos = 0) {
    int result = string.Find(goal, pos);
    cout << "从位置 " << pos << " 开始查找字符 '" << goal << "'，";
    if (result != -1) {
        cout << "首次出现的位置是：" << result << endl;
    }
    else {
        cout << "未找到字符 '" << goal << "'" << endl;
    }
}
void testFindFinally(String& string, const char& goal, const int& pos = 0) {
    int result = string.FindFinally(goal, pos);
    cout << "从位置 " << pos << " 开始查找字符 '" << goal << "'，";
    if (result != -1) {
        cout << "最后一次出现的位置是：" << result << endl;
    }
    else {
        cout << "未找到字符 '" << goal << "'" << endl;
    }
}
void testFind2(String& string, const String& goal, const int& pos = 0) {
    int result = string.Find(goal, pos);
    cout << "从位置 " << pos << " 开始查找字符串 \"" << goal << "\"，";
    if (result != -1) {
        cout << "首次出现的位置是：" << result << endl;
    }
    else {
        cout << "未找到字符串 \"" << goal << "\"" << endl;
    }
}
void testReplace(String& str, const int& pos, const char& goal)
{
    try
    {
        str.Replace(pos, goal);
    }
    catch (const out_of_range& e)
    {
        cerr << "Exception:" << e.what() << endl;
    }
}
void testReplace(String& str, const int& pos, const String& goal)
{
    try
    {
        str.Replace(pos, goal);
    }
    catch (const out_of_range& e)
    {
        cerr << "Exception:" << e.what() << endl;
    }
}

void testYYF() {
    cout << "==============================================================" << endl;
    String string1 = testString("abc");
    cout << "1 测试两种插入功能：" << endl;
    cout << "1.1 void Insert(const int& pos, const char& goal);" << endl;
    cout << "将A插入到位置1处" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    testInsert1(string1, 1, 'A');
    cout << string1;
    cout << endl << endl;

    String string2 = testString("abc");
    cout << "1.2 void Insert(const int& pos, const String& goal);" << endl;
    cout << "将12插入到位置1处" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    testInsert2(string2, 1, "12");
    cout << string2;
    cout << endl << endl;

    cout << "异常处理展示:" << endl;
    String string3 = testString("abc");
    cout << "将A插入到abc的位置4处（产生越界）" << endl;
    testInsert1(string3, 4, 'A');
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t" << string3 << endl;

    cout << "==============================================================" << endl;

    String string4 = testString("abcabc");
    cout << "2. 测试查找字符：" << endl;
    cout << "2.1 int Find(const char& goal, const int& pos = 0);" << endl;
    cout << "在 abcabc 中查找字符 'b'" << endl;
    testFind1(string4, 'b', 0);
    cout << endl;

    cout << "2.2 int FindFinally(const char& goal, const int& pos = 0);" << endl;
    cout << "在 abcabc 中查找字符 'b'，从最后开始查找" << endl;
    testFindFinally(string4, 'b', 0);
    cout << endl;

    String substring = testString("ab");
    cout << "2.3 int Find(const String& goal, const int& pos = 0);" << endl;
    cout << "在 abcabc 中查找字符串 \"ab\"" << endl;
    testFind2(string4, substring, 0);

    cout << "==============================================================" << endl;

    String string5 = testString("abc");
    cout << "3 测试两种替换功能：" << endl;
    cout << "3.1 void Replace(const int& pos, const char& goal);" << endl;
    cout << "将A与位置1处字符替换" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    string5.Replace(1, 'A');
    cout << string5;
    cout << endl << endl;

    String string6 = testString("abc");
    cout << "3.2 void Replace(const int& pos, const String& goal);" << endl;
    cout << "将12从位置1处开始替换" << endl;
    cout << "原字符串\tabc" << endl;
    cout << "现字符串\t";
    string6.Replace(1, "12");
    cout << string2;
    cout << endl << endl;

    cout << "异常处理展示:" << endl;
    String string7 = testString("abc");
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
    String string8 = testString("abc");
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

    String str1 = testString("abcde");
    cout << "1.1void Delete(const int& pos)" << endl;
    cout << "删除下标2对应字符" << endl;
    cout << "原字符串:\t" << str1 << endl;
    testDelete1(str1, 2);
    cout << "现字符串:\t" << str1 << endl;
    cout << endl;

    String str2 = testString("abcdefj");
    cout << "1.2void Delete(const int& pos, const char& goal)" << endl;
    cout << "删除下标1后'c’字符" << endl;
    cout << "原字符串:\t" << str2 << endl;
    testDelete2(str2, 1, 'c');
    cout << "现字符串:\t" << str2 << endl;
    cout << endl;

    String str3 = testString("abcdefj");
    cout << "1.3void Delete(const int& pos, const String& goal)" << endl;
    cout << "删除下标1后‘cd'字符串" << endl;
    String goal("cd");
    cout << "原字符串:\t" << str3 << endl;
    testDelete3(str3, 1, goal);
    cout << "现字符串:\t" << str3 << endl;
    cout << endl;

    String str4 = testString("abcde");
    cout << "异常处理展示" << endl;
    cout << "删除下标1后'd'字符" << endl;
    cout << "原字符串:\t" << str4 << endl;
    testDelete2(str4, 1, 'd');
    cout << "现字符串:\t" << str4 << endl;


}

void testStrncpy(String& str, const String& copy, const int& n)
{
    try
    {
        str.Strncpy(copy, n);
    }
    catch (const invalid_argument& e)
    {
        cerr << "Exception:" << e.what() << endl;
    }
}
void testStrnCat(String& str, const String& s,const int& n)
{
    try
    {
        str.StrnCat(s, n);
    }
    catch (const out_of_range& e)
    {
        cerr << "Exception:" << e.what() << endl;
    }
}
void testSubStr(String& str, const int& pos, const int& n)
{
    try
    {
        String temp;
        temp = str.SubStr(pos, n);
        cout << "返回字符串:" << temp << endl;
    }
    catch (const out_of_range& e)
    {
        cerr << "Exception:" << e.what() << endl;
    }
}
void testTo_int(const String& str)
{
    try
    {
        cout << "数字为:" << str.To_int() << endl;
    }
    catch (const invalid_argument& e)
    {
        cerr << "Exception:" << e.what() << endl;
    }
}

void testLRC()
{
    cout << "==============================================================" << endl;
    cout << "测试一些简单功能" << endl;
    cout << endl;

    String str1("12345");
    String copy("A123");
    cout << "原字符串:" << str1 << endl;
    cout << "待拷贝字符串:" << copy << endl;
    testStrncpy(str1, copy, 3);
    cout << "现字符串:" << str1 << endl;
    cout << endl;

    String str2("2345");
    String target("ABCD");
    cout << "原字符串:" << str2 << endl;
    cout << "待拷贝字符串:" << target << endl;
    testStrnCat(str2, target, 3);
    cout << "现字符串:" << str2 << endl;
    cout << endl;   

    String str3("159");
    cout << "原字符串:" << str3 << endl;
    testSubStr(str3, 2, 1);
    cout << endl;

    String str4("15973");
    cout << "原字符串:" << str4 << endl;
    testTo_int(str4);
    cout << endl;

    String testStr("1594");
    cout << "异常处理展示" << endl;
    testSubStr(testStr, 9, 1);
}

String Function()
{
    String str1("abcd");
    String str2("bcd");
    return str1;
}

void DeleteMenu(String& s)
{
    cout << "1---删除对应下标的字符" << endl;
    cout << "2---删除对应下标后的字符串" << endl;
    cout << endl;
    String deSec;
    String goal;
    int pos;
    cin >> deSec;
    while (deSec[1] !=NULL)
    {
        cout << "错误输入，请重试！" << endl;
        cin >> deSec;
    }
    switch (deSec[0])
    {
    case '1':
        cout << "请输入对应下标：";
        cin >> pos;
        testDelete1(s, pos);
        cout << "修改后字符串:" << s << endl;
        break;
    case '2':
        cout << "请输入对应下标：";
        cin >> pos;
        cout << "请输入对应的字符串：";
        cin >> goal;
        testDelete3(s, pos, goal);
        cout << "修改后字符串:" << s << endl;
        break;
    default:
        cout << "输入错误" << endl;
        break;
    }
}

void InsertMenu(String& s)
{
    cout << "1---在对应下标处插入字符" << endl;
    cout << "2---在对应下标处插入字符串" << endl;
    cout << endl;
    String inSec;
    String target1;
    int pos;
    cin >> inSec;
    while (inSec[1] != NULL)
    {
        cout << "错误输入，请重试！" << endl;
        cin >> inSec;
    }
    switch (inSec[0])
    {
    case '1':
        cout << "请输入下标:" << endl;
        cin >> pos;
        char target;
        cout << "请输入插入的字符;" << endl;
        cin >> target;
        testInsert1(s, pos, target);
        cout << "现字符串:" << s << endl;
        break;
    case '2':
        cout << "请输入下标:" << endl;
        cin >> pos;
        cout << "请输入插入的字符串;" << endl;
        cin >> target1;
        testInsert2(s, pos, target1);
        cout << "现字符串:" << s << endl;
        break;
    default:
        break;
    }
}

void FindMenu(String& s)
{
    cout << "1---查找字符第一次出现并返回对应的下标" << endl;
    cout << "2---查找字符最后一次出现并返回对应的下标" << endl;
    cout << "3---查找相应字符串并返回其首字符的下标" << endl;
    cout << endl;
    String fiSec;
    char goal;
    String target;
    int pos;
    cin >> fiSec;
    while (fiSec[1] != NULL)
    {
        cout << "错误输入，请重试！" << endl;
        cin >> fiSec;
    }
    switch (fiSec[0])
    {
    case '1':
        cout << "请输入查找的字符:" << endl;
        cin >> goal;
        testFind1(s, goal);
        break;
    case '2':
        cout << "请输入查找的字符:" << endl;
        cin >> goal;
        testFindFinally(s, goal);
        break;
    case '3':
        cout << "请输入查找的字符串:" << endl;
        cin >> target;
        testFind2(s, target);
        break;
    default:
        break;
    }
}

void ReplaceMenu(String& s)
{
    cout << "1---替换下标对应的字符" << endl;
    cout << "2---替换下标后(包含下标)的字符串" << endl;
    cout << endl;
    String reSec;
    int pos;
    char goal;
    String target;
    cin >> reSec;
    while (reSec[1] != NULL)
    {
        cout << "错误输入，请重试！" << endl;
        cin >> reSec;
    }
    switch (reSec[0])
    {
    case '1':
        cout << "请输入对应的下标:" << endl;
        cin >> pos;
        cout << "请输入对应的字符:" << endl;
        cin >> goal;
        testReplace(s, pos, goal);
        cout << "现字符串:" << s << endl;
        break;
    case '2':
        cout << "请输入对应的下标:" << endl;
        cin >> pos;
        cout << "请输入对应的字符串" << endl;
        cin >> target;
        testReplace(s, pos, target);
        cout << "现字符串:" << s << endl;
        break;
    default:
        break;
    }
}

void CompareMenu(String& s)
{
    cout << "请输入待比较字符串:" << endl;
    String temp;
    cin >> temp;
    cout << endl;

    cout << "开始比较---" << endl;
    if (s > temp)
    {
        cout << "本串大于待比较字符串" << endl;
    }
    else if (s == temp)
    {
        cout << "本串等于待比较字符串" << endl;
    }
    else
    {
        cout << "本串小于待比较字符串" << endl;
    }
}

void OperatorMenu(String& s)
{
    cout << "1---与字符进行相加" << endl;
    cout << "2---与字符串进行相加" << endl;
    cout << endl;
    String opSec;
    cin >> opSec;
    char goal;
    String target;
    while (opSec[1] != NULL)
    {
        cout << "错误输入，请重试！" << endl;
        cin >> opSec;
    }
    switch (opSec[0])
    {
    case '1':
        cout << "请输入待加字符:" << endl;
        cin >> goal;
        cout << "结果为:" << s + goal << endl;
        break;
    case '2':
        cout << "请输入待加字符串:" << endl;
        cin >> target;
        cout << "结果为:" << s + target << endl;
        break;
    default:
        break;
    }
}

int main()
{
    //testYYF();
    //testWYT();
    //testLRC();
    
    //system("pause");

    cout << "请输入你的初始字符串:";
    String s;
    cin >> s;
    cout << endl;

    String select;
	while (true)
	{
		cout << "----String操作面板----" << endl;
		cout << "1-----对字符串进行删除" << endl;
        cout << "2-----对字符串进行插入" << endl;
        cout << "3-----对字符串进行查找" << endl;
        cout << "4-----对字符串进行替换" << endl;
        cout << "5-----对字符串进行比较" << endl;
        cout << "6-----对字符串进行运算" << endl;
        cout << endl;

        cin >> select;
        while (select[1] != NULL)
        {
            cout << "错误输入，请重试！" << endl;
            cin >> select;
        }
        switch (select[0])
        {
        case '1':
            DeleteMenu(s);
            cout << endl;
            break;
        case '2':
            InsertMenu(s);
            cout << endl;
            break;
        case '3':
            FindMenu(s);
            cout << endl;
            break;
        case '4':
            ReplaceMenu(s);
            cout << endl;
            break;
        case '5':
            CompareMenu(s);
            cout << endl;
            break;
        case '6':
            OperatorMenu(s);
            cout << endl;
            break;
        default:
            break;
        }
	}
}