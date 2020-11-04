#Sum of n natural numbers
def Sum_of_natural_numbers(n):
    sum=0
    x=1
    while x<=n:
        sum=sum+x
        x=x+1
    return sum
n= int(input("Enter the value: "))
print(Sum_of_natural_numbers(n))
