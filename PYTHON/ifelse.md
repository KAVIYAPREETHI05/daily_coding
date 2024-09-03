### data types
numeric- int,float,complex

sequence- str,list,tuple,range

mapping- dict

set- set,frozenset

boolean- True,False

binary- bytes,bytearray,memoryview

nonetype- None

```py
a=int(input())
b=float(input())
c=complex(input())
d=(input())
e=list(input().split())
f=tuple(input().split())
g=set(input().split())
h=frozenset(input().split())
i=input('enter yes/no').lower()=='yes'


print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
print(g)
print(h)
print(i)
"""
23
.3
2+3j
kavi
2 3 4 
2 3 4
o/p
23
0.3
(2+3j)
kavi
['2', '3', '4']
('2', '3', '4')
{'sky', 'kavi'}
frozenset({'sky', 'kavi'})
True
"""
```
### dict
```py
a=input()
pairs=a.split(',')
my_dict={}
for pair in pairs:
  key,value=pair.split(':')
  my_dict[key.strip()] = int(value.strip()) 
print(my_dict)

"""
a:2,b:45
{'a': 2, 'b': 45}
"""
```
### range
```py
a=range(1,10)
print(list(a))

b=range(1,10,2)
for num in b:
  print(num)
"""
[1, 2, 3, 4, 5, 6, 7, 8, 9]
1
3
5
7
9
"""
```



### check whether num is divisible by 5 and 7
```py
a=int(input())
if a%7==0 and a%5==0 :
    print("it is divisible by 5 and 7")
else:
    if(a%7==0 and a%5!=0):
        print("it is divisible by 7 only")
    elif(a%5==0 and a%7!=0):
        print("it is divisible by 5 only")

```
### F to C and C to F
```py
temp=input()
degree=int(temp[:-1])
i_convertion=temp[-1]
if i_convertion.upper()=="C":
    result=int(round((9*degree)/5 +32))
    o_convertion="F"
elif i_convertion.upper()=="F":
    result=int(round((degree-32) *5/9))
    o_convertion="C"
else:
    print("invalid input")
    quit()
print(result,o_convertion)

```
