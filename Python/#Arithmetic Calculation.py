#Arithmetic Calculation

def add(n1,n2):
    return n1+n2
def sub(n1,n2):
    return n1-n2
def mul(n1,n2):
    return n1*n2
def div(n1,n2):
    return n1/n2
def power(n1,n2):
    return n1**n2
def divint(n1,n2):
    return n1//n2

select=int(input("1,2,3,4,5,6 :"))
num1=int(input("Enter The First Number: "))
num2=int(input("Enter The Second Number: "))

if select==1:
    print(add(num1, num2))
elif select==2:
    print(sub(num1,num2))
elif select==3:
    print(mul(num1,num2))
elif select==4:
    print(div(num1,num2))
elif select==5:
    print(power(num1,num2))
elif select==6:
    print(divint(num1,num2))
else:
    print("Invalid")



  