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