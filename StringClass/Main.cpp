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
        std::cerr << "�ڴ�����ʧ��:" << e.what() << std::endl;
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
    cout << "��λ�� " << pos << " ��ʼ�����ַ� '" << goal << "'��";
    if (result != -1) {
        cout << "�״γ��ֵ�λ���ǣ�" << result << endl;
    }
    else {
        cout << "δ�ҵ��ַ� '" << goal << "'" << endl;
    }
}
void testFindFinally(String& string, const char& goal, const int& pos = 0) {
    int result = string.FindFinally(goal, pos);
    cout << "��λ�� " << pos << " ��ʼ�����ַ� '" << goal << "'��";
    if (result != -1) {
        cout << "���һ�γ��ֵ�λ���ǣ�" << result << endl;
    }
    else {
        cout << "δ�ҵ��ַ� '" << goal << "'" << endl;
    }
}
void testFind2(String& string, const String& goal, const int& pos = 0) {
    int result = string.Find(goal, pos);
    cout << "��λ�� " << pos << " ��ʼ�����ַ��� \"" << goal << "\"��";
    if (result != -1) {
        cout << "�״γ��ֵ�λ���ǣ�" << result << endl;
    }
    else {
        cout << "δ�ҵ��ַ��� \"" << goal << "\"" << endl;
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
    cout << "1 �������ֲ��빦�ܣ�" << endl;
    cout << "1.1 void Insert(const int& pos, const char& goal);" << endl;
    cout << "��A���뵽λ��1��" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    testInsert1(string1, 1, 'A');
    cout << string1;
    cout << endl << endl;

    String string2 = testString("abc");
    cout << "1.2 void Insert(const int& pos, const String& goal);" << endl;
    cout << "��12���뵽λ��1��" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    testInsert2(string2, 1, "12");
    cout << string2;
    cout << endl << endl;

    cout << "�쳣����չʾ:" << endl;
    String string3 = testString("abc");
    cout << "��A���뵽abc��λ��4��������Խ�磩" << endl;
    testInsert1(string3, 4, 'A');
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t" << string3 << endl;

    cout << "==============================================================" << endl;

    String string4 = testString("abcabc");
    cout << "2. ���Բ����ַ���" << endl;
    cout << "2.1 int Find(const char& goal, const int& pos = 0);" << endl;
    cout << "�� abcabc �в����ַ� 'b'" << endl;
    testFind1(string4, 'b', 0);
    cout << endl;

    cout << "2.2 int FindFinally(const char& goal, const int& pos = 0);" << endl;
    cout << "�� abcabc �в����ַ� 'b'�������ʼ����" << endl;
    testFindFinally(string4, 'b', 0);
    cout << endl;

    String substring = testString("ab");
    cout << "2.3 int Find(const String& goal, const int& pos = 0);" << endl;
    cout << "�� abcabc �в����ַ��� \"ab\"" << endl;
    testFind2(string4, substring, 0);

    cout << "==============================================================" << endl;

    String string5 = testString("abc");
    cout << "3 ���������滻���ܣ�" << endl;
    cout << "3.1 void Replace(const int& pos, const char& goal);" << endl;
    cout << "��A��λ��1���ַ��滻" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    string5.Replace(1, 'A');
    cout << string5;
    cout << endl << endl;

    String string6 = testString("abc");
    cout << "3.2 void Replace(const int& pos, const String& goal);" << endl;
    cout << "��12��λ��1����ʼ�滻" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    string6.Replace(1, "12");
    cout << string2;
    cout << endl << endl;

    cout << "�쳣����չʾ:" << endl;
    String string7 = testString("abc");
    cout << "��12��λ��2����ʼ�滻������Խ�磩" << endl;
    try {
        string6.Replace(2, "12");
    }
    catch (const out_of_range& e) {
        cerr << "Exception: " << e.what() << std::endl;
    }
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t" << string3 << endl;

    cout << "==============================================================" << endl;
    String string8 = testString("abc");
    cout << "4 ���Դ�Сд���ܣ�" << endl;
    cout << "4.1 String& Strupr();" << endl;
    cout << "���ַ���ת���ɴ�д" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    string8.Strupr();
    cout << string8;
    cout << endl << endl;

    cout << "4.2 String& Strlwr();" << endl;
    cout << "���ַ���ת����Сд" << endl;
    cout << "ԭ�ַ���\tABC" << endl;
    cout << "���ַ���\t";
    string8.Strlwr();
    cout << string8 << endl;
    cout << "==============================================================" << endl;

}

void testDelete1(String& str, const int& pos)//����ɾ���±��Ӧ���ַ�
{
    try
    {
        str.Delete(pos);
    }
    catch (int)
    {
        cout << "δ��ѯ����ɾ�ַ�λ��" << endl;
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
        cout << "δ��ѯ����ɾ�ַ�λ��" << endl;
    }
    catch (char)
    {
        cout << "��ɾ�ַ���ʵ���ַ�����" << endl;
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
        cout << "δ��ѯ����ɾ�ַ�λ��" << endl;
    }
    catch (char)
    {
        cout << "��ɾ�ַ���ʵ���ַ�����" << endl;
    }
}

void testWYT()
{
    cout << "==============================================================" << endl;
    cout << "��������ɾ������" << endl;
    cout << endl;

    String str1 = testString("abcde");
    cout << "1.1void Delete(const int& pos)" << endl;
    cout << "ɾ���±�2��Ӧ�ַ�" << endl;
    cout << "ԭ�ַ���:\t" << str1 << endl;
    testDelete1(str1, 2);
    cout << "���ַ���:\t" << str1 << endl;
    cout << endl;

    String str2 = testString("abcdefj");
    cout << "1.2void Delete(const int& pos, const char& goal)" << endl;
    cout << "ɾ���±�1��'c���ַ�" << endl;
    cout << "ԭ�ַ���:\t" << str2 << endl;
    testDelete2(str2, 1, 'c');
    cout << "���ַ���:\t" << str2 << endl;
    cout << endl;

    String str3 = testString("abcdefj");
    cout << "1.3void Delete(const int& pos, const String& goal)" << endl;
    cout << "ɾ���±�1��cd'�ַ���" << endl;
    String goal("cd");
    cout << "ԭ�ַ���:\t" << str3 << endl;
    testDelete3(str3, 1, goal);
    cout << "���ַ���:\t" << str3 << endl;
    cout << endl;

    String str4 = testString("abcde");
    cout << "�쳣����չʾ" << endl;
    cout << "ɾ���±�1��'d'�ַ�" << endl;
    cout << "ԭ�ַ���:\t" << str4 << endl;
    testDelete2(str4, 1, 'd');
    cout << "���ַ���:\t" << str4 << endl;


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
        cout << "�����ַ���:" << temp << endl;
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
        cout << "����Ϊ:" << str.To_int() << endl;
    }
    catch (const invalid_argument& e)
    {
        cerr << "Exception:" << e.what() << endl;
    }
}

