#include <ai/composite/selector.hpp>

Selector::Selector() {}
Selector::~Selector() {}

BehaviorStatus Selector::Update() {
  if (!_children.empty()) {
    for (;;) {
      _status = (*_currentChild)->Tick();

      if (_status != BehaviorStatus::NodeFailed) {
        return _status;
      }

      if (++_currentChild == _children.end()) {
        return BehaviorStatus::NodeFailed;
      }
    }
  }
  return BehaviorStatus::NodeInvalid;
}
