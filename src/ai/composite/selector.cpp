#include <ai/composite/selector.hpp>

Selector::Selector() {}
Selector::~Selector() {}

BehaviorStatus Selector::update() {
  if (!_children.empty()) {
    for (ABehavior* child : _children) {
      _status = child->tick();

      if (_status == BehaviorStatus::NodeSuccess) {
        return _status;
      }
    }
  }

  return _status;
}
