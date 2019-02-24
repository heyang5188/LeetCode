#!C:\Users\Administrator\AppData\Local\Programs\Python\Python37
# -*- coding: utf-8 -*-
import os
import time
name = input("please in put your problem name:")
name = name.replace(" ", "")
path = input("please in put your Problem Path:")
pwd = os.path.abspath(path)
back = ''
fileName = ''
if name.endswith('.cc'):
    f = open(os.path.join(pwd, name), 'w+', encoding='utf-8')  # 重新写入文件
    s = "// Author Herb \n// Time : "
    s += time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    s += "\n#include <iostream>\n#include <string>\n#include <map>\n#include <unordered_map>\n"
    s += "#include <vector>\n#include <queue>\nusing namespace std;\n"
    s += "struct ListNode { int val; ListNode* next; ListNode(int x): val(x),next(NULL){}};\n"
    s += "struct TreeNode {int val;TreeNode* left;TreeNode* right;TreeNode(int x): val(x), left(nullptr), right(nullptr){}};\n"
    f.write(s)
    f.close()
    back = "C++"
    fileName = name.split('.cc')[0]
else:
    s = "#" + name
    f = open(os.path.join(pwd, name), 'w+', encoding='utf-8')
    f.write(s)
    f.close()
    back = "Python"
# 读取整个文件进入内存
lines = []
# F:\Github\LeetCode
f = open("F:\\Github\\LeetCode\\README.md",
         'r', encoding='utf-8')  # your path!
for line in f:
    lines.append(line)
f.close()

Http = input("please in put your Problem Http path:")
diff = input("please in put your Problem diff:")
cate = input("please in put your Problem cate:")

line = lines[6]
strs = line.split('|')
Number = int(strs[1])+1
print(Number)
#字符串拼接
print("-------------------------------------------------")
print(name)
stringToInsert = ""
stringToInsert += "|" + str(Number) + "|"
stringToInsert += "[" + fileName + "]" + "(" + Http + ") |"
stringToInsert += "[" + back + "]" + "("+ os.path.join(path,name).replace('\\','/') + ") |"
stringToInsert += diff + "|"
stringToInsert += cate + "|\n"
print(stringToInsert)
lines.insert(6,stringToInsert)
s = ''.join(lines)
f=open("F:\\Github\\LeetCode\\README.md", 'w+', encoding='utf-8')  # 重新写入文件
f.write(s)
f.close()
del lines[:]  # 清空列表
