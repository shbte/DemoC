#include <stdio.h>

/*
	==>
		short(2字节=2*8位)类型的无符号和有符号溢出时取值情况。
		中间量：0x8000(0B1000 0000 0000 0000)(无符号：32768，有符号：-32768)
		最大量：0xFFFF(0B1111 1111 1111 1111)(无符号：65535，有符号：-1)
	<==
*/
void example0402()
{
	printf("=====example0402()=====\n");

	// short 
	// 中间量：0x8000(0B1000 0000 0000 0000)(32768)
	// 最大量：0xFFFF(0B1111 1111 1111 1111)(65535)
	short s = 0xFF;
	unsigned short u = 0xFF;
	// 0xFFmod0x10000=0xFF
	// s=255,u=255
	printf("s=%d,u=%d\n", s, u);

	s = 0x7FFF;
	u = 0x7FFF;
	// 0x7FFFmod0x10000=0x7FFF
	// s=32767,u=32767
	printf("s=%d,u=%d\n", s, u);

	s = s + 1;
	u = u + 1;
	// 0x8000mod0x10000=(-0x8000)，0x8000modmod0x10000=0x8000
	// s=-32768,u=32768
	printf("s=%d,u=%d\n", s, u);

	u = -16;
	s = -16;
	// (-16)mod0x10000=0xFFF0=65520=0xFFF0-0x10000
	// s=-16,u=65520
	printf("s=%d,u=%d\n", s, u);

	u = 65535;
	s = 65535;
	// (65535)mod0x10000=(-1)=0xFFFF-0x10000
	// s=-1,u=65535
	printf("s=%d,u=%d\n", s, u);

	u = 0xabcd;
	s = 0xabcd;
	// 0xabcdmod0x10000=(-21555)=abcd-10000
	// s=-21555,u=43981
	printf("s=%d,u=%d\n", s, u);
}