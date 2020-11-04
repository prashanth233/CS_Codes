def main():
	Courses=[]
	Students={}
	Grades={}
	while True:
		s=input()
		if s=="Courses":
			d=1
		elif s=="Students":
			d=2
		elif s=="Grades":
			d=3
		elif s=="EndOfInput":
			break
		else:
			s=s.split("~")
			if d==1:
				Courses.append(s)
			elif d==2:
				Students[s[0]]=s[1]
				Grades[s[0]]=[]
			elif d==3:
				Grades[s[-2]].append(s[-1])
	points={"A":10, "AB":9, "B":8, "BC":7, "C":6, "CD":5, "D":4}
	for idx in sorted(Grades):
		p=[points[x] for x in Grades[idx]]
		n=len(p) or 1
		marks=str(round(sum(p)/n,2)) if p else "0"
		d=[idx,Students[idx],marks]
		print("~".join(d))
main()
			