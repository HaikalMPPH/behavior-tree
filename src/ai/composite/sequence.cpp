#include "sequence.hpp"

Sequence::Sequence() {}
Sequence::~Sequence() {}

BehaviorStatus Sequence::update() {
  if (!_children.empty()) {
    for (;;) {
      _status = (*_current_child)->tick();

      if (_status != BehaviorStatus::NodeSuccess) {
        return _status;
      }

      // TODO: Find out why is this working?
      if (++_current_child == _children.end()) {
        return BehaviorStatus::NodeSuccess;
      }
    }
  }
  return BehaviorStatus::NodeInvalid;
}