void testLRC()
{
    cout << "==============================================================" << endl;
    cout << "����һЩ�򵥹���" << endl;
    cout << endl;

    String str1("12345");
    String copy("A123");
    cout << "ԭ�ַ���:" << str1 << endl;
    cout << "�������ַ���:" << copy << endl;
    testStrncpy(str1, copy, 3);
    cout << "���ַ���:" << str1 << endl;
    cout << endl;

    String str2("2345");
    String target("ABCD");
    cout << "ԭ�ַ���:" << str2 << endl;
    cout << "�������ַ���:" << target << endl;
    testStrnCat(str2, target, 3);
    cout << "���ַ���:" << str2 << endl;
    cout << endl;   

    String str3("159");
    cout << "ԭ�ַ���:" << str3 << endl;
    testSubStr(str3, 2, 1);
    cout << endl;

    String str4("15973");
    cout << "ԭ�ַ���:" << str4 << endl;
    testTo_int(str4);
    cout << endl;

    String testStr("1594");
    cout << "�쳣����չʾ" << endl;
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
    cout << "1---ɾ����Ӧ�±���ַ�" << endl;
    cout << "2---ɾ����Ӧ�±����ַ���" << endl;
    cout << endl;
    String deSec;
    String goal;
    int pos;
    cin >> deSec;
    while (deSec[1] !=NULL)
    {
        cout << "�������룬�����ԣ�" << endl;
        cin >> deSec;
    }
    switch (deSec[0])
    {
    case '1':
        cout << "�������Ӧ�±꣺";
        cin >> pos;
        testDelete1(s, pos);
        cout << "�޸ĺ��ַ���:" << s << endl;
        break;
    case '2':
        cout << "�������Ӧ�±꣺";
        cin >> pos;
        cout << "�������Ӧ���ַ�����";
        cin >> goal;
        testDelete3(s, pos, goal);
        cout << "�޸ĺ��ַ���:" << s << endl;
        break;
    default:
        cout << "�������" << endl;
        break;
    }
}

