
def gcd(c, m): # нахождение НОД(c, m)
    if (m == 0): return c
    return gcd(m, c % m)


print("Реализовать расширенный алгоритм Евклида для вычисления взаимообратного числа s^-1 mod m = d.")

c = int(input("Введите число c: "))
m = int(input("Введите число m: "))

if (gcd(c, m) != 1):
    print("Числа не взаимообратные.")
    exit(1)

# реализация расширенного алгоритма и вывод его значений
print("Табличное представление данных расширенного алгоритма Евклида:")
print(f"A | {c} 1 0")
print(f"B | {m} 0 1")
q = 0
one = [c, 1, 0]
two = [m, 0, 1]
three = [0, 0, 0]
while (two[0] != 0):
    q = one[0] // two[0]
    three[0] = one[0] % two[0]
    three[1] = one[1] - (q * two[1])
    three[2] = one[2] - (q * two[2])
    one = two.copy()
    two = three.copy()
    print(f"T | {three[0]} {three[1]} {three[2]} {q}")

if (one[1] < 0):
    one[1] += m
print(f"Взаимно обратное: {one[1]}")
