# Теорема Ферма и св-во сравнений(2 алгоритма)
def CheckPrime(p): # проверка, является ли модуль простым числом
    
    if (p <= 1): return False
    for i in range(2, int(p ** 0.5) + 1):
        if (p % i == 0): return False
        
    return True

def algorithm1(a, x, p): # Алгоритм1 через уменьшение степени
    
    result = 1
    a %= p
    while (x > 0):
        if (x % 2 == 1):
            result = (result * a) % p
        x //= 2
        a = (a * a) % p
        
    return result

def algorithm2(a, x, p):
    
    nums = [0] * 100 # инициализируем массив чисел, в котором хранится числовой ряд a
    stepen = 1 # для проверки, чтобы степень не превышала себя
    nums[0] = a % p
    
    n = 1
    while (stepen <= x): # вычисляем числовой ряд для числа a
        stepen *= 2
        nums[n] = (nums[n-1] * nums[n-1]) % p
        n += 1
    
    binary = [0] * 100 # инициализируем массив чисел, в котором хранится число в двоичной степени
    n = 0
    while (x != 1): # переводчим степень в двоичное число
        binary[n] = x % 2
        x //= 2
        n += 1
    binary[n] = x
    n += 1
    
    result = 1
    for i in range(n): # используем конечную формулу алгоритма
        result *= pow(nums[i], binary[i])
    result %= p
    
    return result


print("Нахождение остатка числа a^x mod p:")

a = int(input("Введите число а: "))
x = int(input("Введите степень x: "))
p = int(input("Введите модуль p: "))

if (CheckPrime(p) == False): print("p не простое число.") # проверка, является ли модуль простым числом
elif (a % p == 0) and (x != 0): print("Теорема Ферма не выполняется: a^x ≡ 0 (mod p)") # проверка, выполняется ли теорема Ферма
else:
    result1 = algorithm1(a, x, p)
    print(f"Алгоритм 1: {a}^{x} mod {p} = {result1}")
    result2 = algorithm2(a, x, p)
    print(f"Алгоритм 2: {a}^{x} mod {p} = {result2}")
