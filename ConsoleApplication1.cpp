#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

void RUS()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
};

//Структура
struct Faculty
{
	string name;    // название факультета
	int aud;        // номер аудитории
	int body;       // номер корпуса
	int styd;       // кол-во студентов
	string dek;     //ФИО декана


	Faculty* prev;
	Faculty* next;
};
typedef Faculty* PFaculty;

//Создание нового узла
PFaculty CreateFaculty(string Newname, int Newaud, int Newbody, int Newstyd, string Newdek)
{
	PFaculty NewFaculty = new Faculty;
	NewFaculty->name = Newname;
	NewFaculty->aud = Newaud;
	NewFaculty->body = Newbody;
	NewFaculty->styd = Newstyd;
	NewFaculty->dek = Newdek;
	NewFaculty->next = NULL;
	NewFaculty->prev = NULL;
	return NewFaculty;
}

//Добавить в начало
void AddFirst(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
	NewFaculty->next = Head;
	NewFaculty->prev = NULL;
	if (Head != NULL)
		Head->prev = NewFaculty;
	Head = NewFaculty;
	if (Tail == NULL)
		Tail = Head;
}

//Добавить в конец
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

//Добавить перед заданным
void AddBefore(PFaculty& Head, PFaculty& Tail, PFaculty P, PFaculty NewFaculty)
{
	if (P == Head)
		AddFirst(Head, Tail, NewFaculty);
	else
	{
		NewFaculty->next = P;
		NewFaculty->prev = P->prev;
		P->prev->next = NewFaculty;
		P->prev = NewFaculty;
	}
}

//Добавить после заданного
void AddAfter(PFaculty& Head, PFaculty& Tail, PFaculty P, PFaculty NewFaculty)
{
	if (P->next == NULL)
		AddLast(Head, Tail, NewFaculty);
	else
	{
		NewFaculty->next = P->next;
		NewFaculty->prev = P;
		P->next->prev = NewFaculty;
		P->next = NewFaculty;
	}
}

//Удалить некий узел
void Delete(PFaculty& Head, PFaculty& Tail, PFaculty D, bool fullDelete = true)
{
	PFaculty q = Head;
	if (Head == D)
	{
		Head = D->next;
		if (Head != NULL)
			Head->prev = NULL;
		else
			Tail = NULL;
	}
	else
	{
		D->prev->next = D->next;
		if (D->next != NULL)
			D->next->prev = D->prev;
		else
			Tail = NULL;
	}
	if (fullDelete)
		delete D;
}

//Ввод и создание нового узла
PFaculty CinFaculty()
{
	int aud, body, styd;
	string name, dek, departure, arrival;
	cout << "Введите уникальное название факультета: "; cin >> name;
	cout << "Введите номер аудитории: "; cin >> aud; cin.ignore();
	cout << "Введите номер корпуса: "; cin >> body; cin.ignore();
	cout << "Введите количество студентов: "; cin >> styd; cin.ignore();
	cout << "Введите ФИО декана: "; cin >> dek;
	cout << "Новый фаультет добавлен!" << endl
		<< "**********************************************" << endl;
	return CreateFaculty(name, aud, body, styd, dek);
}

//Найти по имени
PFaculty FindFacultyById(PFaculty& Head, string name)
{
	PFaculty pnew = Head;
	do
	{
		if (pnew->name == name)
			return pnew;
		pnew = pnew->next;
	} while (pnew != NULL);
	cout << "Факультет с таким названием не найден." << endl;
	return NULL;
}

