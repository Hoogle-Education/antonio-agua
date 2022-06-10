#include <iostream>
#include <sstream>

using namespace std;


int exercicio2(const char* entrada)
{
   int n;

   std::istringstream meu_cin{entrada};
   
   while( (meu_cin >> n) ){
      cout << n << "\n";
   }

   return 0;
}

int main(){

  cout << exercicio2("41123");

  return 0;
}