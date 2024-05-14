def LastNum(num, nums): # нахождение уникальной комбинации последних цифр в числе
    
    k = 0 # условие выхода из цикла
    n = 0 # счётчик
    i = 0
    while (k == 0):
        nums[i] = pow(num, i+1)
        nums[i] = nums[i] % 10
        if nums[i] == nums[i-1] or nums[i] == nums[i-2] or nums[i] == nums[i-3] or nums[i] == nums[i-4]: k += 1
        else: n += 1
        i += 1
        
    return n

a = int(input("Введите число: "))
b = int(input("Введите 1-ю степень: "))
c = int(input("Введите 2-ю степень: "))

a = a % 10
nums1 = [0] * 10
n1 = LastNum(a, nums1) # находим уникальные конечные цифры и их кол-во
step1 = b % n1
if (step1 == 0): b = nums1[n1-1] # если остаток = 0, то конечная цифра - последняя цифра комбинации
else: b = nums1[step1-1] # иначе (цифра комбинации) - 1

nums2 = [0] * 10
n2 = LastNum(b, nums2)
step2 = c % n2
if (step2 == 0): c = nums2[n2-1]
else: c = nums2[step2-1]

print("Последняя цифра:", c)
