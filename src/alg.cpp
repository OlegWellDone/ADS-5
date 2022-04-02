// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char t) {
switch (t) {
  case '(' : return 0;
  case ')' : return 1;
  case '+' : return 2;
  case '-' : return 2;
  case '*' : return 3;
  case '/' : return 3;
  default : return -1;
}
}

std::string infx2pstfx(std::string inf) {
  TStack <char, 50> zzz;
int pr;
std :: string itog;
for (int i = 0; i < inf.size(); i++) {
  pr = prior(inf[i]);
  switch (pr) {
    case -1 : {
      if (!itog.empty() && prior(inf[i - 1]) != -1) {
        itog.push_back(' ');
      }
      itog.push_back(inf[i]);
      break;
    }
    case 0 : {
      zzz.push(inf[i]);
      break;
    }
    case 1 : {
      while (prior(zzz.get()) != 0) {
        itog.push_back(' ');
        itog.push_back(zzz.get());
        zzz.pop();
      }
      zzz.pop();
      break;
    }
    case 2 : {
      if ((prior(zzz.get()) < 2) ||  (zzz.isEmpty())) {
        zzz.push(inf[i]);
      } else {
        while (prior(zzz.get()) >= 2) {
          itog.push_back(' ');
          itog.push_back(zzz.get());
          zzz.pop();
        }
        zzz.push(inf[i]);
      }
      break;
    }
    case 3 : {
      if ((prior(zzz.get()) < 3) ||  (zzz.isEmpty())) {
        zzz.push(inf[i]);
      } else {
        while (prior(zzz.get()) >= 3) {
          itog.push_back(' ');
          itog.push_back(zzz.get());
          zzz.pop();
        }
        zzz.push(inf[i]);
      }
      break;
    }
  }
}
  while (!zzz.isEmpty()) {
    itog.push_back(' ');
    itog.push_back(zzz.get());
    zzz.pop();
  }
return itog;
}

int eval(std::string pref) {
TStack <int, 50> zzzz;
int itog, temp;
for (int i = 0; i < pref.size(); i++) {
  if (prior(pref[i]) > 1) {
    switch (pref[i]) {
      case '+' : {
      temp = zzzz.get();
      zzzz.pop();
      itog = zzzz.get();
      zzzz.pop();
      zzzz.push(itog + temp);
      break;
    }
    case '-' : {
      temp = zzzz.get();
      zzzz.pop();
      itog = zzzz.get();
      zzzz.pop();
      zzzz.push(itog - temp);
      break;
    }
    case '*' : {
      temp = zzzz.get();
      zzzz.pop();
      itog = zzzz.get();
      zzzz.pop();
      zzzz.push(itog * temp);
      break;
    }
    case '/' : {
      temp = zzzz.get();
      zzzz.pop();
      itog = zzzz.get();
      zzzz.pop();
      zzzz.push(itog / temp);
      break;
    }
  }
} else if (pref[i] != ' ') {
    zzzz.push(pref[i]);
  }
}
  return zzzz.get();
}
