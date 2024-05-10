#include "invert.hpp"

Invert::Invert() {}
Invert::~Invert() {}

BehaviorStatus
Invert::update() {
  _status = _child->tick();
  if (_status == BehaviorStatus::NodeSuccess) {
    return BehaviorStatus::NodeFailed;
  }
  else if (_status == BehaviorStatus::NodeFailed) {
    return BehaviorStatus::NodeSuccess;
  }
  return _status;
}
