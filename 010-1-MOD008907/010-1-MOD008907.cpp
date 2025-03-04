// 010-1-MOD008907.cpp : This file contains TASK 1
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// All Parts: precedence calculator
int precedence(char opChar) {
  if (opChar == '/' || opChar == '*') return 2;
  if (opChar == '+' || opChar == '-') return 1;
  if (opChar == '^') return 3;
  return 0;
}

void stripSpaces(string& str) {
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

// Part 1: Infix to Postfix Converter using std::stack (no brackets)
string infixToPostfixPart1(string infix) {
  if (infix.find("(") != std::string::npos || infix.find(")") != std::string::npos) {
    throw runtime_error("infixToPostfixPart1 cannot contain brackets \"(\" / \")\"");
  }

  stack<char> charStack;
  string output = "";

  for (char currChar : infix) {
    if (isalnum(currChar)) // Operand
      output += currChar;
    else { // Operator
      while (!charStack.empty() && precedence(charStack.top()) >= precedence(currChar)) {
        output += charStack.top();
        charStack.pop();
      }
      charStack.push(currChar);
    }
  }

  while (!charStack.empty()) {
    output += charStack.top();
    charStack.pop();
  }

  return output;
}

int main() {
  string infix;
  // User input 
  cout << "Enter a infix: ";
  getline(cin, infix);

  // Strip invalid characters
  char chars[] = "() ";
  for (unsigned int i = 0; i < strlen(chars); ++i)
  {
    infix.erase(std::remove(infix.begin(), infix.end(), chars[i]), infix.end());
  }

  string postfix;

  try {
    postfix = infixToPostfixPart1(infix);
  }
  catch (const exception& e) {
    cerr << "Exception caught: " << e.what() << endl;
  }

  cout << "Postfix: " << postfix << endl;
  return 0;
}