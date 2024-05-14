import random

def VzaimProst(a, b): # нахождение НОД(a, b) для проверки, являются ли числа взаимопростыми
    
    if (b == 0): return a
    
    return VzaimProst(b, a % b)

def CheckPrime(p): # проверка, является ли число простым
    
    if (p <= 1): return False
    for i in range(2, int(p ** 0.5) + 1):
        if (p % i == 0): return False
        
    return True

def fi(num): # функция Эйлера
    
    result = 1
    stepen = 0
    
    for i in range(2, num+1):
        while (num % i == 0):
            stepen += 1
            num //= i
        if (stepen != 0): 
            result *= pow(i, stepen - 1) * (i - 1)
        stepen = 0
        
    return result

def Pow(a, x, p): # нахождение остатка от числа в степени
    
    result = 1
    
    if (CheckPrime(p) == True): x %= p - 1 # простое
    else: x %= fi(p) # не простое
    for i in range(1, x+1):
        result = (result * a) % p
        
    return result

def inversia(c, m): # алгоритм нахождения числа d(c^-1 mod m)
    
    q = 0
    one = [m, 0]
    two = [c, 1]
    three = [0, 0]
    
    while (two[0] != 0):
        q = one[0] // two[0]
        three[0] = one[0] % two[0]
        three[1] = one[1] - (q * two[1])
        one[0], one[1] = two[0], two[1]
        two[0], two[1] = three[0], three[1]
    
    if (one[1] < 0):
        one[1] += m
    
    return one[1]


message = input("Введите сообщение: ")
g = int(input("Введите число g: "))
n = int(input("Введите число n: "))

x = random.randrange(10000, 100000)  # абонент A выбирает случайное больше число и генерирует закрытый ключ
print("x =", x)

k = Pow(g, x, n)
print("k =", k)

y = random.randrange(10000, 100000)  # абонент B выбирает случайное больше число
while VzaimProst(y, n-1) != 1:
    y = random.randrange(10000, 100000)
print("y =", y)

Y = Pow(g, y, n)  # абонент B посылает абоненту A
print("Y =", Y)

X = Pow(Y, x, n)  # абонент А посылает абоненту B
print("X =", X)

z = inversia(y, n-1)  # абонент B вычисляет
print("z =", z)

ksh = Pow(X, z, n)
print("k' =", ksh)

if (k == ksh):
    key = k
    ArrEncrypted = []
    ArrDecrypted = []
    Encrypted = ""
    Decrypted = ""
    
    for i in range(len(message)): # Шифрование
        ArrEncrypted.append(chr(ord(message[i]) ^ key))
    for i in range(len(ArrEncrypted)):
        Encrypted += ArrEncrypted[i]
    print("Зашифрованное сообщение:", Encrypted)
    
    for i in range(len(Encrypted)): # Дешифрование 
        ArrDecrypted.append(chr(ord(Encrypted[i]) ^ key))
    for i in range(len(ArrDecrypted)):
        Decrypted += ArrDecrypted[i]
    print("Расшифрованное сообщение:", Decrypted)
    
else: print("Ключи не равны!")
