#include <stdio.h>

static int func_estatica()
{
  puts("func_estatica\n");
}

int func_no_estatica()
{
  puts("func_no_estatica\n");

  func_estatica(); // OK: Llamada dentro de la misma unidad de compilacion
}
