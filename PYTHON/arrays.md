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
 
