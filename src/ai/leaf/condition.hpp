#ifndef CONDITION_HPP
#define CONDITION_HPP

#include "ai/behavior.hpp"
#include "std_includes.hpp"

class Condition : public ABehavior {
public:
  using ConditionFn = std::function<bool()>;
protected:
  ConditionFn _conditionFn;
public:
  Condition(ConditionFn conditionFn);
  ~Condition();

  BehaviorStatus Update() override;

};

#endif
