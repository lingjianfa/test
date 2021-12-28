#define H2UNIT_IMPORT_MAIN

#include "h2unit.h"


CASE(malloc faulty injection successful [pass])
{
   BLOCK(limit = 10 /* in the block , available memory only 10 bytes */)
   {
      OK(NULL, malloc(11)); /* no enough available memory */
   }
}
