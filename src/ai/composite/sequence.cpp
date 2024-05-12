#include "sequence.hpp"

Sequence::Sequence() {}
Sequence::~Sequence() {}

BehaviorStatus Sequence::Update() {
  if (!_children.empty()) {
    for (;;) {
      _status = (*_currentChild)->Tick();

      if (_status != BehaviorStatus::NodeSuccess) {
        return _status;
      }

      // TODO: Find out why is this working?
      if (++_currentChild == _children.end()) {
        return BehaviorStatus::NodeSuccess;
      }
    }
  }
  return BehaviorStatus::NodeInvalid;
}
