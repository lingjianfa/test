#define H2UNIT_IMPORT_MAIN

#include "h2unit.h"


class A_AbstractClass {
 public:
   char a;

   A_AbstractClass() : a('a') {}

 private:
   static const char* static_f1(int x) { return sprintf(buffer, "A.static_f1(%d)", x), buffer; }
   const char* normal_f1(int x) { return sprintf(buffer, "A.normal_f1(%d)%c", x, a), buffer; }
   virtual const char* virtual_f1(int x) { return sprintf(buffer, "A.virtual_f1(%d)%c", x, a), buffer; }
   virtual const char* pure_f0() = 0;
};

class B_DerivedClass : public A_AbstractClass {
 public:
   char b;
   char* s;

   B_DerivedClass() : b('b') { s = (char*)malloc(11); }
   virtual ~B_DerivedClass() { free(s); }

 private:
   static const char* static_f2(int x, int y) { return sprintf(buffer, "B.static_f2(%d,%d)", x, y), buffer; }
   const char* normal_f2(int x, int y) { return sprintf(buffer, "B.normal_f2(%d,%d)%c", x, y, b), buffer; }
   virtual const char* virtual_f2(int x, int y) { return sprintf(buffer, "B.virtual_f2(%d,%d)%c", x, y, b), buffer; }
   virtual const char* pure_f0() { return sprintf(buffer, "B.pure_f0()%c", b), buffer; }
};

class C_OverrideClass : public A_AbstractClass {
 public:
   char c;
   std::string s;

   C_OverrideClass() : c('c'), s(10000, 's') {}
   virtual ~C_OverrideClass() {}

 private:
   static const char* static_f1(int x) { return sprintf(buffer, "C.static_f1(%d)", x), buffer; }
   static const char* static_f2(int x, int y) { return sprintf(buffer, "C.static_f2(%d,%d)", x, y), buffer; }

   const char* normal_f1(int x) { return sprintf(buffer, "C.normal_f1(%d)%c", x, c), buffer; }
   const char* normal_f2(int x, int y) { return sprintf(buffer, "C.normal_f2(%d,%d)%c", x, y, c), buffer; }

   virtual const char* virtual_f1(int x) { return sprintf(buffer, "C.virtual_f1(%d)%c", x, c), buffer; }
   virtual const char* virtual_f2(int x, int y) { return sprintf(buffer, "C.virtual_f2(%d,%d)%c", x, y, c), buffer; }

   virtual const char* pure_f0() { return sprintf(buffer, "C.pure_f0()%c", c), buffer; }
};

class D_NoConstructorClass : public B_DerivedClass, public C_OverrideClass {
 public:
   char d;
   D_NoConstructorClass() = delete;
   D_NoConstructorClass(int, int, int, int, int, int, int, int, int, int, int) : d('d') {}

 private:
   static const char* static_f1(int x) { return sprintf(buffer, "D.static_f1(%d)", x), buffer; }
   static const char* static_f2(int x, int y) { return sprintf(buffer, "D.static_f2(%d,%d)", x, y), buffer; }

   static const char* static_f3(int x, int y, int z) { return sprintf(buffer, "D.static_f3(%d,%d,%d)", x, y, z), buffer; }

   const char* normal_f1(int x) { return sprintf(buffer, "D.normal_f1(%d)%c", x, d), buffer; }
   const char* normal_f2(int x, int y) { return sprintf(buffer, "D.normal_f2(%d,%d)%c", x, y, d), buffer; }
   const char* normal_f3(int x, int y, int z) { return sprintf(buffer, "D.normal_f3(%d,%d,%d)%c", x, y, z, d), buffer; }

   virtual const char* virtual_f1(int x) { return sprintf(buffer, "D.virtual_f1(%d)%c", x, d), buffer; }
   virtual const char* virtual_f2(int x, int y) { return sprintf(buffer, "D.virtual_f2(%d,%d)%c", x, y, d), buffer; }
   virtual const char* virtual_f3(int x, int y, int z) { return sprintf(buffer, "D.virtual_f3(%d,%d,%d)%c", x, y, z, d), buffer; }
};

namespace test_ns {
class E_NamespaceClass : public A_AbstractClass {
 public:
   char e;
   E_NamespaceClass() : e('e') {}
   virtual ~E_NamespaceClass() {}

 private:
   virtual const char* pure_f0() { return sprintf(buffer, "E.pure_f0()%c", e), buffer; }
};
}

