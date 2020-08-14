#include <stdio.h>
#include <stdlib.h>
#include "lxaux.h"

void luxX_info(char *msg)
{
  printf("[INFO] %s\n", msg);
}

void luxX_error(char *msg)
{
  printf("[ERRO] %s\n", msg);
  exit(-1);
}

void luxX_help()
{
  printf("Usage: lux <prog.asm>\n");
  exit(0);
}