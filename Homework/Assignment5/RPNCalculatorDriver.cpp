/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
#include <iomanip>

// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator calc;
  string input;
  float num;
  bool comp;
  string tmp;

  
  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;
  while(input != "=")
  {
    cout << "#> ";
    getline(cin, input);
    num = 0.0;

    if(input == "=")
    {
        continue;
    }

    if(isNumber(input))
    {
      num = stof(input);
      calc.push(num);
    }
    if(input == "*" || input = "+")
      comp = calc.compute(input);
    else
      cout << "Invalid expression" << endl;
      continue;

    tmp = input;
  }

  if(calc.isEmpty()){
    cout << "No operands: Nothing to evaluate";
    return 0;
  }

  if(isNumber(tmp)) {
    cout << "Invalid expression" << endl;
    return 0;
  }

  else
  {
    Operand *ret = calc.getStackHead();
    cout << ret->number << endl;
  }

    return 0;
}
