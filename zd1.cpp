

#include <iostream>
using namespace std;
	// Проверка на простату 
    bool is_prime(int p) {
        if (p <= 1)
            return false;
        for (int i = 2; i * i <= p; ++i) {
            if (p % i == 0)
                return false;
        }
        return true;
    }
    // Через двоичный вид (a ^ x) % p
    int bin_exp(long base, int exp, int mod) {
        long res = 1;
        while (exp) {
            if (exp % 2 == 1) {
                res *= base;
                res %= mod;
            }
            base *= base;
            base %= mod;
            exp /= 2;
        }
        cout << "Ответ " << res << endl;
        return res;
    }


    // Функция для нахождения (a ^ x) % p
    int mod_exp(int a, int x, int p) {  
        int result = 1;
        a = a % p;
        while (x > 0) {
            if (x % 2 == 1)
                result = (result * a) % p;
            x = x / 2;
            a = (a * a) % p;            
        }   
        cout << "Ответ " << result << endl;

        return bin_exp(a, x, p);
        return result;
       
    }

    // Проверка условий теоремы Ферма
    bool fermat_theorem(int a, int p, int x) {
        if (!is_prime(p)) 
            return false;
        if (mod_exp(a, x, p) == 1)
            return true;
        else
            return false;
    }

    int main() {
        setlocale(LC_ALL, "Rus");
        // Ввод a и p и x
        int a;
        cout << "Введите целое число a: ";
        cin >> a;

        int x;
        cout << "Введите степнь x: ";     
        cin >> x;

        int p;         
        cout << "Введите mod p: ";
        cin >> p;
        
        if (fermat_theorem(a, p , x ))
            cout << "Условия теоремы Ферма выполнены"<< endl;
        else
            cout << "Условия теоремы Ферма не выполнены " << endl;    

        return 0;
    }

