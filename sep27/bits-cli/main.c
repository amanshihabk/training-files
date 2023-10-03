#include <stdio.h>
#include "bit-changes-by-ref.h"
#include <stdint.h>


#define NUM1 5
#define NUM2 -35
#define MASK 128


int8_t _atoi(int8_t *buff);
void _set_bit_handler(int32_t argc, int8_t **argv);
void _clear_bit_handler(int32_t argc, int8_t **argv);
void _swap_handler(int32_t argc, int8_t **argv);
void _toggle_handler(int32_t argc, int8_t **argv);
void _flip_handler(int32_t argc, int8_t **argv);
void _print_helper();


int main(int32_t argc, int8_t **argv)
{
   if (argc < 2)
   {
      _print_helper();
   }
   else
   {
      switch(_atoi(argv[1]))
      {
         case 1 :    _set_bit_handler(argc, argv);
                     break;

         case 2 :    _clear_bit_handler(argc, argv);
                     break;

         case 3 :    _swap_handler(argc, argv);
                     break;

         case 4 :    _toggle_handler(argc, argv);
                     break;

         case 5 :    _flip_handler(argc, argv);
                     break;

         default :   _print_helper();
      }
   }

   return 0;
}

int8_t _atoi(int8_t *buff)
{
	int8_t num = 0;
	uint32_t i = 0;
	int8_t sign = 1;

	if (buff[i] == '-')
	{
		sign = -1;

		i += 1;
	}
	else
	{
		// Do nothing
	}

	for (; buff[i] != '\0'; i++)
	{
		num = (num * 10) + (buff[i] - '0');
	}

	return sign * num;
}

void _set_bit_handler(int32_t argc, int8_t **argv)
{

   int8_t _num, pos;

   if (argc < 4 || argc > 4)
   {
      printf("\nSet bit usage : executable-name 1 number position-of-bit");
      printf("\nnumber - number whose binary representation is to be manipulated.");
      printf("\nposition-of-bit - the position at which the bit is to be set\n");
   }
   else
   {
      _num = _atoi(argv[2]);
      pos = _atoi(argv[3]);

      printf("\nNum before modifying is : ");
      print_in_binary(&_num);

      set_nth_bit(&_num, pos);

      printf("\nNum after modifying is : ");
      print_in_binary(&_num);
   }
}

void _clear_bit_handler(int32_t argc, int8_t **argv)
{

   int8_t _num, pos;

   if (argc < 4 || argc > 4)
   {
      printf("\nClear bit usage : executable-name 2 number position-of-bit");
      printf("\nnumber - number whose binary representation is to be manipulated.");
      printf("\nposition-of-bit - the position at which the bit is to be set\n");
   }
   else
   {
      _num = _atoi(argv[2]);
      pos = _atoi(argv[3]);

      printf("\nNum before modifying is : ");
      print_in_binary(&_num);

      clear_nth_bit(&_num, pos);

      printf("\nNum after modifying is : ");
      print_in_binary(&_num);
   }
}

void _swap_handler(int32_t argc, int8_t **argv)
{

   int8_t num, pos1, pos2;

   if (argc < 5 || argc > 5)
   {
      printf("\nSwap bit usage : executable-name 3 number position-of-bit1 position-of-bit2");
      printf("\nnumber - number whose binary representation is to be manipulated.");
      printf("\nposition-of-bit1 - the position 1 at which the bit is to be swapped\n");
      printf("\nposition-of-bit2 - the position 2 at which the bit is to be swapped\n");
   }
   else
   {
      num = _atoi(argv[2]);
      pos1 = _atoi(argv[3]);
      pos2 = _atoi(argv[4]);

      printf("\nNum before modifying is : ");
      print_in_binary(&num);

      swap_bits(&num, pos1, pos2);

      printf("\nNum after modifying is : ");
      print_in_binary(&num);
   }
}

void _toggle_handler(int32_t argc, int8_t **argv)
{

   int8_t _num, pos;

   if (argc < 4 || argc > 4)
   {
      printf("\nToggle bit usage : executable-name 4 number position-of-bit");
      printf("\nnumber - number whose binary representation is to be manipulated.");
      printf("\nposition-of-bit - the position at which the bit is to be set\n");
   }
   else
   {
      _num = _atoi(argv[2]);
      pos = _atoi(argv[3]);

      printf("\nNum before modifying is : ");
      print_in_binary(&_num);

      toggle_nth_bit(&_num, pos);

      printf("\nNum after modifying is : ");
      print_in_binary(&_num);
   }
}

void _flip_handler(int32_t argc, int8_t **argv)
{

   int8_t _num;

   if (argc < 3 || argc > 3)
   {
      printf("\nToggle bit usage : executable-name 5 number");
      printf("\nnumber - number whose binary representation is to be manipulated.");
   }
   else
   {
      _num = _atoi(argv[2]);

      printf("\nNum before modifying is : ");
      print_in_binary(&_num);

      flip_sign(&_num);

      printf("\nNum after modifying is : ");
      print_in_binary(&_num);
   }
}

void _print_helper()
{
   printf("\nUsage : executable-name option (operands)+\n");
   printf("\noption :\n1 - set-nth-bit -> two operands : num, pos");
   printf("\n2 - clear-nth-bit -> two operands : num, pos");
   printf("\n3 - swap bits -> three operands : num, pos1, pos2");
   printf("\n4 - toggle-nth-bit -> two operands : num, pos");
   printf("\n5 - flip-sign -> one operand : num\n");
}