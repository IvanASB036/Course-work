#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
void RUS()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
};//Русский язык

struct Faculty
{
	string Name_Faculty; //Название факультета
	int Audience_number; //Номер аудитории
	int Case_number; //Номер корпуса
	int Number_Students; //Количество студентов
	string Full_Name; // ФИО декана
	Faculty* next;
	Faculty* prev;
};
typedef Faculty* PFaculty;
PFaculty Head = NULL;
PFaculty Tail = NULL;

PFaculty Create(string New_Name_Faculty, int New_Audience_number, int New_Case_number, int New_Number_Students, string New_Full_Name)
{
	PFaculty NewFaculty = new Faculty;
	NewFaculty->Name_Faculty = New_Name_Faculty;
	NewFaculty->Name_Faculty = New_Audience_number;
	NewFaculty->Name_Faculty = New_Case_number;
	NewFaculty->Name_Faculty = New_Number_Students;
	NewFaculty->Name_Faculty = New_Full_Name;
	NewFaculty->next = NULL;
	NewFaculty->prev = NULL;
	return NewFaculty;
};

void AddFirst(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty) {
	NewFaculty->next = Head;
	NewFaculty->prev = NULL;
	if (Head != NULL)
		Head->prev = NewFaculty;
	Head = NewFaculty;
	if (Tail == NULL)
		Tail = Head;
};

void AddLast(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty) {
	NewFaculty->prev = Tail;
	NewFaculty->next = NULL;
	if (Tail != NULL)
		Tail->next = NewFaculty;
	Tail = NewFaculty;
	if (Head == NULL)
		Head = Tail;
};

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
};

void AddBefore(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty, PFaculty p)
{
	if (p == Head)
		AddFirst(Head, Tail, NewFaculty);
	else {
		NewFaculty->next = p;
		NewFaculty->prev = p->prev;
		p->prev->next = NewFaculty;
		p->prev = NewFaculty;
	}
};

void Delete(PFaculty& Head, PFaculty& Tail, PFaculty OldFaculty)
{
	if (Head == OldFaculty)
	{
		Head = OldFaculty->next;
		if (Head != NULL)
			Head->prev = NULL;
		else
			Tail = NULL;
	}
	else {
		OldFaculty->prev->next = OldFaculty->next;
		if (OldFaculty->next != NULL)
			OldFaculty->next->prev = OldFaculty->prev;
		else
			Tail = NULL;
	}
	delete OldFaculty;
};



int main()
{
	RUS();
	PFaculty Head = NULL, Tail = NULL;
	PFaculty pnew, pfind;
	int S;
	string newName_Faculty, newFull_Name;
	int newAudience_number, newCase_number, newNumber_Students;
	do
	{
		cout << "Выберете действие" << endl;
		cout << "1 - Добавить новый факультет в начало списка" << endl;
		cout << "2 - Добавить новый факультет в конец списка" << endl;
		cout << "3 - Добавить новый факультет после определенного факультета" << endl;
		cout << "4 - Добавить новый факультет перед определенного факультета" << endl;
		cout << "5 - Удаление данных о выбранном факультете" << endl;
		cout << "6 - Сохранить данные списка факультетов в бинарный файл" << endl;
		cout << "7 - Извлечь данные из бинарного файла и помещение новых факультетов в список" << endl;
		cout << "8 - Сведения о факультетах расположенных в первом корпусе на третьем этаже" << endl;
		cout << "9 - Общее количество студентов" << endl;
		cout << "10 - Факультет с наименьшим количеством студентов" << endl;
		cout << "11 - Вывод списка" << endl;
		cout << "0 - Выход" << endl;
		cin >> S;

		switch (S)
		{
		case 1:
			cout << "Введите название факультета - ";
			cin >> newName_Faculty;
			cout << endl << "Введите номер аудитории - ";
			cin >> newAudience_number;
			cout << endl << "Введите номер корпуса - ";
			cin >> newCase_number;
			cout << endl << "Введите количество студентов - ";
			cin >> newCase_number;
			cout << endl << "Введите ФИО декана - ";
			cin >> newFull_Name;
			pnew = Create(newName_Faculty, newAudience_number, newCase_number, newCase_number, newFull_Name);
			if (Head == NULL)
				AddLast(Head, Tail, pnew);
			else
				AddFirst(Head, Tail, pnew);
			break;
		case 2:
			cout << "Введите название факультета - ";
			cin >> newName_Faculty;
			cout << endl << "Введите номер аудитории - ";
			cin >> newAudience_number;
			cout << endl << "Введите номер корпуса - ";
			cin >> newCase_number;
			cout << endl << "Введите количество студентов - ";
			cin >> newCase_number;
			cout << endl << "Введите ФИО декана - ";
			cin >> newFull_Name;
			pnew = Create(newName_Faculty, newAudience_number, newCase_number, newCase_number, newFull_Name);
			if (Head == NULL)
				AddFirst(Head, Tail, pnew);
			else
				AddLast(Head, Tail, pnew);
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;
		case 11:
			pnew = Head;
			while (pnew != NULL)
			{
				cout << pnew->Name_Faculty << "\t" << pnew->Audience_number << pnew->Case_number << pnew->Number_Students << pnew->Full_Name << endl;
				pnew = pnew->next;
			}
			break;
		}
	} while (S != 0);

}

