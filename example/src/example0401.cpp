#include <stdio.h>

/*
    ==>
        char(1字节=1*8位)类型的无符号和有符号溢出时取值情况。
        中间量：0x80(0B1000 0000)(无符号：128，有符号：-128)
        最大量：0xFF(0B1111 1111)(无符号：255，有符号：-1)
    <==
*/
void example0401()
{
    printf("=====example0401()=====\n");

    // char
    // 中间量：0x80(0B1000 0000)(128)
    // 最大量：0xFF(0B1111 1111)(255)
    unsigned char u = 255;    //无符号：0-255
    char c = 129;             //有符号（有负号）： 0-127  -1 到 -128
    // u=255    c=-127，这里出现-127的原因是0~126、127、-128(-0=1000 0000)、-127、-126~-1
    // 129mod256=(-127)
    printf("u=%d\t c=%d\n", u, c);

    u = 0x8887F;         //溢出 之后只留1个字节    0x8887Fmod256=127
    c = 0x88877F;        //溢出                 0x88877Fmod256=127
    // u=127    c=127
    printf("u=%d\t c=%d\n", u, c);

    u = 256;             //0x100 //溢出
    c = 256;            // 256mod256=0
    // u=0      c=0
    printf("u=%d\t c=%d\n", u, c);

    u = 511;                //0x1FF    511mod256=255
    c = 511;                //0x1FF    511mod256=(-1)
    // u=255    c=-1
    printf("u=%d\t c=%d\n", u, c);

    u = u + 1;    
    c = c + 1;    // 512mod256=0
    // u=0      c=0
    printf("u=%d\t c=%d\n", u, c);

    u = 250;    
    c = 250;    // 250mod256=(-6)
    // u=250    c=-6
    printf("u=%d\t c=%d\n", u, c);

    u = -1; //-1+256    (-1)mod256=255
    c = -1;
    // u=255    c=-1
    printf("u=%d\t c=%d\n", u, c);
}