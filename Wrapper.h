#pragma once
#include <functional>
#include <iostream>
#include <tuple>
#include <array>
#include <utility>
#include "Params.h"
//template <typename ...Args>
class Wrapper
{
  //Params Param;
  //int(*func)(Args...);
  std::function<int()> func;
  std::vector<Argument> args;
  //std::array<std::string, sizeof...(Args)> Names;
  //std::array<int, sizeof...(Args)> Values;
private:
  template<typename T, typename ...Args, size_t ... I>
  Wrapper(T *f_class, int(T::* funcptr)(Args...), const std::vector<Argument> &Prmtrs, std::index_sequence<I...>)
  {
    args = Prmtrs;
    //auto Is = std::make_index_sequence<Prmtrs.size()>();
    func = std::bind(funcptr, f_class, std::ref(this->args[I].Data)...);
  }

public:
  template<typename T, typename ...Args>
  Wrapper(T *f_class, int(T::* funcptr)(Args...), const std::vector<Argument> &Prmtrs):
    Wrapper(f_class, funcptr, Prmtrs, std::make_index_sequence<sizeof...(Args)>())
  {
  }
  void Set(Params P)
  {
    for (int i = 0; i < args.size(); i++)
      for (int j = 0; j < args.size(); j++)
        if (P.Data[i].Name == args[j].Name)
          args[j].Data = P.Data[i].Data;
  }
  int Call( void )
  {
    int tmp = func();
    return tmp;
  }
  //~Wrapper();
};

