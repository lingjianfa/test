#define H2UNIT_IMPORT_MAIN

#include "h2unit.h"


CASE(malloc faulty injection successful [pass])
{
   // BLOCK(limit = 10)
   // {
   //    auto a1 = (char*)malloc(11);

   //    std::cout << h2::h2_cxa::type_name<decltype(a1)>() << std::endl;

   //    OK(NULL, a1);
   // }

   auto a1 = NULL;

      std::cout << h2::h2_cxa::type_name<decltype(a1)>() << std::endl;

h2::h2_stringify (NULL) ;
}

SUITE()
{

   Case(char*)
   {
      char* a = (char*)"hello world";
      OK("hello world", h2::h2_stringify<char*>(a));
      OK(ListOf("\033{+dark gray}", "\"", "\033{-dark gray}",
                "hello world",
                "\033{+dark gray}", "\"", "\033{-dark gray}"),
         h2::h2_stringify<char*>(a, true));
   }

   Case("char[]")
   {
      char a[100];
      strcpy(a, "hello world");

      OK("hello world", h2::h2_stringify(a));
      OK(ListOf("\033{+dark gray}", "\"", "\033{-dark gray}",
                "hello world",
                "\033{+dark gray}", "\"", "\033{-dark gray}"),
         h2::h2_stringify(a, true));
   }

   Case(char* null)
   {
      char* a = nullptr;
      OK(ListOf("(null)"), h2::h2_stringify<char*>(a));
   }

   Case(const char* null)
   {
      const char* a = nullptr;
      OK(ListOf("(null)"), h2::h2_stringify<const char*>(a));
   }

}