#include "condition.hpp"

Condition::Condition(ConditionFn conditionFn)
    : _conditionFn {conditionFn} {}

Condition::~Condition() {}

BehaviorStatus
Condition::Update() {
  bool condition = _conditionFn();
  if (condition) {
    _status = BehaviorStatus::NodeSuccess;
  }
  else {
    _status = BehaviorStatus::NodeFailed;
  }

  return _status;
}
