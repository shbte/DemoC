### 学习C/C++语言时的个人练习代码

> [笔记](https://github.com/shbte/Practice/blob/master/noteC.txt)

~~~
编译命令:
1、手动编译
    g++ *.cpp example/*.cpp example/src/*.cpp work/*.cpp work/src/*.cpp -Iinclude -o build/g_main -g

2、cmake编译
    1、
        cd build
        cmake ..
        make
    2、
        cmake -S . -B build
        cd build
        make

构建环境
    系统：ubuntu22
    编辑器：vscode
    编译器：g++
~~~