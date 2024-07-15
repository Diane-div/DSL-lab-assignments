n=int(input("Enter the number of students:"))
marks=[]
for i in range(0,n):
    x=int(input("Enter marks of student:"))
    marks.append(x)
sum1=0
for i in marks:
    if i >0:
        sum1+=i
avg=sum1/n
max_marks=max(marks)
#MIN_MARKS
min_marks=marks[0]
pm=12
pass_count=0
fail_count=0
for i in marks:
    if i<pm:
        fail_count+=1
    else:
        pass_count+=1
pass_percent=(pass_count/n)*100   
fail_percent=(fail_count/n)*100
#ABSENT
absent=0
for i in marks:
    if i<0:
        absent+=1
    elif min_marks>i & i>0:
        min_marks=i
#FREQUENCY
freq=[]
for i in range (0,n):
    x=marks[i]
    count=1
    for j in range(i+1,n):
        if marks[j]==x:
            count+=1
    freq.append(count)
max_freq=freq[0]
z=0
for i in range(0,n):
    y=freq[i]
    if y>max_freq:
        max_freq=y   
        z=i
print("Average:",avg)
print("Maximum marks:",max_marks)
print("Minimum marks:",min_marks)
print("Absent students:", absent)
print("Passed percent:",pass_percent)
print("Failed percent:",fail_percent)
print("Max Frequency marks:",marks[z])
