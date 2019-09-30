#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

/* Algorithm:
   1.

*/
int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{

  bool swapped = false;
  string hello;

  // Insert first entry
  if(numEntries == 0)
  {
      myArray[0] = newValue;
      numEntries++;
      return numEntries;
  }

  for(int i = 0; i < numEntries; i++)
  {
    if(newValue < myArray[i])
    {
      myArray[i + 1] = myArray[i];
      myArray[i] = newValue;
      numEntries++;
      swapped = true;
      break;
    }
  }

  if(swapped == false)
  {
    myArray[numEntries] = newValue;
    numEntries++;
  }
}
