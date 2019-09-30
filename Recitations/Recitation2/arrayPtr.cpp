#include <iostream>
using namespace std;

void add2 ( int ∗a, int len)
{
  for ( int i= 0 ;i<len;i++)
  a[i]+= 2 ;
}

int main ()
{
  int a[] = { 1 , 2 , 3 };
  add2( a, 3 );
  for ( int i= 0 ;i< 3 ;i++)
  cout << a[i] << endl ;
}
