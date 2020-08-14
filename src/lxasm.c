#include <stdio.h>
#include <string.h>
#include "lxhw.h"
#include "lxaux.h"

void luxC_assemble(char *fn)
{
  FILE *fp = fopen(fn, "rb");
  if (!fp) luxX_error("File is broken...");

  char cmd[21];
  LUX_BYTE* p = ROM;
  while (fgets(cmd, sizeof(cmd), fp) != NULL) {
    char inst[4], op1[4], op2[4];
    sscanf(cmd, "%s%s, %s", inst, op1, op2);
    printf("%s %s, %s\n", inst, op1, op2);
    if (!strcmp(inst, "HLT")) {
      *p++ = 0x00;
    } else if (!strcmp(inst, "NOP")) {
      *p++ = 0x01;
    } else if (!strcmp(inst, "RED")) {
      *p++ = 0x02;
    } else if (!strcmp(inst, "WRT")) {
      *p++ = 0x03;
    }
  }

  fclose(fp);

#ifdef LUX_DEBUG
  luxX_info("Program asssmebled and burnt to ROM!");
#endif
}