void InsertMenu(String& s)
{
    cout << "1---�ڶ�Ӧ�±괦�����ַ�" << endl;
    cout << "2---�ڶ�Ӧ�±괦�����ַ���" << endl;
    cout << endl;
    String inSec;
    String target1;
    int pos;
    cin >> inSec;
    while (inSec[1] != NULL)
    {
        cout << "�������룬�����ԣ�" << endl;
        cin >> inSec;
    }
    switch (inSec[0])
    {
    case '1':
        cout << "�������±�:" << endl;
        cin >> pos;
        char target;
        cout << "�����������ַ�;" << endl;
        cin >> target;
        testInsert1(s, pos, target);
        cout << "���ַ���:" << s << endl;
        break;
    case '2':
        cout << "�������±�:" << endl;
        cin >> pos;
        cout << "�����������ַ���;" << endl;
        cin >> target1;
        testInsert2(s, pos, target1);
        cout << "���ַ���:" << s << endl;
        break;
    default:
        break;
    }
}

void FindMenu(String& s)
{
    cout << "1---�����ַ���һ�γ��ֲ����ض�Ӧ���±�" << endl;
    cout << "2---�����ַ����һ�γ��ֲ����ض�Ӧ���±�" << endl;
    cout << "3---������Ӧ�ַ��������������ַ����±�" << endl;
    cout << endl;
    String fiSec;
    char goal;
    String target;
    int pos;
    cin >> fiSec;
    while (fiSec[1] != NULL)
    {
        cout << "�������룬�����ԣ�" << endl;
        cin >> fiSec;
    }
    switch (fiSec[0])
    {
    case '1':
        cout << "��������ҵ��ַ�:" << endl;
        cin >> goal;
        testFind1(s, goal);
        break;
    case '2':
        cout << "��������ҵ��ַ�:" << endl;
        cin >> goal;
        testFindFinally(s, goal);
        break;
    case '3':
        cout << "��������ҵ��ַ���:" << endl;
        cin >> target;
        testFind2(s, target);
        break;
    default:
        break;
    }
}

void ReplaceMenu(String& s)
{
    cout << "1---�滻�±��Ӧ���ַ�" << endl;
    cout << "2---�滻�±��(�����±�)���ַ���" << endl;
    cout << endl;
    String reSec;
    int pos;
    char goal;
    String target;
    cin >> reSec;
    while (reSec[1] != NULL)
    {
        cout << "�������룬�����ԣ�" << endl;
        cin >> reSec;
    }
    switch (reSec[0])
    {
    case '1':
        cout << "�������Ӧ���±�:" << endl;
        cin >> pos;
        cout << "�������Ӧ���ַ�:" << endl;
        cin >> goal;
        testReplace(s, pos, goal);
        cout << "���ַ���:" << s << endl;
        break;
    case '2':
        cout << "�������Ӧ���±�:" << endl;
        cin >> pos;
        cout << "�������Ӧ���ַ���" << endl;
        cin >> target;
        testReplace(s, pos, target);
        cout << "���ַ���:" << s << endl;
        break;
    default:
        break;
    }
}

void CompareMenu(String& s)
{
    cout << "��������Ƚ��ַ���:" << endl;
    String temp;
    cin >> temp;
    cout << endl;

    cout << "��ʼ�Ƚ�---" << endl;
    if (s > temp)
    {
        cout << "�������ڴ��Ƚ��ַ���" << endl;
    }
    else if (s == temp)
    {
        cout << "�������ڴ��Ƚ��ַ���" << endl;
    }
    else
    {
        cout << "����С�ڴ��Ƚ��ַ���" << endl;
    }
}

void OperatorMenu(String& s)
{
    cout << "1---���ַ��������" << endl;
    cout << "2---���ַ����������" << endl;
    cout << endl;
    String opSec;
    cin >> opSec;
    char goal;
    String target;
    while (opSec[1] != NULL)
    {
        cout << "�������룬�����ԣ�" << endl;
        cin >> opSec;
    }
    switch (opSec[0])
    {
    case '1':
        cout << "����������ַ�:" << endl;
        cin >> goal;
        cout << "���Ϊ:" << s + goal << endl;
        break;
    case '2':
        cout << "����������ַ���:" << endl;
        cin >> target;
        cout << "���Ϊ:" << s + target << endl;
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

    cout << "��������ĳ�ʼ�ַ���:";
    String s;
    cin >> s;
    cout << endl;

    String select;
	while (true)
	{
		cout << "----String�������----" << endl;
		cout << "1-----���ַ�������ɾ��" << endl;
        cout << "2-----���ַ������в���" << endl;
        cout << "3-----���ַ������в���" << endl;
        cout << "4-----���ַ��������滻" << endl;
        cout << "5-----���ַ������бȽ�" << endl;
        cout << "6-----���ַ�����������" << endl;
        cout << endl;

        cin >> select;
        while (select[1] != NULL)
        {
            cout << "�������룬�����ԣ�" << endl;
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