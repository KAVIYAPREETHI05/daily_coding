## TUPLE
- Tuple Items

Tuple items are ordered, unchangeable, and allow duplicate values.

Tuple items are indexed, the first item has index [0], the second item has index [1] etc.

- Ordered
  
When we say that tuples are ordered, it means that the items have a defined order, and that order will not change.

- Unchangeable
  
Tuples are unchangeable, meaning that we cannot change, add or remove items after the tuple has been created.

- Allow Duplicates
  
Since tuples are indexed, they can have items with the same value:

### create tuple
```py
x=()
print(x)#()

tupleA=tuple()
print(tupleA)#()

type1_tuple=(1,2,3,'h',"hello")
print(type1_tuple)#(1, 2, 3, 'h', 'hello')


type2_tuple=1,2,3,'k',"sky"
print(type2_tuple)#(1, 2, 3, 'h', 'hello')

l = (1,2,3)
print('this is tuple{0}'.format(l))
```
### pack and unpack
```py
tupleQ=1,2,3 #pack tuple
print(tupleQ)
a,b,c=tupleQ
print(a)#unpack tuple
```
### append item
```py
input_tuple=(1,2,3)
print(input_tuple)#(1, 2, 3)
input_list=list(input_tuple)
print(input_list)
input_list.append(4)#[1, 2, 3]
input_tuple=tuple(input_list)
print(input_tuple)#(1, 2, 3, 4)
```
### remove item
```py
input_tuple=(1,2,3,5)
print(input_tuple)#(1, 2, 3, 5)
input_list=list(input_tuple)
print(input_list)
input_list.remove(3)#[1, 2, 3, 5]
input_tuple=tuple(input_list)
print(input_tuple)#(1, 2,5)
```
### colon of tuple
```py
input_tuple=(1,2,3,[],5)
print(input_tuple)#(1, 2, 3, [], 5)
input_list=list(input_tuple)
print(input_list)
input_list[3].append(4)#[1, 2, 3, [], 5]
input_tuple=tuple(input_list)
print(input_tuple)#(1, 2, 3, [4], 5)

```
### tuple methods
```py
input_tuple=[1,2,3,4,2,3,4]
print(input_tuple.count(2))#2 times
print(input_tuple.index(4))#3rd index
```
### Check whether an element exists within a tuple
```py
input_tuple=[1,2,3,4,2,3,4]
if 4 in input_tuple:
  print("yes 4 occurs")
else:
  print("no it does not occur")
```
### slice items
```py
input_tuple=('a','b','c','d','e','f')
slice_=input_tuple[1:3]
print(slice_)

slice_=input_tuple[:3]
print(slice_)

slice_=input_tuple[:3:2]
print(slice_)

slice_=input_tuple[::]
print(slice_)

slice_=input_tuple[::-2]
print(slice_)

slice_=input_tuple[-1:-4:-1]
print(slice_)

slice_=input_tuple[1:5:2]
print(slice_)
```
```
('b', 'c')
('a', 'b', 'c')
('a', 'c')
('a', 'b', 'c', 'd', 'e', 'f')
('f', 'd', 'b')
('f', 'e', 'd')
('b', 'd')

```
### tuple to dict
```py
tupleA=((2,"a"),(3,"b"))

res_dict=dict((y,x) for  x,y in tupleA)
print(res_dict)
```
###  Unzip a list of tuples into individual lists
```py
l=[(2,3),(5,6),(9,8)]

result=list(zip(*l))
print(result)
#[(1, 3, 8), (2, 4, 9)] 
```
### reverse tuple
```py
t=(1,2,3,4)
r=reversed(t)
print(tuple(r))
```
```py
t=(1,2,3,4)
r=t[::-1]
print(r)
```
### Converting a list of tuples into a dictionary
```py
l = [("x", 1), ("x", 2), ("x", 3), ("y", 1), ("y", 2), ("z", 1)]
d={}
for a,b in l:
    d.setdefault(a,[]).append(b)
print(d)
```
### Replace last value of tuples in a list
```py
l =  [(10, 20, 40), (40, 50, 60), (70, 80, 90)]

print([t[:-1]+(1000,) for t in l])
```
### Remove an empty tuple(s) from a list of tuples

In Python, the following are considered falsy:
- None
- False
- 0 (or 0.0)
- Empty sequences: [], (), '', {}
  
```py
l = [(), (), ('',), ('a', 'b'), ('a', 'b', 'c'), ('d')]

l=[x for x in l if x]
print(l)
#[('',), ('a', 'b'), ('a', 'b', 'c'), 'd']
```

