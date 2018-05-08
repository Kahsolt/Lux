#include <stdio.h>
#include "lxhw.h"
#include "lxrt.h"

int luxR_fetch()
{
  if(PC < LUX_ROM_SIZE) {
    IR = ROM[PC++];
    return 1;
  } else {
    return 0;
  }
}

int luxR_execute() {
  if(IR == 0x00) {
    return 0;
  } else if(IR == 0x01) {
    ;
  } else if(IR == 0x01) {
    scanf("%d", &AX);
  } else if(IR == 0x03) {
    printf("%d\n", AX);
  }

  return 1;
}