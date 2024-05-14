def algorithm(c, m): # Алгоритм нахождения НОД(c, m) и числа d 
    
    one = [m, 0]
    two = [c, 1]
    three = [0, 0]
    q = 0
    while (two[0] != 0):
        q = one[0] // two[0]
        three[0] = one[0] % two[0]
        three[1] = one[1] - (q * two[1])
        one[0], one[1] = two[0], two[1]
        two[0], two[1] = three[0], three[1]
        
    return one[0], one[1]


print("Нахождение d, чтобы c*d mod m = 1:")

c = int(input("Введите число c: "))
m = int(input("Введите число m: "))

gcd, d = algorithm(c, m)

if (gcd != 1):
    print("Такого d не существует, т.к. c и m не взаимнопростые.")
else:
    if (d < 0):
        d += m
    print("Число d:", d)
    print(c*d, "mod", m, "=", (c*d) % m)
