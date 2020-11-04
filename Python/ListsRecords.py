class  STUDENT:
    def __init__(self, field1, field2, field3, field4):
        self.firstName = field1
        self.lastName = field2
        self.rollNumber = field3
        self.marks = field4

def ComputeAverage(list, n, index):
    average = int (0)
    for i in range(n):
        average = average + int (list[i].marks[index])
    return (average/n)
aList=list(range(3))
aList[0] = STUDENT(field1="hema", field2="murthy", field3="cs88D001", field4=[100,25,65])
aList[1] = STUDENT("M V N", "murthy", "cs86F001", [80,90,100])
aList[2] = STUDENT("Kaveri", "Murthy", "cs08B001",[75,75,75])
print (aList[0],aList[1], aList[2])
print (ComputeAverage(aList, 3,2))
