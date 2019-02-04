// Lab1listG.cpp: определяет точку входа для консольного приложения.
//
/*
\Цель работа с двунаправленным списком
\Автор Грицкова К.А.
\Дата 29.01.2019
*/

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "..\Lab1listG.h"
using namespace std;
Elem *p_first = NULL;//указатель на первый элемент
Elem *p_cur = NULL;//указатель на текущий элемент

void add(int value)
{
	Elem *p_tmp = new Elem();
	p_tmp->data = value;
	//добавление первого элемента
	if (p_first == 0)
	{
		p_first = p_tmp;
		p_cur = p_tmp;
		p_tmp->p_nx = p_tmp;
		p_tmp->p_pr = p_tmp;
	}
	else //Добавление последующих элементов после первого
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
		//напечатали первый элемент, теперь выведем все остальные
		while (p_tmp != p_first)
		{
			cout << p_tmp->data << " ";
			p_tmp = p_tmp->p_nx;
		}
	}
	else
	{
		cout << " Список пуст ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
//экранное меню
do {
	cout << " 0 - Выйти" << endl;
	cout << " 1 - Добавить элемент" << endl;
	cout << " 2 - Напечатать список" << endl;
	cout << " 3 - Удалить элемент" << endl;
	cout << "\nЧто сделать?>";
	cin >> x;

	// выбор действия из пунктов меню 
	switch (x)
	{
	case 1:
		cout << "Значение > "; 
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
} while (x != 0);//условие выхода из цикла
}