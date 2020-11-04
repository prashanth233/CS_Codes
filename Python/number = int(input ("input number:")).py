number = int(input ("input number:"))
print (number)
revNumber = 0
while (number > 0):
    revNumber =  revNumber*10 + number % 10
    number = number // 10
    print ("%5d %5d\n" %(number, revNumber))
print("Reversed number=", revNumber)