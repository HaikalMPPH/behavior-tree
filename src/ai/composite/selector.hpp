#ifndef SELETOR_HPP
#define SELETOR_HPP

#include <src/ai/composite/composite.hpp>

class Selector : public Composite {
protected:
public:
  Selector();
  ~Selector();
  BehaviorStatus update() override;
};

#endif
