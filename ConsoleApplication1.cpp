#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;
void RUS()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
};//Русский язык
// описание динамической структуры 
struct Node
{
    string name;    // название факультета
    int aud;        // номер аудитории
    int body;       // номер корпуса
    int styd;       // кол-во студентов
    string dek;     //ФИО декана
    Node* next;
    Node* prev;
};
typedef Node* PNode;
// Создание элемента списка 
PNode CreateNode(string Newname, int Newaud, int Newbody, int Newstyd, string Newdek)
{
    PNode NewNode = new Node;
    NewNode->name = Newname;
    NewNode->aud = Newaud;
    NewNode->body = Newbody;
    NewNode->styd = Newstyd;
    NewNode->dek = Newdek;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

void AddFirst(PNode& Head, PNode& Tail, PNode NewNode)
{
    NewNode->next = Head;
    NewNode->prev = NULL;
    if (Head != NULL)
        Head->prev = NewNode;
    Head = NewNode;
    if (Tail == NULL) Tail = Head;
}

void AddLast(PNode& Head, PNode& Tail, PNode NewNode)
{
    NewNode->prev = Tail;
    NewNode->next = NULL;
    if (Tail != NULL)
        Tail->next = NewNode;
    Tail = NewNode;
    if (Head == NULL) Head = Tail;

}

int main()
{
    RUS();
    PNode Head = NULL, Tail = NULL;
    PNode pnew, pfind;
    int t;
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

            pnew = CreateNode(new_name, new_aud, new_body, new_styd, new_dek); // создаем новый узел
            if (Head == NULL)
                AddFirst(Head, Tail, pnew);    //вставляем на первое место 
            else
                AddLast(Head, Tail, pnew);    //вставляем в конец списка
            break;
        case 2:
            pnew = Head;  // вывод списка на экран
            while (pnew != NULL)
            {
                cout << pnew->name << "\t"
                    << pnew->aud << "\t"
                    << pnew->body << "\t"
                    << pnew->styd << "\t"
                    << pnew->dek << endl;
                pnew = pnew->next;
            }
            break;
        }
    } while (t != 0);
}