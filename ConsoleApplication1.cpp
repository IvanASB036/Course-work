#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


struct Faculty
{
	string Name;
	int Audience;
	int Number;
	int Students;
	string Full_Name;

	Faculty *next;
	Faculty *prev;
};
typedef Faculty* PFaculty;
PFaculty Head = NULL;
PFaculty Tail = NULL;

//Создание нового узла
PFaculty CreateFaculty(string NewName, int NewAudience, int NewNumber, int NewStudents)
{
	PFaculty NewFaculty = new Faculty;
	NewFaculty->Name = NewName;
	NewFaculty->Audience = NewAudience;
	NewFaculty->Number = NewNumber;
	NewFaculty->Students = NewStudents;
	NewFaculty->next = NULL;
	NewFaculty->prev = NULL;
	return NewFaculty;
}

//Добавление узла в начало списка

void AddFirst(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
	NewFaculty -> next = Head;
	NewFaculty -> prev = NULL;
	if (Head != NULL)
		Head->prev = NewFaculty;
	Head = NewFaculty;
	if (Tail == NULL) 
		Tail = Head;
}

//Добавление в конец списка

void AddLast(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
	NewFaculty->prev = Tail;
	NewFaculty->next = NULL;
	if (Tail != NULL) 
		Tail->next = NewFaculty;
	Tail = NewFaculty;
	if (Head == NULL)
		Head = Tail;
}

//Добавление нового узла после заданного
void AddAfter(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty, PFaculty p)
{
	if (p->next == NULL)
		AddLast(Head, Tail, NewFaculty);
	else {
		NewFaculty->next = p->next;
		NewFaculty->prev = p;
		p->next->prev = NewFaculty;
		p->next = NewFaculty;
	}
}

//Добавление узла перед заданным
void AddBefore(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty, PFaculty p)
{
	if (p == Head)
		AddFirst(Head, Tail , NewFaculty);
	else {
		NewFaculty->next = p;
		NewFaculty->prev = p->prev;
		p->prev->next = NewFaculty;
		p->prev = NewFaculty;
	}
}

//Удаление узла
void DeleteFaculty(PFaculty $Head, PFaculty& Tail, PFaculty OldFaculty)
{
	if (Head == OldFaculty)
	{	Head = OldFaculty->next;
	if (Head != NULL)
		Head->prev = NULL;
	else
		Tail = NULL;
	}
	else
	{
		OldFaculty->prev->next = OldFaculty->next;
		if (OldFaculty->next != NULL)
			OldFaculty->next->prev = OldFaculty->prev;
		else
			Tail = NULL;
	}
	delete OldFaculty;
}

//Поиск в списке
PFaculty Find(PFaculty Head, string NewName, int Audince, int Number, int students, string Full_Name)
{
	PFaculty q = Head;

	while (q->Name != NewName && q != NULL)
		q = q->next;
	return q;
}

//Поиск по порядку

PFaculty FindPlace(PFaculty Head, string NewName, int Audince, int Number, int students, string Full_Name)
{
	PFaculty q = Head;
	while (q->Name < NewName && q != NULL)
		q = q->next;
	return q;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	PFaculty Head = NULL, Tail = NULL;
	PFaculty pnew, pfind;
	int t;
	string New_Name, New_Full_Name;
	int New_Audience, New_Number, New_Students;
	do
	{
		cout << "Выберите действие" << endl;
		cout << "0 - Выход " << endl;
		cout << "1 - Добавить новый элемент " << endl;
		cout << "2 - Вывод списка" << endl;
		cout << "3 - Добавить новый элемент после выбранного " << endl;
		cout << "4 - Добавть новый элемент по алфавиту" << endl;
		cout << "5 - Добавить новый элемент перед выбранныым" << endl;
		cout << "6 - Удалить элемент " << endl;
		cout << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			cout << "Введите новое название факультета - ";
			cin >> New_Name;
			pnew = CreateFaculty(New_Name);
			cout << "Введите новый номер аудитории - ";
			cin >> New_Audience;
			pnew = CreateFaculty(New_Audience);
			cout << "Введите новый номер корпуса - ";
			cin >> New_Number;
			pnew = CreateFaculty(New_Number);
			cout << "Введите новое количество студентов - ";
			cin >> New_Students;
			pnew = CreateFaculty(New_Students);
			cout << "Введите новое ФИО декана - ";
			cin >> New_Full_Name;
			pnew = CreateFaculty(New_Full_Name);


			if (Head == NULL)
			if (Head == NULL)
				AddFirst(Head, Tail, pnew);
			else
				AddLast(Head, Tail, pnew);
			break;

		case 2:
			pnew = Head;
			while (pnew != NULL)
			{
				cout << pnew->Name << "\t" << pnew->Audience << pnew->Number << pnew->Students << pnew->Full_Name << endl;
				pnew = pnew->next;
			}
			break;
		};
	} 
	while (t != 0);
	return 0;
}