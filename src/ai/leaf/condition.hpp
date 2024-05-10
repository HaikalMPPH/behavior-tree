#ifndef CONDITION_HPP
#define CONDITION_HPP

#include "../behavior.hpp"
#include "../../std_includes.hpp"

class Condition : public ABehavior {
public:
  using ConditionFn = std::function<bool()>;
protected:
  ConditionFn _condition_fn;
public:
  Condition(ConditionFn condition_fn);
  ~Condition();

  BehaviorStatus update() override;

};

#endif
