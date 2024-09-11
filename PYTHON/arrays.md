### get input and print output
```py
from array import*
n=int(input())
arr=array('i',[])

for i in range(n):
  element=int(input())
  arr.append(element)
for i in range(n):
  print(arr[i])
```
### array methods
```py
from array import*

arr=array('i',[10,20,30,40,10])
arr.insert(1,10000)
print(arr) #array('i', [10, 10000, 20, 30, 40, 10])
arr.append(5000)
print(arr) #array('i', [10, 10000, 20, 30, 40, 10, 5000])
print(arr.count(10)) #2
print(arr.index(40)) #4
arr.pop(3)
arr.remove(10)
print(arr) #array('i', [10000, 20, 40, 10, 5000])
arr.reverse()
print(arr) #array('i', [5000, 10, 40, 20, 10000])
sorted=array('i',sorted(arr))
print(sorted) #array('i', [10, 20, 40, 5000, 10000])

```

### append element
```py
from array import*
n=int(input())
arr=array('i',[10,20,30,40])
arr.append(n)

for i in arr:
  print(i)#refers value

for i in range(len(arr)):
  print(i,end=' ')#refers index
  print(arr[i])#refers value

```

### reverse array
reverse() method
```py
from array import*

arr=array('i',[10,20,30,40])

arr.reverse()
for i in arr:
  print(i)
```
manually using loop
```py
from array import*

arr=array('i',[10,20,30,40])

for i in range(len(arr)-1,-1,-1):
  print(arr[i])
```
slicing
```py
from array import*

arr=array('i',[10,20,30,40])

reversed=arr[::-1]
for i in reversed:
  print(i)

```
### length of array
```py
from array import*

arr=array('i',[10,20,30,40])
print(len(arr))#length of array
print(arr.itemsize) #The length of the one array in bytes
print(arr.buffer_info()) #Current memory address and the length in elements of the buffer
print(arr.buffer_info()[0]*arr.itemsize) #The size of the memory buffer in bytes
```
### occurence of element
```py
from array import*
n=int(input())

arr=array('i',[10,20,30,40,10])
count=0
for i in arr:
  if(n==i):
    count+=1
print(count)
```
count() method
```py
from array import*
n=int(input())

arr=array('i',[10,20,30,40,10])
print(arr.count(n))
```

### extend array
```py
from array import*
arr=array('i',[10,20,30,40,10])
arr.extend(arr)
print(arr)
```
### append items with specified list
```py
from array import*
arr=array('i',[10,20,30,40,10])
arr2=[90,80]
arr.fromlist(arr2)
print(arr)
```
###  Insert a new item before the second element in an existing array
```py
from array import*

arr=array('i',[10,20,30,40,10])
arr.insert(1,10000)
print(arr)

```

 
