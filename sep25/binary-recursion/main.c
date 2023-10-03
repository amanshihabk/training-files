#include <stdio.h>
#ifdef BY_REF
#include "bit-changes-by-ref.h"
#else
#include "bit-changes-by-val.h"
#endif

#define NUM1 5
#define NUM2 -35
#define MASK 128

void print_holder(int8_t value)
{
    printf("\nThe value of holder now is %hhd.\n", value);
}

int main()
{
   int8_t holder = NUM1;
   int8_t neg_holder = NUM2;
   /*
      holder in binary = 0000 0101 -> 5
      Set bit 1 in NUM1 = 0000 0111 -> 7
   */
   print_holder(holder);
   #ifdef BY_REF
   set_nth_bit(&holder, 1);
   printf("\nSetting bit 1 of holder by reference = %hhd\nIn binary : ", holder);
   print_in_binary(&holder, MASK);
   #else
   holder = set_nth_bit(holder, 1);
   printf("\nSetting bit 1 of holder by value = %hhd\nIn binary : ", holder);
   print_in_binary(holder, MASK);
   #endif

   /*
      holder in binary = 0000 0101 -> 5
      clear bit 0 in NUM1 = 0000 0100 -> 4
   */
   holder = NUM1;
   print_holder(holder);
   #ifdef BY_REF
   clear_nth_bit(&holder, 0);
   printf("\nClearing bit 0 of holder by referce = %hhd\nIn binary : ", holder);
   print_in_binary(&holder, MASK);
   #else
   holder = clear_nth_bit(holder, 2);
   printf("\nClearing bit 2 of holder by value = %hhd\nIn binary : ", holder);
   print_in_binary(holder, MASK);
   #endif

   /*
      holder in binary = 0000 0101 -> 5
      swap bit 0 and 4 in NUM1 = 0001 0100 -> 20
   */
   holder = NUM1;
   print_holder(holder);
   #ifdef BY_REF
   swap_bits(&holder, 0, 4);
   printf("\nSwapping bit 0 and 4 of holder by referce = %hhd\nIn binary : ", holder);
   print_in_binary(&holder, MASK);
   #else
   holder = swap_bits(holder, 0, 4);
   printf("\nSwapping bit 0 and 4 of holder by value = %hhd\nIn binary : ", holder);
   print_in_binary(holder, MASK);
   #endif

   /*
      holder in binary = 0000 0101 -> 5
      toggling bit 6 = 0100 0100 -> 68
   */
   holder = NUM1;
   print_holder(holder);
   #ifdef BY_REF
   toggle_nth_bit(&holder, 6);
   printf("\nToggling bit 6 of holder by referce = %hhd\nIn binary : ", holder);
   print_in_binary(&holder, MASK);
   #else
   holder = toggle_nth_bit(holder, 6);
   printf("\nToggling bit 6 of holder by value = %hhd\nIn binary : ", holder);
   print_in_binary(holder, MASK);	
   #endif

   /*
      holder in binary = 1110 1001 -> -23
      toggling signs = 0001 0111-> 23
   */
   holder =  -1 * NUM2;
   print_holder(holder);
   #ifdef BY_REF
   flip_sign(&holder);
   printf("\nFlipping sign of holder by referce = %hhd\nIn binary : ", holder);
   print_in_binary(&holder, MASK);
   #else
   holder = flip_sign(holder);
   printf("\nFlipping sign of holder by value = %hhd\nIn binary : ", holder);
   print_in_binary(holder, MASK);
   #endif

   return 0;
}
