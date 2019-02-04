// Lab1listG.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*
\���� ������ � ��������������� �������
\����� �������� �.�.
\���� 29.01.2019
*/

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "..\Lab1listG.h"
using namespace std;
Elem *p_first = NULL;//��������� �� ������ �������
Elem *p_cur = NULL;//��������� �� ������� �������

void add(int value)
{
	Elem *p_tmp = new Elem();
	p_tmp->data = value;
	//���������� ������� ��������
	if (p_first == 0)
	{
		p_first = p_tmp;
		p_cur = p_tmp;
		p_tmp->p_nx = p_tmp;
		p_tmp->p_pr = p_tmp;
	}
	else //���������� ����������� ��������� ����� �������
	{
		p_tmp->p_nx = p_cur->p_nx;
		p_tmp->p_pr = p_cur;
		p_cur->p_nx->p_pr = p_tmp;
		p_cur->p_nx = p_tmp;
		p_cur = p_tmp;
	}
	

}
void remove(int data)
{
	if (p_first == NULL) return;
	Elem *p_tmp = p_first;
	while (p_tmp->p_nx != p_first) {
		if (p_tmp->data == data) {
			if (p_tmp == p_first) {
				if (p_tmp->p_nx != p_first) {
					p_first = p_tmp->p_nx;
				}
				else
				{
					p_first = NULL;
				}
			}
			p_tmp->p_nx->p_pr = p_tmp->p_pr;
			p_tmp->p_pr->p_nx = p_tmp->p_nx;
			delete p_tmp;
			if (p_first) {
				p_cur = p_first->p_pr;
			}
			return;
		}
		p_tmp = p_tmp->p_nx;
	}
	if (p_tmp->data == data) {
		if (p_tmp == p_first) {
			if (p_tmp->p_nx != p_first) {
				p_first = p_tmp->p_nx;
			}
			else {
				p_first = NULL;
			}
		}
		p_tmp->p_nx->p_pr = p_tmp->p_pr;
		p_tmp->p_pr->p_nx = p_tmp->p_nx;
		delete p_tmp;
	}
	if (p_first) {
		p_cur = p_first->p_pr;
	}
}
void print()
{
	if (p_first) {
		Elem *p_tmp = p_first;
		cout << p_tmp->data << " ";
		p_tmp = p_tmp->p_nx;
		//���������� ������ �������, ������ ������� ��� ���������
		while (p_tmp != p_first)
		{
			cout << p_tmp->data << " ";
			p_tmp = p_tmp->p_nx;
		}
	}
	else
	{
		cout << " ������ ���� ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
//�������� ����
do {
	cout << " 0 - �����" << endl;
	cout << " 1 - �������� �������" << endl;
	cout << " 2 - ���������� ������" << endl;
	cout << " 3 - ������� �������" << endl;
	cout << "\n��� �������?>";
	cin >> x;

	// ����� �������� �� ������� ���� 
	switch (x)
	{
	case 1:
		cout << "�������� > "; 
		cin >> value;
		add(value); 
		break;
	case 2:
		cin >> data;
		remove(data);
		break;
	case 3: 
		print(); 
		break;
	}
} while (x != 0);//������� ������ �� �����
}