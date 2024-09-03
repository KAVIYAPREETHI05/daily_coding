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
### positive or negative
```py
num=float(input())
if num>0:
    print(f"{num} is positive")
elif num<0:
    print(f"{num} is negative")
else:
    print(f"{num} is zero")
```
### even or odd
```py
num=float(input())
if num%2==0:
    print(f"{num} is even")
else:
    print(f"{num} is odd")
```
### largest of three nums
```py
a=int(input())
b=int(input())
c=int(input())
if a>=b and a>=c:
  print(f"{a} is largest")
elif b>=a and b>=c:
  print(f"{b} is largest")
else:
    print(f"{c} is largest")
```
### leap year or not
```py
a=int(input())

if (a%4==0 and a%100!=0) or a%400==0:
  print(f"{a} is leap year")
else:
    print(f"{a} is not leap year")
```
### char is vow or consonant
```py
a=input()
if len(a)!=1:
  print("enter only one char")
elif a in 'aeiouAEIOU':
  print(f"{a} is vowel")
else:
  print(f"{a} is consonant")
```
### num is multiple of another
```py
num1=int(input())
num2=int(input())
if num1%num2==0:
  print(f"{num1} is multiple of num2")
else:
  print(f"{num1} is not multiple of num2")
```
### alpha or digit or spl char
```py
a=input()
if a.isalpha():
  print(f"{a} is alpha")
elif a.isdigit():
  print(f"{a} is number")
else:
  print(f"{a} is spl char")
```
### check triangle
```py
a=int(input())
b=int(input())
c=int(input())
if a+b>c and b+c>a and a+c>b:
  print("the sides form triangle")
else:
  print("the sides doesn't form triangle")
```
### categorize age
```py
a=int(input())

if a<0:
  print("invalid age")
elif a<=12:
  print("child age")
elif a<=19:
  print("teen age")
elif a<=60:
  print("adult age")
else:
  print("senior")
```
###  check prime 
```py
a=int(input())

if a>1:
  for i in range(2,int(a*0.5)):
    if a%i==0:
      print("not prime")
      break
    
  else:
    print("prime number")
else:
  print("senior")
```
### check palindrome
```py
a=input()

if a==a[::-1]:
  print("it is palindrome")
else:
  print("it is not a palindrome")
```
### type of triangle
```py
a=int(input())
b=int(input())
c=int(input())
if a==b==c:
  print("triangle is equilateral")
elif a==b or b==c or a==c:
  print("triangle is isosceles")
else:
  print("it is scalene")
```
### calculate wages
```py
age=int(input())
days=int(input())
base=50
if age<18:
  multiplier=0.8
elif age>=18 and age<=65:
  multiplier=1.0
else:
  multiplier=0.6

wages=days*multiplier*base
print(wages)
```
### hot or cold based on temp
```py
temp=int(input())
if temp>=30:
  print("hot")
else:
  print("cold")


```
### type of triangle
```py
ang1=int(input())
ang2=int(input())
ang3=int(input())
if ang1+ang2+ang3!=180:
  print("not a triangle")
elif ang1==90 or ang2==90 or ang3==90:
  print("right triangle")
elif a>90 or b>90 or c>90:
  print("obtuse triangle")
else:
  print("acute triangle4")


```
### n+nn+nnn series
```py
n=int(input())
nn=2*n
nnn=3*n
print(n+nn+nnn)
```
### simple interest
```py
principal=float(input())
rate=float(input())
time=float(input())

simple_interest=(principal*rate*time)/100
print(f"simple interest is {simple_interest:.2f}")
```
### compound interest
```py
principal=float(input())
rate=float(input())
time=float(input())
freq=int(input())

compound_interest=principal*(1+rate/(100*freq))**(freq*time) -principal
print(f"compund interest is {compound_interest:.2f}")
```
### calculate velocity
```py
distance=float(input())
time=float(input())
velocity=distance/time
print(velocity)
```
### discount
```py
age=int(input())
if age<=12:
  discount=0.50
elif 13<=age<=19:
  discount=0.30
elif 20<=age<=65:
  discount=0.1
else:
  discount=0.0

ticket_price=50
total_price=ticket_price*(1-discount)
print(total_price)
```
