//Библиотеки
#include <iostream>
#include <fstream>
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

//1. Добавить в начало списка
void AddFirst(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
    NewFaculty->next = Head;
    NewFaculty->prev = NULL;
    if (Head != NULL)
        Head->prev = NewFaculty;
    Head = NewFaculty;
    if (Tail == NULL) Tail = Head;
}

//2. Добавить в конец списка
void AddLast(PFaculty& Head, PFaculty& Tail, PFaculty NewFaculty)
{
    NewFaculty->prev = Tail;
    NewFaculty->next = NULL;
    if (Tail != NULL)
        Tail->next = NewFaculty;
    Tail = NewFaculty;
    if (Head == NULL) Head = Tail;

}

//3. Добавление после заданного
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

//4. Добавить перед заданным
void AddBefore(PFaculty& Head, PFaculty& Tail, PFaculty pos, PFaculty NewFaculty)
{
    if (pos == Head)
        AddFirst(Head, Tail, NewFaculty);
    else
    {
        NewFaculty->next = pos;
        NewFaculty->prev = pos->prev;
        pos->prev->next = NewFaculty;
        pos->prev = NewFaculty;
    }
}

//5. Удаление выбранного
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

//6. Запись в файл
void WriteFile(int num, Faculty FCLT)
{
    ofstream ofile("FacultyList.bin", ios::binary);
    for (int i = 0; i < num; i++)
    {
        ofile.write((char*)&FCLT, sizeof(Faculty));// 1-й блок
    }
    cout << "Файл сохранён";
    ofile.close();// закрыть записанный файл
}

//7. Чтение из файла
void ReadFile(Faculty FCLT)
{
    int Fnumber = 0;
    ifstream file("FacultyList.bin", ios::binary | ios::in | ios::out);
    file.seekg(0);           // вернуться к началу файла
    while (!file.eof())
    {
        file.read((char*)&FCLT, sizeof(Faculty));
        if (file.eof()) break;
        Fnumber++;
        cout
            << "Факультет № " << Fnumber << endl
            << "Название Факультета - " << FCLT.name << endl
            << "Номер аудитории - " << FCLT.aud << endl
            << "Номер корпуса - " << FCLT.body << endl
            << "Количество студентов - " << FCLT.styd << endl
            << "ФИО декана - " << FCLT.dek << endl << endl;


    }
    file.close();
}



//Главная функция 
int main()
{
    RUS();
    PFaculty Head = NULL, Tail = NULL;
    PFaculty pnew, pos = NULL;
    Faculty FCLT;

    string new_name;    // название факультета
    int new_aud;        // номер аудитории
    int new_body;       // номер корпуса
    int new_styd;       // кол-во студентов
    string new_dek;     //ФИО декана 
    int allstyd = 0;//Подсчет всех студентов
    int t = 0, num = 0, x; // Переменная для switсh
    int max = 0, min = 999, sh = 0, max1, min1;
    Faculty* b = new Faculty[num];


    int Fnumber = 0;
    do
    {
        cout << "Структу введено: " << num << endl;
        cout << "Выберете действие" << endl;
        cout << " 0 - выход " << endl;
        cout << " 1 - добавить новый элемент в конец списка " << endl;
        cout << " 2 - добавить новый элемент в начало списка " << endl;
        cout << " 3 - добавить новый элемент после заданного элемента (В разработке) " << endl;
        cout << " 4 - добавить новый элемент перед заданным элементом(В разработке) " << endl;
        cout << " 5 - удаление данных о выбранном факультете(В разработке) " << endl;
        cout << " 6 - сохранение данных списка факультетов в бинарный файл(В разработке) " << endl;
        cout << " 7 - извлечение данных из бинарного файла и помещение новых факультетов в список(В разработке) " << endl;
        cout << " 8 - Сведения о факультетах расположенных в первом корпусе на третьем этаже(В разработке) " << endl;
        cout << " 9 - Рассчитать общее количество студентов со всех факультетов " << endl;
        cout << " 10 - Сведения о факультете с наименьшим и наибольшим количеством студентов (В разработке)" << endl;
        cout << " 11 - вывод всего списка " << endl;
        cout << endl;
        cin >> t;
        cout << "**********************************************" << endl;
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
            cout << "**********************************************" << endl;
            num++;
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
            cout << "**********************************************" << endl;
            num++;
            break;

            //Добавить после заданного
        case 3:
            /* cout << "Введите позицию - "; cin >> pos;
             cout << "введите новое название факультета - " << endl; cin >> new_name;
             cout << "Введите номер аудитории - " << endl; cin >> new_aud;
             cout << "Введите номер корпуса - " << endl; cin >> new_body;
             cout << "Введите количество студентов - " << endl; cin >> new_styd;
             cout << "Введите ФИО декана - " << endl; cin >> new_dek;
             pnew = CreateFaculty(new_name, new_aud, new_body, new_styd, new_dek); // создаем новый узел
             AddAfter(Head, Tail, pos, pnew);
             cout << endl << "**********************************************" << endl;
             num++;
             break;*/

             //Добавить перед заданным
        case 4:
            cout << "Введите позицию - "; cin >> x;
            cout << "введите новое название факультета - " << endl; cin >> new_name;
            cout << "Введите номер аудитории - " << endl; cin >> new_aud;
            cout << "Введите номер корпуса - " << endl; cin >> new_body;
            cout << "Введите количество студентов - " << endl; cin >> new_styd;
            cout << "Введите ФИО декана - " << endl; cin >> new_dek;
            pnew = CreateFaculty(new_name, new_aud, new_body, new_styd, new_dek); // создаем новый узел
            AddBefore(Head, Tail, pos, pnew);
            cout << "**********************************************" << endl;
            num++;
            break;

            //Удаление выбранного
        case 5:
            cout << "Функция в разработке";
            break;

            //запись в файл
        case 6:
            WriteFile(num, FCLT);
            break;

            //Чтение из файла
        case 7:
            ReadFile(FCLT);
            break;

        case 8:
            pnew = Head;

            while (pnew != NULL)
            {
                if (pnew->body == 1 && (pnew->aud - 300) < 100)
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

            //Общее кол-во студентов
        case 9:
            pnew = Head;
            while (pnew != NULL)
            {
                allstyd += pnew->styd;
                pnew = pnew->next;
            }
            cout << "Общее количество студентов: " << allstyd << endl;
            cout << "**********************************************" << endl;
            break;

            //Вывод общее кол-во студентов
        case 10:
            cout << "Наибольшее и наименьшее количество студентов:" << endl;
            pnew = Head;
            while (pnew != NULL)
            {
                sh++;
                if (pnew->styd > max)
                {
                    max1 = sh;
                    max = pnew->styd;
                }
                if (pnew->styd < min)
                {
                    min1 = sh;
                    min = pnew->styd;
                }

                pnew = pnew->next;
            }
            cout << "Max - " << max << " Min - " << min << endl;
            cout << "**********************************************" << endl;
            break;

            //Вывод минимальног и максимального
        case 11:
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
    } while (t != 0);
}