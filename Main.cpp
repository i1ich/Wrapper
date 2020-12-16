#include <iostream>
#include "Engine.h"
#include "Wrapper.h"
class Subject
{
public:

int f3 (int a, int b)
{
  return a+b;
}
private:

};
void main (void)
{
   Subject subj;
   //void *f = &Subject::f3;
   Wrapper wrapper(&subj, &Subject::f3, {{"arg1", 0}, {"arg2", 0}});
   //Wrapper     w(&subj, &Subject::f3, {{"arg1", 0}, {"arg2", 0}});
   Engine engine;
  
  engine.register_command(&wrapper, "command1");
  
  std::cout << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;
}
