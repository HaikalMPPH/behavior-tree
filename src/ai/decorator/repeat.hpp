#ifndef REPEAT_HPP
#define REPEAT_HPP

#include <ai/decorator/decorator.hpp>

class Repeat : public Decorator {
protected:
public:
  Repeat();
  ~Repeat();
  BehaviorStatus update() override;
};

#endif
