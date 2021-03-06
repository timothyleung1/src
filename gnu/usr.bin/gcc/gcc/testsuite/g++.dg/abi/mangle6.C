/* Check that __int128 types are mangled.  */
/* { dg-do compile { target mips64*-*-* mipsisa64*-*-* } } */

typedef int int128 __attribute__ ((mode(TI)));
typedef unsigned int uint128 __attribute__ ((mode(TI)));

struct S
{
  int128 i;
  int128 func1 (int128) const { return i; }
  uint128 func2 (uint128) const { return i; }
};

int128 (S::*ptr1) (int128) const = &S::func1;
uint128 (S::*ptr2) (uint128) const = &S::func2;

/* { dg-final { scan-assembler _ZNK1S5func1En } } */
/* { dg-final { scan-assembler _ZNK1S5func2Eo } } */
