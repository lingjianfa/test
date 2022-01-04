#define H2UNIT_IMPORT_MAIN

#include "h2unit.h"

SUITE(a)
{
   Case(ab)
   {
      printf("Hello Docker\n");
      std::cout << "Hello H2unit" << std::endl;
      OK(1, 2);
   }
}
