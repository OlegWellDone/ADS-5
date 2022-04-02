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
  if (pr == -1) {
    if (!itog.empty() && prior(inf[i - 1]) != -1) {
      itog.push_back(' ');
    }
    itog.push_back(inf[i]);
  } else if ((pr == 0) || (pr > prior(zzz.get())) || (zzz.isEmpty())) {
    zzz.push(inf[i]);
  } else {
    if (pr == 1) {
      while (prior(zzz.get()) != 0) {
        itog.push_back(' ');
        itog.push_back(zzz.get());
        zzz.pop();
      }
      zzz.pop();
    } else {
      while (prior(zzz.get()) >= pr) {
        itog.push_back(' ');
        itog.push_back(zzz.get());
        zzz.pop();
      }
      zzz.push(inf[i]);
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
TStack <int, 50> zzz;
int itog, temp;
for (int i = 0; i < pref.size(); i++) {
if ((static_cast<int>(pref[i]) > 0) && (static_cast<int>(pref[i]) < 10)) {
zzz.push(static_cast<int>(pref[i]));
} else if (prior(pref[i]) > 1) {
  switch (pref[i]) {
    case '+' : {
      temp = zzz.get();
      zzz.pop();
      itog = zzz.get();
      zzz.pop();
      zzz.push(itog + temp);
      break;
    }
    case '-' : {
      temp = zzz.get();
      zzz.pop();
      itog = zzz.get();
      zzz.pop();
      zzz.push(itog - temp);
      break;
    }
    case '*' : {
      temp = zzz.get();
      zzz.pop();
      itog = zzz.get();
      zzz.pop();
      zzz.push(itog * temp);
      break;
    }
    case '/' : {
      temp = zzz.get();
      zzz.pop();
      itog = zzz.get();
      zzz.pop();
      zzz.push(itog / temp);
      break;
    }
  }
}
}
  return zzz.get();
}
