#Prime Number
num=int(input("Enter the number: "))
if num>1:
    for i in range(2,num):
        if(num%i==0):
            print(num, "Not Prime")
            break
    else:
        print(num, "is Prime")
        
else:
    print(num, "Not Prime")
    