7.1.4 GCC编译C/C++的四个过程（面试）
预处理
gcc -E main.c -o main.i
编译阶段
gcc -S main.i -o main.s
汇编阶段
gcc -c main.s -o main.o
链接阶段
gcc main.o -o main.exe

预处理:
展开头文件，宏定义，条件编译处理
预处理阶段会把引用的头文件插入到我们本身的代码中，会把所有的宏定义替换掉，所有的注释取消，条件编译不符合的不进行编译。
编译:
编译器来检查代码的规范性，语法错误等，检查无误后编译器会把代码编译成汇编代码
汇编：
汇编阶段把.s 文件翻译成二进制指令文件
链接
链接函数库，生成可执行文件

7.1.5 函数库分为静态库和动态库
静态库
这类库的名字一般是libxxx.a；
静态函数库编译成的文件比较大，因为整个函数库的所有数据都会被整合进目标代码中，他的优点就显而易见了，即编译后的执行程序不需要外部的函数库支持.当然这也会成为他的缺点，因为如果静态函数库改变了，那么你的程序必须重新编译。

动态库
这类库的名字一般是libxxx.so;相对于静态函数库，动态函数库在编译的时候 并没有被编译进目标代码中，你的程序执行到相关函数时才调用该函数库里的相应函数，因此动态函数库所产生的可执行文件比较小。由于函数库没有被整合进你的程序，而是程序运行时动态的申请并调用，所以程序的运行环境中必须提供相应的库。动态函数库的改变并不影响你的程序，所以动态函数库的升级比较方便

windows 平台
1 .dll：动态链接，作为共享函数库的可执行文件
2 .obj：目标文件，相当于源代码对应的二进制文件，为经过重定义
3 .lib：可理解为多个 obj 的集合，本质与 .obj 相同
linux 平台
1 .so ：（shared ojbect）动态链接库，和windows上 dll类似
2 .o：目标文件
3 .a：与.o类似，多个.o 的集合，类似windows 下lib
Android如何配置cmakelist.txt 配置编译动态库和静态库呢
————————————————
版权声明：本文为CSDN博主「一夜空中最亮的星一」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_41477306/article/details/123617609