int main()
{
	RUS();
	PFaculty NewFaculty;
	PFaculty Head = NULL, Tail = NULL;
	PFaculty pnew, pos = NULL;
	Faculty FCLT;
	string nameToFind, nameToDel;
	int t = 0, num = 0;
	do
	{
		//Меню
		{
			cout << "Факультетов введенно: " << num << endl
				<< "Выберете действие" << endl
				<< " 0 - выход " << endl
				<< " 1 - добавить новый элемент в начало списка " << endl
				<< " 2 - добавить новый элемент в конец списка " << endl
				<< " 3 - добавить новый элемент после заданного элемента " << endl
				<< " 4 - добавить новый элемент перед заданным элементом " << endl
				<< " 5 - удаление данных о выбранном факультете " << endl
				<< " 6 - сохранение данных списка факультетов в бинарный файл " << endl
				<< " 7 - извлечение данных из бинарного файла и помещение новых факультетов в список " << endl
				<< " 8 - Сведения о факультетах расположенных в первом корпусе на третьем этаже " << endl
				<< " 9 - Рассчитать общее количество студентов со всех факультетов " << endl
				<< " 10 - Вывод наименьшего и наибольшего количества студентов " << endl
				<< " 11 - вывод всего списка " << endl
				<< "Выборанное действие - ";
			cin >> t;
			cout << "**********************************************" << endl;
		}//Меню
		switch (t)
		{
		case 1://Добавление в начало
		{
			NewFaculty = CinFaculty();
			AddFirst(Head, Tail, NewFaculty);
			num++;
			break;
		}
		case 2://Добавление в конец
		{
			NewFaculty = CinFaculty();
			AddLast(Head, Tail, NewFaculty);
			num++;
			break;
		}
		case 3://Добавление после заданного
		{
			cout << "Введите название факультета, после которого нужно добавить новый: ";
			cin >> nameToFind; cin.ignore();
			NewFaculty = CinFaculty();
			PFaculty FacultyToAddAfter = FindFacultyById(Head, nameToFind);
			if (FacultyToAddAfter != NULL)
			{
				AddAfter(Head, Tail, FacultyToAddAfter, NewFaculty);
			}
			num++;
			break;
		}
		case 4://Добавление перед заданным
		{
			cout << "Введите название факультета, перед которым нужно добавить новый: ";
			cin >> nameToFind; cin.ignore();
			NewFaculty = CinFaculty();
			PFaculty FacultyToAddBefore = FindFacultyById(Head, nameToFind);
			if (FacultyToAddBefore != NULL)
			{
				AddBefore(Head, Tail, FacultyToAddBefore, NewFaculty);
			}
			num++;
			break;
		}
		case 5://Удаление выбранного
		{
			if (Head != NULL)
			{
				cout << "Введите название факультета, который нужно удалить: ";
				cin >> nameToDel; cin.ignore();
				PFaculty FacultyToDel = FindFacultyById(Head, nameToDel);
				if (FacultyToDel != NULL)
				{
					Delete(Head, Tail, FacultyToDel);
					cout << "Данные о факультете успешно удалёны!" << endl;
					num--;
				}
			}
			else
				cout << "Список пустой!" << endl;
			break;
		}
		case 6://Сохранение в файл
		{
			if (Head != NULL)
			{
				ofstream ofile("FacultyList.bin", ios::binary);
				if (ofile)
				{
					if (Head != NULL)
					{
						pnew = Head;
						while (pnew != NULL)
						{
							ofile << pnew->name << '\n' << pnew->aud << '\n' << pnew->body << '\n' << pnew->styd << '\n' << pnew->dek << endl;
							pnew = pnew->next;
						}
					}
				}
				if (!ofile.eof())
					cout << "Файл сохранён" << endl;
			}
			else
				cout << "Список пустой, сохранять нечего!" << endl;
			cout << "**********************************************" << endl;
			break;
		}
		case 7://Чтение файла
		{
			int  body, aud, styd;
			string name, dek;
			pnew = Head;
			ifstream file("FacultyList.bin", ios::binary | ios::in | ios::out);
			if (file)
			{
				while (!file.eof())
				{
					file >> name;
					file >> body;
					file >> aud;
					file >> styd;
					file >> dek;

					cout << "Название факультета - " << name << endl;
					cout << "Номер корпуса - " << body << endl;
					cout << "Номер аудитории - " << aud << endl;
					cout << "Количество студентов - " << styd << endl;
					cout << "ФИО декана - " << dek << endl;
					cout << endl;
				}
			}
			else
				cout << "Файл не найден" << endl;
		}
		case 8://Информация о факультетах в 1 корпусе, 3 этаже
		{
			int x = 0;
			pnew = Head;
			while (pnew != NULL)
			{
				x = pnew->aud;
				x = x - 300;
				if (100 > x && 0 < x && (pnew->body == 1))
					cout
					<< "Название Факультета - " << pnew->name << endl
					<< "Номер аудитории - " << pnew->aud << endl
					<< "Номер корпуса - " << pnew->body << endl
					<< "Количество студентов - " << pnew->styd << endl
					<< "ФИО декана - " << pnew->dek << endl
					<< endl << endl;
				pnew = pnew->next;
			}
			cout << "**********************************************" << endl;
			break;
		}
		case 9: //Общее кол-во студентов
		{
			int allstyd = 0;
			pnew = Head;
			while (pnew != NULL)
			{
				allstyd += pnew->styd;
				pnew = pnew->next;
			}
			cout << "Общее количество студентов: " << allstyd << endl;
			cout << "**********************************************" << endl;
			break;
		}
		case 10://Нахождение max и min
		{
			int min = 999, max = 0, x = 0;
			pnew = Head;
			cout << "Наибольшее и наименьшее количество студентов:" << endl;
			//Нахождение max и min
			while (pnew != NULL)
			{
				if (pnew->styd > max)
				{
					max = pnew->styd;
				}
				if (pnew->styd < min)
				{
					min = pnew->styd;
				}
				pnew = pnew->next;
			}
			cout << "Наибольшее - " << max << " Наименьшее - " << min << endl;
			while (pnew != NULL)
			{
				pnew->styd = x;
				if (x == max)
				{

					cout << "Название Факультета - " << pnew->name << endl;
					cout << "Номер аудитории - " << pnew->aud << endl;
					cout << "Номер корпуса - " << pnew->body << endl;
					cout << "Количество студентов - " << pnew->styd << endl;
					cout << "ФИО декана - " << pnew->dek << endl << endl;
				}
				if (x == min)
				{
					cout << "Название Факультета - " << pnew->name << endl;
					cout << "Номер аудитории - " << pnew->aud << endl;
					cout << "Номер корпуса - " << pnew->body << endl;
					cout << "Количество студентов - " << pnew->styd << endl;
					cout << "ФИО декана - " << pnew->dek << endl << endl;
				}
				pnew = pnew->next;
			}
			cout << "**********************************************" << endl;
			break;
		}
		case 11: //Вывод списка
		{
			int Fnumber = 0;
			cout << endl << "Вывод списка факультетов" << endl;
			pnew = Head;

			while (pnew != NULL)
			{
				Fnumber++;
				cout
					<< "Факультет № " << Fnumber << endl
					<< "Название Факультета - " << pnew->name << endl
					<< "Номер аудитории - " << pnew->aud << endl
					<< "Номер корпуса - " << pnew->body << endl
					<< "Количество студентов - " << pnew->styd << endl
					<< "ФИО декана - " << pnew->dek << endl << endl;
				pnew = pnew->next;
			}
			cout << "**********************************************" << endl;
			break;

		}
		}
	} while (t != 0);
};