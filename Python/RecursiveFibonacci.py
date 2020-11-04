def Fibonacci (n):
    if ((n == 1) or (n == 2)):
        return 1
    else:
        return (Fibonacci(n-1)+Fibonacci(n-2))

nthFib = int (input ("input nth:"))
print ("nthFib number is:", Fibonacci(nthFib))
