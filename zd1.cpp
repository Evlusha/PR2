// Теорема Ферма и св-во сравнений(2 алгоритма)
#include <iostream>
#include <math.h>

using namespace std;

bool CheckPrime(int p) { // проверка, является ли модуль простым числом
    
    if (p <= 1) return false; 
    for (int i = 2; i * i <= p; ++i) { 
        if (p % i == 0) return false;
    }

    return true;
}

int algorithm1(int a, int x, int p) { // Алгоритм1 через уменьшение степени

    int result = 1;
    a %= p;
    while (x > 0) {
        if (x % 2 == 1)
            result = (result * a) % p;
        x /= 2;
        a = (a * a) % p;
    }
    
    return result;
}

int algorithm2(int a, int x, int p) { // Алгоритм2 через логарифм

    int nums[100]; // инициализируем массив чисел, в котором хранится числовой ряд a
    int stepen = 1; // для проверки, чтобы степень не превышала себя
    nums[0] = a % p;

    int n=1;

    while (stepen <= x) { // вычисляем числовой ряд для числа a
        stepen *= 2;
        nums[n] = (nums[n-1] * nums[n-1]) % p; 
        n += 1;
    }

    int binary[100]; // инициализируем массив чисел, в котором хранится число в двоичной степени
    n = 0;
    while (x != 1) { // переводчим степень в двоичное число
        binary[n] = x % 2;
        x /= 2;
        n += 1;
    }
    binary[n] = x;
    n += 1;

    int result = 1;
    for (int i = 0; i < n; ++i) { // используем конечную формулу алгоритма
        result *= pow(nums[i], binary[i]);
    }
    result %= p;

    return result;
}

int main(){
    setlocale(LC_ALL, "Rus");

    cout << "Нахождение остатка числа a^x mod p:" << endl;
    
    int a, x, p;
    cout << "Введите числа a, x и p: ";
    cin >> a >> x >> p;

    if (CheckPrime(p)==false) { // проверка, является ли модуль простым числом
        cout << "p не простое число." << endl;
        return 1;
    }

    if (a % p == 0 && x != 0) { // проверка, выполняется ли теорема Ферма
        cout << "Теорема Ферма не выполняется: a^x ≡ 0 (mod p)" << endl;
        return 1;
    }

    int result1 = algorithm1(a, x, p);
    cout << "Алгоритм 1: " << a << "^" << x << " mod " << p << " = " << result1 << endl;
    int result2 = algorithm2(a, x, p);
    cout << "Алгоритм 2: " << a << "^" << x << " mod " << p << " = " << result2 << endl;

    return 0;
}
