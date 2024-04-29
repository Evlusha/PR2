#include <iostream>
#include <math.h>

using namespace std;

int LastNum(int num, int nums[]) { // нахождение уникальной комбинации последних цифр в числе

    int k = 0, n = 0; // k - условие выхода из цикла / n - счётчик
    for (int i = 0; k == 0; i++) {
        nums[i] = pow(num, i+1);
        nums[i] = nums[i] % 10;
        if (nums[i] == nums[i-1] || nums[i] == nums[i-2] || nums[i] == nums[i-3] || nums[i] == nums[i-4]) {
            k = k + 1;
        } else {
            n = n + 1;
        }
    }

    return n;
}

int main(){
    setlocale(LC_ALL, "Rus");

    int a, b, c;
    cout << "Введите число, первую и вторую степень: ";
    cin >> a >> b >> c;

    a = a % 10;
    int nums1[10];
    int n1;
    n1 = LastNum(a, nums1); // находим уникальные конечные цифры и их кол-во
    int step1 = b % n1;
    if (step1 == 0) {
        b = nums1[n1-1]; // если остаток = 0, то конечная цифра - последняя цифра комбинации 
    } else {
        b = nums1[step1-1]; // иначе (цифра комбинации) - 1
    }

    int nums2[10];
    int n2;
    n2 = LastNum(b, nums2);
    int step2 = c % n2;
    if (step2 == 0) {
        c = nums2[n2-1];   
    } else {
        c = nums2[step2-1];
    }

    cout << "Последняя цифра: " << c; // вывод последней цифры числа
    
    return 0;
}
