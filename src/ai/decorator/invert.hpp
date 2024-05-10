#ifndef INVERT_HPP
#define INVERT_HPP

#include "decorator.hpp"

class Invert : public Decorator {
protected:

public:
  Invert();
  ~Invert();
  BehaviorStatus update() override;
};

#endif
