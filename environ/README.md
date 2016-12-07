# 进程环境
### 1.进程终止
atexit() 注册当中的函数。
当exit()执行时（return会调用exit()），会调用这些被atexit()注册的函数并且调用的顺序与登记的顺序相反

### 2.命令行参数

```c
int main(int argc, char * argv[])
{
    // 
}
```
argc为参数的个数，*argv[]是参数数组的指针

### 3. 函数setjmp和longjmp
```c
int setjmp(jmp_buf env);

void longjmp(jmp_buf env, int val);
```
    
setjmp与longjmp是同时使用的一组函数。在main函数中，我们直接调用该函数，所以返回值为0。setjmp函数存入的env为全局变量，保存当前的环境信息。longjmp的参数中env为setjmp存入的env用来恢复状态的所有信息，val为setjmp返回的值

在testjmp.c的程序中，我们不使用-O进行优化处理，会发现当中的变量没有变回原来的值，它仍然维持在调用setjmp之后的值。因为它仍然存在于存储器当中，而优化后变量都会存在于寄存器当中。**（存放在存储器中的变量将具有longjmp时的值，而在CPU和浮点寄存器中的变量则恢复为调用setjmp的值）**

### 4.C语言的存储布局

```sh
$ size /usr/bin/cc 
```
| text | data | bss | dec  | hex | filename
| :--: | :--: | :--:| :--: |:--: | :--:  
|902577| 8048 | 9696|920321|e0b01|/usr/bin/cc
> * 正文段(text).程序代码
> * 初始化数据段(data).有初始化值的全局和静态变量
> * 非初始化数据段(bss,block started by symbol).没有初始化值的全局和静态变量，初始化值为0。
> * 栈(stack) **自动变量**以及**每次函数调用时所需保存的信息** **（个人理解为局部变量）**都存在此段中
> * 堆(heap) 通常在堆中进行**动态存储分配**

    栈与堆的组成类型于双向栈的数据结构。如图：
![典型的存储器空间安排][http://s10.sinaimg.cn/orignal/494e45feg8ec9c0576139&690]