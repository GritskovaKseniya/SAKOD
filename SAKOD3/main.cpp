//Lab3List.cpp
/*
����: ���������� ��������� ������ k-� ���������� ����������
�����:�������� �.�.
����: 19.02.2019
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //�������, ����������� ��������� ��������
    //������������� �����
    cout << "������� ����� �-�� ����������:";
    int k;
    cin >> k; // ���������� � ������������ ����� ����� ��������
    int v[] = { 3, 2, 15, 10, 45, 33, 56, 23, 47, 60 }, i;

    nth_element(v, v + 1, v + 10);
/*����������������� ������������������, ������������ ���������� [first,last), ��� ,
��� ��� ��������, ������� ��� ���, �� ������� ��������� �������� nth,
����������� ����� ���, � ��� ������� �������� - �����.
*/
for (i = 0; i < 10; ++i)
    {
        cout << v[i] << " ";
    }
//������� �������� �������� �� �������� ������������� �������
cout << endl << "k-�� ������� = " << v[k - 1];
return 0;
}
