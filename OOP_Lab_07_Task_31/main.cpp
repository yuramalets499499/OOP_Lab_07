/*
 31. На основі контейнера vector побудувати одновимірний масив цілих чисел. Виконати
 операції введення елементів у масив, сортування, виведення елементів масиву на екран.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

void Output(vector<int> &Arr);
void Sort(vector<int> &Arr);

int main()
{
    system("chcp 1251");
    system("cls");
    system("color F0");
    
    vector<int> Arr;
    
    ifstream o;
    o.open("E:\\filecpp\\filecpp.txt");
    if (!o.is_open())
    {
        cout << "Файл не відкрито!" << endl;
    }
    else
    {
        cout << "Файл успішно відкрито" << endl;
        int n;
        while (o >> n)
        {
            Arr.push_back(n);
        }
    }
    Sort(Arr);
    cout << "Відсортований масив :" << endl;
    Output(Arr);
    int timer = clock();
    cout << "Кількість секунд, які працювала програма : ";
    cout << ((float)timer) / CLOCKS_PER_SEC << endl;
    o.close();
    
    system("pause");
    return 0;
}

void Sort(vector<int> &Arr)
{
    for (vector<int>::iterator i = Arr.begin(); i != Arr.end(); i++)
    {
        for (vector<int>::iterator j = i + 1; j != Arr.end(); j++)
        {
            if (*i > *j)
            {
                int st = *i;
                *i = *j;
                *j = st;
            }
        }
    }
}

void Output(vector<int> &Arr)
{
    for (vector<int>::iterator i = Arr.begin(); i != Arr.end(); i++)
    {
        cout << *i << endl;
    }
}
