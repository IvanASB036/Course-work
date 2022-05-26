#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;
void RUS()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
};//Русский язык

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

void AddFirst(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
    NewFaculty->next = Head;
    NewFaculty->prev = NULL;
    if (Head != NULL)
        Head->prev = NewFaculty;
    Head = NewFaculty;
    if (Tail == NULL) Tail = Head;
}

void AddLast(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
    NewFaculty->prev = Tail;
    NewFaculty->next = NULL;
    if (Tail != NULL)
        Tail->next = NewFaculty;
    Tail = NewFaculty;
    if (Head == NULL) Head = Tail;

}

int main()
{
    RUS();
    PFaculty Head = NULL, Tail = NULL;
    PFaculty pnew, pfind;
    int t, Fnumber = 0;
    string new_name;    // название факультета
    int new_aud;        // номер аудитории
    int new_body;       // номер корпуса
    int new_styd;       // кол-во студентов
    string new_dek;     //ФИО декана
    do
    {
        cout << "введите от 1 до 5 или 0 - выход" << endl;
        cout << " 0 - выход " << endl;
        cout << " 1 - добавить новый элемент в конец списка " << endl;
        cout << " 2 - вывод списка " << endl;
        cout << endl;
        cin >> t;
        switch (t)
        {
        case 1:
            cout << "введите новое название факультета - " << endl; cin >> new_name;
            cout << "Введите номер аудитории - " << endl; cin >> new_aud;
            cout << "Введите номер корпуса - " << endl; cin >> new_body;
            cout << "Введите количество студентов - " << endl; cin >> new_styd;
            cout << "Введите ФИО декана - " << endl; cin >> new_dek;

            pnew = CreateFaculty(new_name, new_aud, new_body, new_styd, new_dek); // создаем новый узел
            if (Head == NULL)
                AddFirst(Head, Tail, pnew);    //вставляем на первое место 
            else
                AddLast(Head, Tail, pnew);    //вставляем в конец списка
            break;
        case 2:
            cout << endl << "Вывод списка факультетов" << endl;
            pnew = Head;  // вывод списка на экран

            while (pnew != NULL)
            {
                Fnumber++;
                cout
                    << "Факультет № " << Fnumber << endl
                    << "Название Факультета - " << pnew->name << endl
                    << "Номер аудитории - " << pnew->aud << endl
                    << "Номер корпуса - " << pnew->body << endl
                    << "Количество студентов - " << pnew->styd << endl
                    << "ФИО декана - " << pnew->dek << endl;
                pnew = pnew->next;
            }
            break;
        }
    } while (t != 0);
}