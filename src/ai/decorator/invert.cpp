#include "invert.hpp"

Invert::Invert() {}
Invert::~Invert() {}

BehaviorStatus
Invert::Update() {
  _status = _child->Tick();
  if (_status == BehaviorStatus::NodeSuccess) {
    return BehaviorStatus::NodeFailed;
  }
  else if (_status == BehaviorStatus::NodeFailed) {
    return BehaviorStatus::NodeSuccess;
  }
  return _status;
}
