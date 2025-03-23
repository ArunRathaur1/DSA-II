# print("hello word")
# #varibles
# a=50
# b=[5,3,2,5,[5,3]]
# print(isinstance(b,list))
# for i in range(len(b)):
#     print(b[i],i)
# name="This is the name"
# print(f"this is the {name} ")
# print("value1","value2","value3",sep='-',end='p')
# print(type(b))
# a='50'
# b=int(a)
# print(type(b))
# c=float(a)
# print(c/3,type(c))
# s="""this is the
# format I wnat to use
# in the same pattern I will get the output
# """
# print(s)
# s='dlfjkdlfjlsdfj'
# p="This is the sentence"
# print(s.find('fjk'))
# print(s.count("fjk"))
# print(p.split('i'))
# print(len(s))
# print(2*s)
# print(s.isalpha())
# print(p.title())
# print(s.lower())
# print(s.upper())
# print(p.capitalize())
# print(s.rstrip())
# print(s[-5:])
# def function1(x=20):
#     if(x==0):return 0
#     if(x==1):return 1
#     return function1(x-1)+function1(x-2)
# list=[5,3,1,5,1]
# list.append(5)
# print(list)
# list.pop()
# print(list)
# p={3,5,2,43,5,3,234,5}
# print(p)
# print(100 in p)
# p.add(1434)
# p.remove(3)
# print(p)
# print(list.index(5))
# print(list.count(5))
# print(list)
# dict={
#     3:'c',
#     1:'a',
#     2:'b'
# }
# for key in dict:
#     print(key,dict[key])
# l=list(dict.keys())
# l.sort()
# for key in l:
#     print(key,dict[key])
# import os
# path1=os.getcwd()
# parth2=os.chdir(r"C:\Users\iampe\Desktop\engering book\1st Semester")
# path=os.getcwd()
# list =os.listdir(path)
# for i in list:
#     print(i)
# #creating some new files
# for i in range(5):
#     newpath=os.path.join(path,str(i))
#     os.mkdir(newpath)
# x=4
# def fun():
#     global x
#     x=10
# fun()
# print(x)
# import os
# path="first.txt"
# print(os.path.abspath(path))
# y=open(path,'w')
# y.write("This is the text")
# y.close()
# x=open(path,'r')
# line=x.readline()
# print(line)
# class myclass:
#     x=10
#     y=0
#     def add(self):
#         print(self.x+self.y)
# b=myclass
# b.x=50
# b.y=100
# a=myclass
# a.add(b)
class myclass:
    x=0
    y=0
    z=0
    def __init__(self,x,y,z):
        self.x=x
        self.y=y
        self.z=z
    def sum(self):
        return self.x+self.y+self.z
y=myclass
x=myclass
print(x.sum(y))