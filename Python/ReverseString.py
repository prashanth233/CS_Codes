str = list(input ("input string:"))
lnt = len(str)
for i in range(0, lnt//2, 1):
    str[i], str[lnt-i-1] = str[lnt-i-1], str[i]
    print (i, lnt-i)
print ("rev1", "".join(str))
def Reverse(str):
    s = str
    str = ""
    for i in s:
        str = i + str
    return str
s = str
str = ""
for i in s:
    str = i + str
print("rev2", str)
str = list(str)
for i in range(0, lnt//2, 1):
    str[i], str[lnt-i-1] = str[lnt-i-1], str[i]
    print (i, lnt-i)
print ("rev3", "".join(str))
print ("rev4", Reverse("".join(str)))
