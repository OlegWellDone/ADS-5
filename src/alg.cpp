// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int ischar(char t) {
  switch (t) {
    case ('(') : return 0;
    case (')') : return 1;
    case ('+') : return 2;
    case ('-') : return 2;
    case ('*') : return 3;
    case ('/') : return 3;
    default : return 4;
  }
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stackznakov;
  char chto = '', razd = ' ';
  std::string itog = " ";
  for (int i = 0; i <= inf.length(); i++) {
    chto = inf[i];
    if (ischar(chto) == 4) {
      itog += chto;
      itog += razd;
      }
      if (ischar(chto) == 1) {
      while (stackznakov.top() != 0) {
        itog += stackznakov.pop();
        itog += razd;
        }
      } else if ((ischar(chto) >= ischar(stackznakov.top())) &&
                 (ischar(chto) != 0) && (ischar(chto) != 1)) {
        itog += chto;
        itog += razd;
      } else {
        stackznakov.push(chto);
      }
    }
  return std::string(itog);
}

int eval(std::string pref) {
  TStack<int, 100> stackzifr;
  char chto = ' ';
  std::string uu = " ";
  uint64_t resh = 0, kk = 0;
  for (int i = 0; i <= pref.length(); i++) {
    chto = pref[i];
    if (ischar(chto) == 4) {
      stackzifr.push(chto);
    } else if (ischar(chto) != 4) {
      kk = stackzifr.pop();
      switch (chto) {
          case ('+') : {
            if (resh == 0) {
              resh = kk + stackzifr.pop();
              break;
            } else {
              resh = resh + stackzifr.pop();
              break;
            }
          }
          case ('-') : {
            if (resh == 0) {
              resh = kk - stackzifr.pop();
              break;
            } else {
              resh = resh - stackzifr.pop();
              break;
            }
          }
          case ('*') : {
            if (resh == 0) {
              resh = kk * stackzifr.pop();
              break;
            } else {
              resh = resh * stackzifr.pop();
              break;
            }
          }
          case ('/') : {
            if (resh == 0) {
              resh = kk / stackzifr.pop();
              break;
            } else {
              resh = resh / stackzifr.pop();
              break;
            }
          }
      }
    }
  }
  return resh;
}
