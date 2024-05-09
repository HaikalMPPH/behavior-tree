#include <ai/composite/sequence.hpp>

Sequence::Sequence() {}
Sequence::~Sequence() {}

BehaviorStatus Sequence::update() {
  if (!_children.empty()) {
    for (ABehavior* child : _children) {
      _status = child->tick();

      if (_status == BehaviorStatus::NodeFailed) {
        return _status;
      }
    }
  }

  return _status;
}
