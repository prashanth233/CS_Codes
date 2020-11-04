def h(x):
    (d,n) = (1,0)
    while d <= x:
        (d,n) = (d*3,n+1)
    return(n)

