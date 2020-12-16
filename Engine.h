#pragma once
#include <map>
#include "Wrapper.h"
//template <typename ...Args>
class Engine
{
  std::map<std::string, Wrapper *> M;
public:
  Engine( void )
  {}
  void register_command(Wrapper *w, const char *Name)
  {
    std::string S(Name);
    M[S] = w;
  }
  
  int execute( const char *Name, Params P)
  {
    std::string S(Name);
    Wrapper *wrap = M[S];
    wrap->Set(P);
    int tmp = wrap->Call();
    return tmp;
  }
  //~Engine();
};