static const char* A_normal_f1_fake(A_AbstractClass* This, int x) { return sprintf(buffer, "-A.normal_f1(%d)%c", x, This->a), buffer; }
static const char* A_virtual_f1_fake(A_AbstractClass* This, int x) { return sprintf(buffer, "-A.virtual_f1(%d)%c", x, This->a), buffer; }
static const char* B_static_f1_fake(int x) { return sprintf(buffer, "-B.static_f1(%d)", x), buffer; }
static const char* B_normal_f1_fake(B_DerivedClass* This, int x) { return sprintf(buffer, "-B.normal_f1(%d)%c", x, This->b), buffer; }
static const char* B_normal_f2_fake(B_DerivedClass* This, int x, int y) { return sprintf(buffer, "-B.normal_f2(%d,%d)%c", x, y, This->b), buffer; }
static const char* B_virtual_f1_fake(B_DerivedClass* This, int x) { return sprintf(buffer, "-B.virtual_f1(%d)%c", x, This->b), buffer; }
static const char* B_virtual_f2_fake(B_DerivedClass* This, int x, int y) { return sprintf(buffer, "-B.virtual_f2(%d,%d)%c", x, y, This->b), buffer; }
static const char* C_normal_f1_fake(C_OverrideClass* This, int x) { return sprintf(buffer, "-C.normal_f1(%d)%c", x, This->c), buffer; }
static const char* C_virtual_f1_fake(C_OverrideClass* This, int x) { return sprintf(buffer, "-C.virtual_f1(%d)%c", x, This->c), buffer; }
static const char* D_virtual_f3_fake(D_NoConstructorClass* This, int x, int y, int z) { return sprintf(buffer, "-D.virtual_f3(%d,%d,%d)%c", x, y, z, This->d), buffer; }
static const char* E_virtual_f1_fake(test_ns::E_NamespaceClass* This, int x) { return sprintf(buffer, "-E.virtual_f1(%d)%c", x, This->e), buffer; }

template <typename T>
struct F_TemplateClass {
   char f = 'f';
   virtual ~F_TemplateClass() {}
   static const char* static_f1(T x) { return sprintf(buffer, "F.static_f1(%d)", x), buffer; }
   template <typename U>
   const char* normal_f1(U x) { return sprintf(buffer, "F.normal_f1(%d)%c", x, f), buffer; }
   virtual const char* virtual_f1(T x) { return sprintf(buffer, "F.virtual_f1(%d)%c", x, f), buffer; }
};

template <typename T1, typename T2>
struct G_TemplateClass {
   char g = 'g';
   T1 G = 7;
   template <typename U1, typename U2>
   static const char* static_f2(U1 x, U2 y) { return sprintf(buffer, "G.static_f2(%d,%d)", x, y), buffer; }
   template <typename U1, typename U2>
   const char* normal_f2(U1 x, U2 y) { return sprintf(buffer, "G.normal_f2(%d,%d)%c", x, y, g), buffer; }
   template <typename U1, typename U2>
   std::pair<const char*, double> virtual_f2(U1 x, U2 y) { return std::make_pair("G.virtual_f2", x * 10 + y + G / 10.0); }
};

static const char* F_static_f1_fake(int x) { return sprintf(buffer, "-F.static_f1(%d)", x), buffer; }
static const char* F_normal_f1_fake(F_TemplateClass<int>* This, int x) { return sprintf(buffer, "-F.normal_f1(%d)%c", x, This->f), buffer; }
static const char* F_virtual_f1_fake(F_TemplateClass<int>* This, int x) { return sprintf(buffer, "-F.virtual_f1(%d)%c", x, This->f), buffer; }
static const char* G_static_f2_fake(int x, int y) { return sprintf(buffer, "-G.static_f2(%d,%d)", x, y), buffer; }
static const char* G_normal_f2_fake(G_TemplateClass<int, int>* This, int x, int y) { return sprintf(buffer, "-G.normal_f2(%d,%d)%c", x, y, This->g), buffer; }
static std::pair<const char*, double> G_virtual_f2_fake(G_TemplateClass<int, int>* This, int x, int y) { return std::make_pair("-G.virtual_f2", x * 10 + y + This->G / 10.0); }


SUITE(mock member function)
{
   B_DerivedClass b;

   Case(static member function)
   {
      MOCK(B_DerivedClass::static_f2, const char*(int a, int b)).Once(1, 2).Return("+B.static_f2");
      OK("+B.static_f2", B_DerivedClass::static_f2(1, 2));
   }
}
