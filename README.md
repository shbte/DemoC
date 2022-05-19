### 学习C/C++语言时的个人练习代码

> [笔记](noteC.txt)

#### 1、手动编译

~~~bash
g++ *.cpp example/*.cpp example/src/*.cpp work/*.cpp work/src/*.cpp -Iinclude -o build/g_main -g
~~~

#### 2、cmake编译

~~~bash
1、进入中间目录(build)执行
    cd build
    cmake ..
    make
2、可以对cmake制定参数，build是Makefile生成路径
    cmake -S . -B build
    make -C build
~~~

### 构建环境

~~~
编译器：G++
调试器：Gdb
编辑器：Vscode
系统：Ubuntu22
~~~