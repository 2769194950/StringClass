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
    cout << "��λ�� " << pos << " ��ʼ�����ַ� '" << goal << "'��";
    if (result != -1) {
        cout << "�״γ��ֵ�λ���ǣ�" << result << endl;
    }
    else {
        cout << "δ�ҵ��ַ� '" << goal << "'" << endl;
    }
}
void testFindFinally(String string, const char& goal, const int& pos = 0) {
    int result = string.FindFinally(goal, pos);
    cout << "��λ�� " << pos << " ��ʼ�����ַ� '" << goal << "'��";
    if (result != -1) {
        cout << "���һ�γ��ֵ�λ���ǣ�" << result << endl;
    }
    else {
        cout << "δ�ҵ��ַ� '" << goal << "'" << endl;
    }
}
void testFind2(String string, const String& goal, const int& pos = 0) {
    int result = string.Find(goal, pos);
    cout << "��λ�� " << pos << " ��ʼ�����ַ��� \"" << goal << "\"��";
    if (result != -1) {
        cout << "�״γ��ֵ�λ���ǣ�" << result << endl;
    }
    else {
        cout << "δ�ҵ��ַ��� \"" << goal << "\"" << endl;
    }
}

void testYYF() {
    cout << "==============================================================" << endl;
    String string1("abc");
    cout << "1 �������ֲ��빦�ܣ�" << endl;
    cout << "1.1 void Insert(const int& pos, const char& goal);" << endl;
    cout << "��A���뵽λ��1��" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    testInsert1(string1, 1, 'A');
    cout << string1;
    cout << endl << endl;

    String string2("abc");
    cout << "1.2 void Insert(const int& pos, const String& goal);" << endl;
    cout << "��12���뵽λ��1��" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    testInsert2(string2, 1, "12");
    cout << string2;
    cout << endl << endl;

    cout << "�쳣����չʾ:" << endl;
    String string3("abc");
    cout << "��A���뵽abc��λ��4��������Խ�磩" << endl;
    testInsert1(string3, 4, 'A');
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t" << string3 << endl;

    cout << "==============================================================" << endl;

    String string4("abcabc");
    cout << "2. ���Բ����ַ���" << endl;
    cout << "2.1 int Find(const char& goal, const int& pos = 0);" << endl;
    cout << "�� abcabc �в����ַ� 'b'" << endl;
    testFind1(string4, 'b', 0);
    cout << endl;

    cout << "2.2 int FindFinally(const char& goal, const int& pos = 0);" << endl;
    cout << "�� abcabc �в����ַ� 'b'�������ʼ����" << endl;
    testFindFinally(string4, 'b', 0);
    cout << endl;

    String substring("ab");
    cout << "2.3 int Find(const String& goal, const int& pos = 0);" << endl;
    cout << "�� abcabc �в����ַ��� \"ab\"" << endl;
    testFind2(string4, substring, 0);

    cout << "==============================================================" << endl;

    String string5("abc");
    cout << "3 ���������滻���ܣ�" << endl;
    cout << "3.1 void Replace(const int& pos, const char& goal);" << endl;
    cout << "��A��λ��1���ַ��滻" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    string5.Replace(1, 'A');
    cout << string5;
    cout << endl << endl;

    String string6("abc");
    cout << "3.2 void Replace(const int& pos, const String& goal);" << endl;
    cout << "��12��λ��1����ʼ�滻" << endl;
    cout << "ԭ�ַ���\tabc" << endl;
    cout << "���ַ���\t";
    string6.Replace(1, "12");
    cout << string2;
    cout << endl << endl;

    cout << "�쳣����չʾ:" << endl;
    String string7("abc");
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
    String string8("abc");
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

    String str1("abcde");
    cout << "1.1void Delete(const int& pos)" << endl;
    cout << "ɾ���±�2��Ӧ�ַ�" << endl;
    cout << "ԭ�ַ���:\t" << str1 << endl;
    testDelete1(str1, 2);
    cout << "���ַ���:\t" << str1 << endl;
    cout << endl;

    String str2("abcdefj");
    cout << "1.2void Delete(const int& pos, const char& goal)" << endl;
    cout << "ɾ���±�1��'c���ַ�" << endl;
    cout << "ԭ�ַ���:\t" << str2 << endl;
    testDelete2(str2, 1, 'c');
    cout << "���ַ���:\t" << str2 << endl;
    cout << endl;

    String str3("abcdefj");
    cout << "1.3void Delete(const int& pos, const String& goal)" << endl;
    cout << "ɾ���±�1��cd'�ַ���" << endl;
    String goal("cd");
    cout << "ԭ�ַ���:\t" << str3 << endl;
    testDelete3(str3, 1, goal);
    cout << "���ַ���:\t" << str3 << endl;
    cout << endl;

    String str4("abcde");
    cout << "�쳣����չʾ" << endl;
    cout << "ɾ���±�1��'d'�ַ�" << endl;
    cout << "ԭ�ַ���:\t" << str4 << endl;
    testDelete2(str4, 1, 'd');
    cout << "���ַ���:\t" << str4 << endl;


}

int main()
{
    //testYYF();
    testWYT();
    
    
    //system("pause");
	/*while (true)
	{
		cout << "----String�������----" << endl;
		cout << "" << endl;
	}*/
}