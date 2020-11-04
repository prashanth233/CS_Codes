def g(n):
    s=0
    for i in range(2,n):
        if n%i == 0:
           s = s+1
    return(s)
