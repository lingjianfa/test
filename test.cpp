#define H2UNIT_IMPORT_MAIN

#include "h2unit.h"


CASE(malloc faulty injection successful [pass])
{
   BLOCK(limit = 10)
   {
      auto a1 = malloc(11);

      std::cout << h2::h2_cxa::type_name<decltype(a1)>() << std::endl;

      OK(NULL, a1);
   }
}
