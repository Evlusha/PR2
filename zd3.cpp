#include <iostream>
#include <vector>

using namespace std;

int gcd(int c, int m) { // нахождение НОД(c, m)
    if (m == 0) return c;
    return gcd(m, c % m);
}

int main(){
    setlocale(LC_ALL, "Rus");

    cout << "Реализация расширенного алгоритм Евклида для вычисления взаимообратного числа с^-1 mod m = d." << endl;

    int c, m;
    cout << "Введите числа c и m: ";
    cin >> c >> m;

    if (gcd(c, m) != 1) {
        cout << "Числа не взаимообратные.";
        return 1;
    }

    // реализация расширенного алгоритма и вывод его значений
    cout << "Табличное представление данных расширенного алгоритма Евклида: " << endl;
    cout << "A | " << c << " " << "1 " << "0" << endl;
    cout << "B | " << m << " " << "0 " << "1" << endl;
    int q;
    vector<int> one = {c, 1, 0};
    vector<int> two = {m, 0, 1};
    vector<int> three(3);
    while (two[0] != 0) {
        q = one[0] / two[0];
        three[0] = one[0] % two[0];
        three[1] = one[1] - (q * two[1]);
        three[2] = one[2] - (q * two[2]);
        one = two;
        two = three;
        cout << "T | " << three[0] << " " << three[1] << " " << three[2] << " " << q << endl;
    }
    
    if (one[1] < 0) {
        one[1] += m;
    }
    cout << "Взаимно обратное: " << one[1];

    return 0;
}
