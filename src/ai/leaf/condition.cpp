#include "condition.hpp"

Condition::Condition(ConditionFn condition_fn)
    : _condition_fn {condition_fn} {}

Condition::~Condition() {}

BehaviorStatus
Condition::update() {
  bool condition = _condition_fn();
  if (condition) {
    _status = BehaviorStatus::NodeSuccess;
  }
  else {
    _status = BehaviorStatus::NodeFailed;
  }

  return _status;
}
