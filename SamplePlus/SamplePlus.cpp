// SamplePlus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include "BankAccount.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    string str = "sueta";
    int key = 24;

    for_each(str.begin(), str.end(), [key](char& ch) { ch ^= key; });

    cout << str << endl;

    for_each(str.begin(), str.end(), [key](char& ch) { ch ^= key; });
    
    cout << str << endl;

    auto account = BankAccount(230);

    BankAccount::AccountStateHandler print = [](string message) { 
        for_each(message.begin(), message.end(), [](auto& ch) { ch = toupper(ch); });

        cout << message << endl; 
    };

    account.registerHandler(print);
    account.registerHandler(print);
    account.withdraw(10);
    account.withdraw(1000);
    
    account.unregisterHandler(print);
    //account.unregisterHandler(print);
    account.withdraw(10);




}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
