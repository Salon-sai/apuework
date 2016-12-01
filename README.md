不超出整理，但形式多样，可能有编程题

# Project(10分)
- API case化，
- posix标准中哪些不流行哪些流行？
- posix接口如何整理成人和机器都看得懂的数据结构

# big data
- 概念

# energy
- io

# 实践类型
- 不增加

# kernel
- 不增加
- 增加项目相关内容

# ML
- DL and Distribution

# 代码分析
- 流程控制，代码分析

---
数据缓存
一致性
事务处理
异步同步
编程or论述

> 时区导致的文件时间属性变化问题, 大规模环境下时间戳问题

> 用例分析，case分析,api组织


# 考试
- 18周周二左右
- 英文题目，中文答题
- 考试成绩60%，论文20%，项目20%
- 光盘
  - 论文
    - 学号+姓名
      - 论文，PPT，相关资料，论文总结
  - project
    - 学号+姓名
      - project总结报告
      - 相关资料：源代码，收集资料，相关文件
  - 论文评分
  - Project评分

# 题型
- 名词解释(30)
- 简答题(30)
- 计算，阅读，编程

# 课本
- 文件系统
- `进程概念`
  - 进程环境：main函数和函数变量，命令行参数
  - 进程控制：权限控制图，七个id的变化，real usr id, effective user id, saved set-user-id, exec函数导致的id变更
  - 进程启动，终止过程，exit handler概念，进程状态变更图
  - 僵尸进程
  - 退出前函数现场清理
  - `函数内存布局`
    - 上下文，code,data,stack,heap
    - `setjmp(), longjmp()`
    - cmd_add(), 压栈
    - 函数退出，退栈
    - `缓冲区溢出攻击（概念）`：函数调用时，将pc指针指向新的地址，将旧地址压栈，堆栈用于保存返回地址，在返回时返回地址，但放入很大的动态数据时，heap部分的数据就可能覆盖掉stack部分数据，导致pop时返回不正确的地址，或者用缓冲区跟踪旧程序的运行规律，将返回地址修改为恶意代码地址，运行恶意程序，被称为缓冲区溢出攻击。

- Unix时间
- 静态库与动态库的区别（shell是动态库）
- 库的装载：编译时编入程序即为静态库，编译时仅告诉程序库的路径，运行时动态加载，则称为动态库，或share library。
- 自动变量，自动变量，生命周期变量
- 概念：getrlimit, setrlimit()，limit
- pid
- fork
- 文件共享概念
- 父子进程的文件表（图）
- race condition
- dumpup 代码 信号量 实现：进行资源同步复制时，先dump再up
- 常见example
- 概念：什么是shell程序
- 概念：可执行文件的格式：可以是二进制文件（属性定义为exec），文本文件（脚本语言）,需要定义可执行，解释器
- 进程时间
- 进程间关系
- 终端 - 登录 - 登录时的用户id变化 - 终端交互时前后端（控制终端）
- 网络登录
- 进程组，组长限制条件与变迁
- 会话
- 作业，作业控制
- 孤儿进程，孤儿进程组
- 信号的概念，为什么信号叫做软中断，为什么过去的信号是不可靠的，如何做到信号的可靠性（信号屏蔽挂起处理，函数的可重入，线程安全的函数，函数隔离线程）
- 信号编程的三种模式：忽略，缺省，手动关联到一个函数（exec时关联失效）
- 线程实现模式：内核级，用户级，轻量级，重量级
- 线程与进程的比较
- 如何保护线程间的私有属性（pc，堆栈，调度信息），内核级：放在内核，用户级：放到runtime空间
- 线程的属性api，包括clone
- 同步互斥api
- 线程属性如何控制：私有变量等
- IPC:管道，消息队列，信号量：api实现事务语义
- 事务概念与操作
- socket：网络通讯代码，api，伪代码
