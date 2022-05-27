//Библиотеки
#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

//Добавление русского языка
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

    Faculty* next;
    Faculty* prev;
};
typedef Faculty* PFaculty;

// Создание нового элемента
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

//Добавить в начало списка
void AddFirst(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
    NewFaculty->next = Head;
    NewFaculty->prev = NULL;
    if (Head != NULL)
        Head->prev = NewFaculty;
    Head = NewFaculty;
    if (Tail == NULL) Tail = Head;
}

//Добавить в конец списка
void AddLast(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
    NewFaculty->prev = Tail;
    NewFaculty->next = NULL;
    if (Tail != NULL)
        Tail->next = NewFaculty;
    Tail = NewFaculty;
    if (Head == NULL) Head = Tail;

}

//Добавление после заданного
void AddAfter(PFaculty& Head, PFaculty& Tail, PFaculty pos, PFaculty NewFaculty)
{
    if (pos->next == NULL)
        AddLast(Head, Tail, NewFaculty);
    else
    {
        NewFaculty->next = pos->next;
        NewFaculty->prev = pos;
        pos->next->prev = NewFaculty;
        pos->next = NewFaculty;
    }
}
//Удаление
void DeleteFaculty(PFaculty& Head, PFaculty& Tail, PFaculty OldFaculty)
{
    if (Head == OldFaculty)
    {
        Head = OldFaculty->next;
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



//Главная функция
int main()
{
    RUS();
    PFaculty Head = NULL, Tail = NULL;
    PFaculty pnew, pfind;


    string new_name;    // название факультета
    int new_aud;        // номер аудитории
    int new_body;       // номер корпуса
    int new_styd;       // кол-во студентов
    string new_dek;     //ФИО декана
    int allstyd = 0;//Подсчет всех студентов
    int t; // Переменная для switсh

    do
    {

        cout << "Выберете действие" << endl;
        cout << " 0 - выход " << endl;
        cout << " 1 - добавить новый элемент в конец списка " << endl;
        cout << " 2 - добавить новый элемент в начало списка " << endl;
        cout << " 4 - добавить новый элемент после заданного элемента (В разработке) " << endl;
        cout << " 5 - добавить новый элемент после заданного элемента(В разработке) " << endl;
        cout << " 6 - удаление данных о выбранном факультете(В разработке) " << endl;
        cout << " 7 - сохранение данных списка факультетов в бинарный файл(В разработке) " << endl;
        cout << " 8 - извлечение данных из бинарного файла и помещение новых факультетов в список(В разработке) " << endl;
        cout << " 9 - Сведения о факультетах расположенных в первом корпусе на третьем этаже(В разработке) " << endl;
        cout << " 10 - Рассчитать общее количество студентов со всех факультетов " << endl;
        cout << " 11 - Сведения о факультете с наименьшим и наибольшим количеством студентов (В разработке)" << endl;
        cout << " 12 - вывод всего списка " << endl;
        cout << endl;
        cin >> t;
        cout << endl << "**********************************************" << endl;
        switch (t)
        {
            //Добавть в конец
        case 1:
            cout << "введите новое название факультета - " << endl; cin >> new_name;
            cout << "Введите номер аудитории - " << endl; cin >> new_aud;
            cout << "Введите номер корпуса - " << endl; cin >> new_body;
            cout << "Введите количество студентов - " << endl; cin >> new_styd;
            cout << "Введите ФИО декана - " << endl; cin >> new_dek;
            pnew = CreateFaculty(new_name, new_aud, new_body, new_styd, new_dek); // создаем новый узел
            AddLast(Head, Tail, pnew);
            cout << endl << "**********************************************" << endl;
            break;

            //Добавить в начало
        case 2:
            cout << "введите новое название факультета - " << endl; cin >> new_name;
            cout << "Введите номер аудитории - " << endl; cin >> new_aud;
            cout << "Введите номер корпуса - " << endl; cin >> new_body;
            cout << "Введите количество студентов - " << endl; cin >> new_styd;
            cout << "Введите ФИО декана - " << endl; cin >> new_dek;
            pnew = CreateFaculty(new_name, new_aud, new_body, new_styd, new_dek); // создаем новый узел
            AddFirst(Head, Tail, pnew);
            cout << endl << "**********************************************" << endl;
            break;

        case 3:
            cout << "Функция в разработке";
            break;

        case 4:
            cout << "Функция в разработке";
            break;

        case 5:
            cout << "Функция в разработке";
            break;

        case 6:
            cout << "Функция в разработке";
            break;

        case 7:
            cout << "Функция в разработке";
            break;

        case 8:
            cout << "Функция в разработке";
            break;

        case 9:
            cout << "Функция в разработке";
            break;

            //Вывод общее кол-во студентов
        case 10:

            pnew = Head;
            while (pnew != NULL)
            {
                allstyd += pnew->styd;
                pnew = pnew->next;
            }
            cout << "Общее количество студентов: " << allstyd << endl;
            cout << endl << "**********************************************" << endl;
            break;


        case 11:
            cout << "Функция в разработке";
            break;

            //Вывод всей стуктуры
        case 12:
            cout << endl << "Вывод списка факультетов" << endl;
            pnew = Head;  // вывод списка на экран
            int Fnumber = 0;
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
            cout << endl << "**********************************************" << endl;
            break;
        }
    } while (t != 0);
}