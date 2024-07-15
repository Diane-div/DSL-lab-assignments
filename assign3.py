m=int(input("Enter number of rows:"))
n=int(input("Enter number of columns:"))

matrixA=[]
for i in range(0,m):
    row=[]
    for j in range(0,n):
        print("Index:",i,j)
        x=int(input("Enter element:"))
        row.append(x)
    matrixA.append(row)
    
#magic square
sum1=0
sum2=0
no_ms=True
for i in range(0,m):
    for j in range(0,n):
        if i==j:
            sum1+=matrixA[i][j] 
        f=i+j
        x=m-1
        if f==x:
            sum2+=matrixA[i][j]
sum_a=[]
if sum1==sum2:
    for l in range(0,m):
        x=matrixA[l]
        y=sum(x)
        if y==sum1:
            sum_a.append(y)
        else:
            no_ms=False
            break
else:
    no_ms=False
for i in range(0,m):
    s=0
    for k in range(0,n):
        s+=matrixA[k][i]
    if s== sum1:
        sum_a.append(s)
    else:
        no_ms=False
        break
b=len(sum_a)
c=2*m
if b==c:
    print("Its a magic square")
if no_ms==False:
    print("Not a magic square")
    
#Upper triangular matrix & diagonal sum

alpha=True
sum=0
for i in range(0,m):
    for j in range(0,n):
        z=matrixA[i][j]
        if i>j :
            if z!=0:
                alpha=False
        if i==j:
            sum+=matrixA[i][j]
if alpha:
    print("Matrix is upper triangular")
else:
    print("Not a upper triangular matrix") 
print("Sum of diagonal elements:",sum)  


#Saddle Point
for i in range(0,m):
    for j in range(0,n):
        x=matrixA[i][j]
        y=min(matrixA[i])
        if x==y:
            largest=x
            for k in range(0,m):
               if x< matrixA[k][j]:
                   largest=matrixA[k][j]
            if largest==x:
                print(x,"is a saddle point")
            else:
                continue
  
matrixB=[]
for i in range(0,m):
    row=[]
    for j in range(0,n):
        print("Index:",i,j)
        x=int(input("Enter element:"))
        row.append(x)
    matrixB.append(row)
print(matrixB)

addition

add_matrix=[]
for i in range(0,m):
    row=[]
    for j in range(0,n):
        x=matrixA[i][j]+matrixB[i][j]
        row.append(x)
    add_matrix.append(row)
print(matrixA)
print(matrixB)
print(add_matrix)

subtraction

sub_matrix=[]
for i in range(0,m):
    row=[]
    for j in range(0,n):
        x=matrixA[i][j]-matrixB[i][j]
        row.append(x)
    sub_matrix.append(row)
print(sub_matrix)

#multiply
multiply=[]
for i in range(0,m):
    row=[]
    for j in range(0,n):
        sum=0
        for k in range(0,n):
            x=matrixA[i][k]*matrixB[k][j]
            sum+=x
        row.append(sum)
    multiply.append(row)
print(multiply)
