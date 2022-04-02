// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int ischar(char t) {
  switch (t) {
    case '(' : return 0;
    case ')' : return 1;
    case '+' : return 2;
    case '-' : return 2;
    case '*' : return 3;
    case '/' : return 3;
  }
  return 4;
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stackznakov;
  char chto = ' ', razd = ' ';
  std::string itog;
  for (int i = 0; i <= inf.size(); i++) {
    chto = inf[i];
    if (ischar(chto) != 4) {
      if (ischar(chto) == 1) {
      while (ischar(stackznakov.get()) != 0) {
        itog.push_back(stackznakov.get());
        stackznakov.pop();
        itog.push_back(razd);
        if (ischar(stackznakov.get()) == 0) {
          stackznakov.pop();
          break;
        }
        }
      } else if ((ischar(chto) >= ischar(stackznakov.get())) &&
                 (ischar(chto) != 0) && (ischar(chto) != 1)) {
        itog.push_back(chto);
        itog.push_back(razd);
      } else {
        stackznakov.push(chto);
      }
    } else {
      itog.push_back(chto);
      itog.push_back(razd);
      }
    }
  return itog;
}

int eval(std::string pref) {
  TStack<int, 100> stackzifr;
  char chto = ' ';
  std::string uu = " ";
  int resh = 0, kk = 0;
  for (int i = 0; i <= pref.size(); i++) {
    chto = pref[i];
    if (ischar(chto) != 4) {
      kk = stackzifr.get();
      stackzifr.pop();
      switch (chto) {
          case ('+') : {
            if (resh == 0) {
              resh = kk + stackzifr.get();
              stackzifr.pop();
              break;
            } else {
              resh = resh + stackzifr.get();
              stackzifr.pop();
              break;
            }
          }
          case ('-') : {
            if (resh == 0) {
              resh = kk - stackzifr.get();
              stackzifr.pop();
              break;
            } else {
              resh = resh - stackzifr.get();
              stackzifr.pop();
              break;
            }
          }
          case ('*') : {
            if (resh == 0) {
              resh = kk * stackzifr.get();
              stackzifr.pop();
              break;
            } else {
              resh = resh * stackzifr.get();
              stackzifr.pop();
              break;
            }
          }
          case ('/') : {
            if (resh == 0) {
              resh = kk / stackzifr.get();
              stackzifr.pop();
              break;
            } else {
              resh = resh / stackzifr.get();
              stackzifr.pop();
              break;
            }
          }
      }
    } else if (chto == ' ') {
      continue;
    } else {
      stackzifr.push(chto);
    }
  }
  return resh;
}
