#include <ai/composite/selector.hpp>

Selector::Selector() {}
Selector::~Selector() {}

BehaviorStatus Selector::update() {
  if (!_children.empty()) {
    for (;;) {
      _status = (*_current_child)->tick();

      if (_status != BehaviorStatus::NodeFailed) {
        return _status;
      }

      if (++_current_child == _children.end()) {
        return BehaviorStatus::NodeFailed;
      }
    }
  }
  return BehaviorStatus::NodeInvalid;
}
