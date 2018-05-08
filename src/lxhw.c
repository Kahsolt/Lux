#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "lxhw.h"
#include "lxaux.h"

void luxH_init()
{
  ROM = malloc(LUX_ROM_SIZE);
  if (!ROM)
    luxX_error("Where's the ROM?");
  memset(ROM, 0x0, LUX_ROM_SIZE);
  RAM = malloc(LUX_RAM_SIZE);
  if (!RAM)
    luxX_error("I can't find my RAM right now...");
  memset(RAM, 0x0, LUX_RAM_SIZE);

  PSW.ZRO = PSW.NEG = PSW.CRY = PSW.OVF = 0;
  PC = IR = 0x00;
  SP = 0xFF;
  AX = BX = CX = DX = 0;

#ifdef LUX_DEBUG
  luxX_info("Lux machine setup OK.");
#endif
}

void luxH_dump()
{
  int addr = 0x00, i;
  printf("[ROM]\n");
  while (addr < LUX_ROM_SIZE) {
    printf("  %04x", addr);
    for(i=0 ; i<16 && addr < LUX_ROM_SIZE; i++) {
      printf(" %02x", ROM[addr]);
      addr += 1;
    }
    printf("\n");
  }
  printf("\n");

  addr = 0x00;
  printf("[RAM]\n");
  while (addr < LUX_RAM_SIZE) {
    printf("  %04x", addr);
    for(i=0 ; i<16 && addr < LUX_RAM_SIZE; i++) {
      printf(" %02x", RAM[addr]);
      addr += 1;
    }
    printf("\n");
  }
  printf("\n");

  luxH_coredump();
}

void luxH_coredump()
{
  printf("[SYS] PC=0x%02X IR=0x%02X DT=%d\n", PC, IR, DT);
  printf("      ZRO=%d CRY=%d NEG=%d OVF=%d\n", PSW.ZRO, PSW.CRY, PSW.NEG, PSW.OVF);
  printf("[USR] AX=%d BX=%d CX=%d DX=%d SP=0x%02X\n", AX, BX, CX, DX, SP);

  printf("\n");
}