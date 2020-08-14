#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "lxhw.h"
#include "lxaux.h"

void luxH_init()
{
  ROM = malloc(LUX_ROM_SIZE);
  if (!ROM) luxX_error("Where's the ROM?");
  memset(ROM, 0x00, LUX_ROM_SIZE);
  RAM = malloc(LUX_RAM_SIZE);
  if (!RAM) luxX_error("I can't find RAM right now...");
  memset(RAM, 0x00, LUX_RAM_SIZE);

  memset(&PSW, 0x00, sizeof(PSW));
  PC = IR = 0x00; DT = 0;
  AX = BX = CX = DX = 0;
  SP = 0xFF;

#ifdef LUX_DEBUG
  luxX_info("Lux machine setup & init OK.");
#endif
}

void luxH_dump(int verbose)
{
  if (!verbose) goto NO_VERBOSE;

  int addr = 0x00, i;
  printf("[ROM]\n");
  while (addr < LUX_ROM_SIZE) {
    printf("  %04x", addr);
    for (i=0; i<16 && addr < LUX_ROM_SIZE; i++) {
      printf(" %02x", ROM[addr]);
      addr++;
    }
    putchar('\n');
  }
  putchar('\n');

  addr = 0x00;
  printf("[RAM]\n");
  while (addr < LUX_RAM_SIZE) {
    printf("  %04x", addr);
    for (i=0; i<16 && addr < LUX_RAM_SIZE; i++) {
      printf(" %02x", RAM[addr]);
      addr++;
    }
    putchar('\n');
  }
  putchar('\n');

NO_VERBOSE:
  printf("[SYS] PC=0x%02X IR=0x%02X DT=%d\n", PC, IR, DT);
  printf("      ZRO=%d CRY=%d NEG=%d OVF=%d\n", PSW.ZRO, PSW.CRY, PSW.NEG, PSW.OVF);
  printf("[USR] AX=%d BX=%d CX=%d DX=%d SP=0x%02X\n", AX, BX, CX, DX, SP);

  putchar('\n');
}