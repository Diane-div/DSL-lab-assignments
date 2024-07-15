n=int(input("Total students:"))
n1=int(input("Cricket students count:"))
n2=int(input("Football students count:"))
n3=int(input("Badminton students count:"))
univ=[]
for i in range(1,n+1):
    univ.append(i)
cric=[]
for i in range(0,n1):
    a=int(input("Enter roll no:"))
    cric.append(a)
foot=[]
for i in range(0,n2):
    a=int(input("Enter roll no:"))
    foot.append(a)
badi=[]
for i in range(0,n3):
    a=int(input("Enter roll no:"))
    badi.append(a)    
X1=[]
for i in range(0, len(cric)):
    if cric[i] in badi:
        X1.append(cric[i])
print(X1)
X2=[]
for i in range(0,len(cric)):
    if cric[i] not in X1:
        X2.append(cric[i])
for i in range(0,len(badi)):
    if badi[i] not in X1:
        X2.append(badi[i])
print(X2)
x3=[]    
for i in range(0,len(univ)):
    if univ[i] not in cric and univ[i] not in badi:
        x3.append(univ[i])
print(x3)
X=[]
for i in range(0, len(cric)):
    if cric[i] in foot:
        X.append(cric[i])
x4=[]
for i in range(0,len(X)):
    if X[i] not in badi:
        x4.append(X[i])
print(x4)
X5=[]
for i in range(0,len(univ)):
    if univ[i] not in badi and univ[i] not in foot and univ[i] not in cric:
        X5.append(univ[i])
print(X5)
X6=[]
for i in range(0,len(univ)):
    if univ[i] in badi or univ[i] in foot or univ[i] in cric:
        X6.append(univ[i])
print(X6)
X7=[]
for i in range(0,len(univ)):
    if univ[i] in badi and univ[i] in foot and univ[i] in cric:
        X7.append(univ[i])
print(X7)
