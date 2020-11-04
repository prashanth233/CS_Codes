lines = list (map (int, input().split()))
print (lines)
for i in range(len(lines)):
    max = i
    for j in range(i+1, len(lines)):
        if lines[max] < lines[j]:
            max = j
    lines[i], lines[max] = lines[max], lines[i]
    print (lines)
#for i in range(len(lines)):
#     print("%d" %lines[i])