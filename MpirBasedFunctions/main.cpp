// Author & Copyright : Peter Luschny
// Created: 2010-01-15
// License: LGPL version 2.1 or (at your option)
// Creative Commons Attribution-ShareAlike 3.0

#include <iostream>
#include <string>
#include <sstream>
#include "test.h"

//  static void msg() {                                  std::cout << std::endl <<
//  "The fastes function is ParallelPrimeSwing. The computing    " << std::endl <<
//  "times of Schoenhage and PrimeSwing are approximately equal. " << std::endl <<
//  "Note that PrimeSwing uses 1/3 less space than Schoenhage's  " << std::endl <<
//  "algorithm. The space requirements in our implementation are " << std::endl <<
//  "2.PrimePi(n) for PrimeSwing and 3.PrimePi(n) for Schoenhage." << std::endl <<
//  "Writing an implementation for large n! without also paying  " << std::endl <<
//  "attention to the required space is pointless."                << std::endl;
//  std::cin.get(); }



static void FactTestN(ulong n,
    bool paralSwing, bool paraSchoen, bool primeSwing, bool schoenhage, bool mp_lib)
{
    Test::FactorialSanityCheck(1000);

    Test::FactorialBenchmark(n,
        paralSwing, paraSchoen, primeSwing, schoenhage, mp_lib);

}

static void FactTest()
{
    Test::FactorialSanityCheck(1000);

  //for(ulong n = 1000000; n < 64000001; n = n*2)
    for(ulong n = 1000000; n < 1000000000; n = n*2)
    {
       Test::FactorialBenchmark(n);
    }

 //Test::FactorialBenchmark(100000000);
   Test::FactorialBenchmark(1000000000);
}

static void DoubleFactTest()
{
    Test::DoubleFactorialSanityCheck(1000);

    for(ulong n = 1000000; n < 64000002; n = n*2)
    {
       Test::DoubleFactorialBenchmark(n);
       Test::DoubleFactorialBenchmark(n+1);
    }
}

static void BinomialTest()
{
    Test::BinomialSanityCheck(333);

    for(ulong n = 100000; n < 6400002; n = n*2)
    {
       Test::BinomialBenchmark(n, n / 3);
    }
}

static bool getUserYes(const std::string &question)
{
  char yes;

  std::cout << std::endl << question << "? (y/n)" << std::endl;
  std::cin >> yes;
  if(yes == 'y' || yes == 'Y') {
      return true;
  }
  return false;
}

static ulong getUserNumber(const std::string &question)
{
   std::string nstr;
   ulong n;

   std::cout << std::endl << question << "?" << std::endl;
   std::cin.ignore(); //flush cin
   std::getline(std::cin, nstr);
   std::stringstream(nstr) >> n;
   return n;
}

int main()
{
   bool all;
   bool paralSwing = true;
   bool paraSchoen = true;
   bool primeSwing = true;
   bool schoenhage = true;
   bool mp_lib = true;


   if(getUserYes("Fakultaet zu einer Zahl")) {

       auto n = getUserNumber("Welche");

       all = getUserYes("Alle Berechnungsmethoden");
       if (!all) {
         paralSwing = getUserYes("ParalSwing Berechnung");
         paraSchoen = getUserYes("ParaSchoen Berechnung");
         primeSwing = getUserYes("PrimeSwing Berechnung");
         schoenhage = getUserYes("Schoenhage Berechnung");
         mp_lib = getUserYes("MP-library Berechnung");
       }

       FactTestN(n,
           paralSwing, paraSchoen, primeSwing, schoenhage, mp_lib);
   }

   //originalcode
   char yes;

   std::cout << std::endl << "Factorial Test? (y/n)" << std::endl;
   std::cin >> yes; if(yes == 'y' || yes == 'Y') FactTest();

   std::cout << std::endl << "Binomial Test? (y/n)" << std::endl;
   std::cin >> yes; if(yes == 'y' || yes == 'Y') BinomialTest();

   std::cout << std::endl << "Double Factorial Test? (y/n)" << std::endl;
   std::cin >> yes; if(yes == 'y' || yes == 'Y') DoubleFactTest();

    std::cout << std::endl << "Done." << std::endl;  std::cin.get();
    return 0;
}
