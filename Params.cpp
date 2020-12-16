#include "Params.h"

Argument::Argument(const char * name, const int argument)
{
  Name = name;
  Data = argument;
}
Argument::~Argument()
{
}
