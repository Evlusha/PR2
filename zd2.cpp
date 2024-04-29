#include <iostream>
#include <vector>

using namespace std;

void algorithm(int c, int m, int &gcd, int &d) { // Алгоритм нахождения НОД(c, m) и числа d 

    int q; 
    vector<int> one = {m, 0};
    vector<int> two = {c, 1};
    vector<int> three(2);
    while (two[0] != 0) {
        q = one[0] / two[0];
        three[0] = one[0] % two[0];
        three[1] = one[1] - (q * two[1]);
        one[0] = two[0]; one[1] = two[1];
        two[0] = three[0]; two[1] = three[1];
    }

    gcd = one[0], d = one[1];
}

int main(){
    setlocale(LC_ALL, "Rus");

    cout << "Нахождение d, чтобы c*d mod m = 1:" << endl;
   
    int c, m;
    cout << "Введите числа c и m: ";
    cin >> c >> m;

    int gcd, d;
    algorithm(c, m, gcd, d);
    
    if (gcd != 1) {
        cout << "Такого d не существует, т.к. c и m не взаимнопростые.";
    } else {
        if (d < 0) {
            d += m;
        }
        cout << "Число d: " << d << endl << c*d << " mod " << m << " = " << (c*d) % m;
    }

    return 0;
}
