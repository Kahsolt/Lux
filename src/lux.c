#include "lxhw.h"
#include "lxrt.h"
#include "lxasm.h"
#include "lxaux.h"

#define LUX_DEBUG
#define LUX_PROG_FN "prog.asm"

int main(int argc, char *argv[])
{
  luxH_init();

  if (argc > 2) luxX_help();
  else if (argc == 2) luxC_assemble(argv[1]);
  else luxC_assemble(LUX_PROG_FN);

  while (luxR_fetch())
    if(!luxR_execute()) break;

#ifdef LUX_DEBUG
  luxH_coredump();
#endif

  return 0;
}