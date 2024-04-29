#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>

using namespace std;
// нахождение НОД(a, b) для проверки, являются ли числа взаимопростыми
int VzaimProst(int a, int b) { 

    if (b == 0) return a;

    return VzaimProst(b, a % b);
}
// проверка, является ли число простым
bool CheckPrime(int p) { 

    if (p <= 1) return false;
    for (int i = 2; i * i <= p; ++i) 
    {
        if (p % i == 0) return false;
    }

    return true;
}
 // функция Эйлера
int fi(int num) {

    int result = 1;
    int stepen = 0;

    for (int i = 2; i <= num; ++i)
    {
        while (num % i == 0) 
        {
            stepen++;
            num /= i;
        }
        if (stepen != 0) {
            result *= pow(i, stepen - 1) * (i - 1);
        }
        stepen = 0;
    }

    return result;
}
// нахождение остатка от числа в степени
int Pow(int a, int x, int p) 
{ 

    int result = 1;

    if (CheckPrime(p) == true) 
    { // простое
        x %= p - 1;
    }
    else { // не простое
        x %= fi(p);
    }
    for (int i = 1; i <= x; ++i) {
        result = (result * a) % p;
    }

    return result;
}
// Алгоритм нахождения числа d(c^-1 mod m)
int inversia(int c, int m) 
{ 

    int q;
    vector<int> one = { m, 0 };
    vector<int> two = { c, 1 };
    vector<int> three(2);
    while (two[0] != 0) 
    {
        q = one[0] / two[0];
        three[0] = one[0] % two[0];
        three[1] = one[1] - (q * two[1]);
        one[0] = two[0]; one[1] = two[1];
        two[0] = three[0]; two[1] = three[1];
    }

    if (one[1] < 0) 
    {
        one[1] += m;
    }

    return one[1];
}


int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    string message;
    cout << "Введите сообщение: ";
    cin >> message;
    int g, n;
    cout << "Введите числа g и n: ";
    cin >> g >> n;

    int x = 100 + rand() % 100000; // абонент A выбирает случайное больше число и генерирует закрытый ключ
    cout << "x = " << x << endl;
    int k = Pow(g, x, n);
    cout << "k = " << k << endl;

    int y = 100 + rand() % 100000; // абонент B выбирает случайное больше число
    while (VzaimProst(y, n - 1) != 1) 
    {
        y = 100 + rand() % 100000;
    }
    cout << "y = " << y << endl;

    int Y = Pow(g, y, n); // абонент B посылает абоненту A
    cout << "Y = " << Y << endl;

    int X = Pow(Y, x, n); // абонент А посылает абоненту B
    cout << "X = " << X << endl;

    int z = inversia(y, n - 1); // абонент B вычисляет
    cout << "z = " << z << endl;
    int ksh = Pow(X, z, n);
    cout << "k' = " << ksh << endl;

    if (k == ksh) 
    {
        int key = k;

        for (int i = 0; i < message.length(); ++i) 
        {
            message[i] = message[i] ^ key;
        }
        cout << "Зашифрованное сообщение: " << message << endl;

        for (int i = 0; i < message.length(); ++i) 
        {
            message[i] = message[i] ^ key;
        }
        cout << "Расшифрованное сообщение: " << message;

    }
    else 
    {
        cout << "Ключи не равны!";
    }

    return 0;
}
