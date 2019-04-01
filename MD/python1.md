# 环境搭建
    anaconda环境配置
    Anaconda安装与环境配置Anaconda 是一个包含数据科学常用包的 Python 发行版本。它基于 conda ——一个包和环境管理器——衍生而来。你将使用 conda 创建环境，以便分隔使用不同 Python 版本和不同程序包的项目。你还将使用它在环境中安装、卸载和更新包。通过使用 Anaconda，处理数据的过程将更加愉快。
    解释器（英语：Interpreter），又译为直译器，是一种电脑程序，能够把高级编程语言一行一行直接转译运行。解释器不会一次把整个程序转译出来，只像一位“中间人”，每次运行程序时都要先转成另一种语言再作运行，因此解释器的程序运行速度比较缓慢。它每转译一行程序叙述就立刻运行，然后再转译下一行，再运行，如此不停地进行下去。
# python基础讲解
## python变量特性
    python是一个脚本语言与静态语言不同，一行一行直接转译运行，变量名不能包含空格，但可使用下划线来分隔其中的单词。例如，变量名greeting_message可行，但变量名greeting message会引发错误。
    不要将Python关键字和函数名用作变量名，即不要使用Python保留用于特殊用途的单词，如print。
    

## 命名规则
    变量名应既简短又具有描述性。例如，name比n好，student_name比s_n好，name_length比length_of_persons_name好。
        慎用小写字母l和大写字母O，因给他们可能被人错看成数字1和0；
## 注释
    井号(#)常被用作单行注释符号，在代码中使用#时，它右边的任何数据都会被忽略，当做是注释。
    print 1 #输出1
    #号右边的内容在执行的时候是不会被输出的。
## python中“：”作用
    “：”一般在在函数定义语句、for语句、while语句、if语句、类定义等后面使用，也可以用于切片a[::-1] 表示把列表内容倒序输出
## 数据结构
    Number（数字）、String（字符串）、List（列表）、Tuple（元组）、Set（集合）、Dictionary（字典）
    顺序容器，关联容器，链表。

# Python 运算符


    位运算 | & >> << 和C语言的一样
    and = && ,or == ||  ,not in, in ; 
    not in 在刷题的时候 当元素在后面的集合内返回true 否则 false

    身份运算符
        is 是判断两个标识符是不是引用自一个对象
        is not 是判断两个标识符是不是引用自不同对象

    举个🌰
~~~
    result = []
        for i in nums1:
            if i in nums2 and i not in result:
                result.append(i)
        return result 
~~~

## inport

Python语言中import的使用很简单，直接使用import module_name语句导入即可。

~~~
# 导入一个模块
import model_name
# 导入多个模块
import module_name1,module_name2
# 导入模块中的指定的属性、方法（不加括号）、类
from moudule_name import moudule_element [as new_name]
~~~






