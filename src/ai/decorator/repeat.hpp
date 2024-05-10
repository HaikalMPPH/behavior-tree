#ifndef REPEAT_HPP
#define REPEAT_HPP
/////////////////////// !!! WARNING !!! ///////////////////////////////
//                 DO NOT USE REPEAT IN A GAME LOOP.                 //
///////////////////////////////////////////////////////////////////////

#include "decorator.hpp"

class Repeat : public Decorator {
protected:
public:
  Repeat();
  ~Repeat();
  BehaviorStatus update() override;
};

#endif
