#ifndef LUX_LXHW_H
#define LUX_LXHW_H

/* Types */
typedef unsigned char LUX_BYTE; /* Lux机器字长，8bit */

/* Constants */
#define LUX_ROM_SIZE 1024 /* 1024byte rom disk; 000H~3FFH */
#define LUX_RAM_SIZE 256  /* 256byte ram memory; 00H~FFH */

/* Hardware */
LUX_BYTE* ROM;  /* 程序内存; 程序从 000H 开始执行　*/
LUX_BYTE* RAM;  /* 数据内存; 默认栈顶在 FFH */

/* Sys Register */
struct psw /* 程序状态字 */
{
  LUX_BYTE CRY : 1; /* 进位 */
  LUX_BYTE NEG : 1; /* 为负 */
  LUX_BYTE OVF : 1; /* 溢出 */
  LUX_BYTE ZRO : 1; /* 为零 */
} PSW;
LUX_BYTE PC; /* 程序计数器/下一条指令指针 */
LUX_BYTE IR; /* 当前指令缓存 */
LUX_BYTE DT; /* 当前数据缓存 */

/* User Register */
LUX_BYTE AX; /* 累加 */
LUX_BYTE BX; /* 基址 */
LUX_BYTE CX; /* 计数 */
LUX_BYTE DX; /* 数据 */
LUX_BYTE SP; /* 栈指针 */
static LUX_BYTE* REGS[4] = {&AX, &BX, &CX, &DX};

void luxH_init();
void luxH_dump();
void luxH_coredump();

#endif //LUX_LXHW_H