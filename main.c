#include <stdio.h>

int add(int i, int j)
{
  int res = 0;
  __asm ("ADD %[result], %[input_i], %[input_j]"
    : [result] "=r" (res)
    : [input_i] "r" (i), [input_j] "r" (j)
  );
  return res;
}

int main(void)
{
  int a = 1;
  int b = 2;
  int c = 0;

  c = add(a,b);


  printf("Result of %d + %d = %d\n", a, b, c);

  __asm ("MOVN x13, #0x0c00, lsl #0x10");
  __asm ("ROR x13, x13, #0x20");
  //__asm ("LSL x13, x13, #0x20");
  //__asm ("ORR x13, x13, #0xffffffff");
  __asm ("MOVN x12, #0xabcd");
  __asm ("AND x12, x12, x13");
  return 0;
}
