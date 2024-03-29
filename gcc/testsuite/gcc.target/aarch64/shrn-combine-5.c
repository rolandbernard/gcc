/* { dg-do assemble } */
/* { dg-options "-O3 --save-temps --param=vect-epilogues-nomask=0" } */

#define TYPE1 char
#define TYPE2 short
#define SHIFT 8

void foo (TYPE2 * restrict a, TYPE1 * restrict d, int n)
{
    for( int i = 0; i < n; i++ )
      d[i] = a[i] >> SHIFT;
}

/* { dg-final { scan-assembler-times {\tuzp2\t} 1 } } */
/* { dg-final { scan-assembler-not {\tshrn\t} } } */
/* { dg-final { scan-assembler-not {\tshrn2\t} } } */
