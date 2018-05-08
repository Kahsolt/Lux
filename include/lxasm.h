/*
Lux指令结构 = 5bit指令主类 + 2bit目标寄存器 + 1bit方向指示位
(尽量设计为单字节指令)

*5bit指令主类:
00000	HLT		// 000* 设备控制
00001	NOP
00010	RED r
00011	WRT r
00100	MOV r/m,m/r	// 001* 数据传送
00101	MOV r,r
00110	LEA r/m,r/m/i
00111
01000	PSH r/m/i
01001	POP r/m
01010
01011
01100	JMP m		// 011* 跳转
01101	JPC m
01110
01111
10000	ADD r,r/m/i	// 10* 代数运算
10001	SUB r,r/m/i
10010	MUL r,r/m/i
10011	DIV r,r/m/i
10100	INC r/m
10101	NEG r/m
10110
10111
11000	NOT r/m		// 11* 逻辑运算
11001	AND r,r/m/i
11010	IOR r,r/m/i
11011	XOR r,r/m/i
11100	LSH r,r/m/i
11101	RSH r,r/m/i
11110
11111

2bit目标寄存器:
 00 AX
 01 BX
 10 CX
 11 DX

1bit数据指示位:
 0	单字节指令；从r到m
 1	双字节指令，后一个byte为数据；从m到r

*/

void luxC_assemble(char* fn);