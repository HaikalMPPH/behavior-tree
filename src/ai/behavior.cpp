#include <src/ai/behavior.h>

ABehavior::ABehavior() 
    : _status {BehaviorStatus::NodeInvalid} 
    // By default can't have a child
    , _can_have_child {false} 
    , _can_have_multi_child {_can_have_child} {
}

ABehavior::~ABehavior() {}

BehaviorStatus ABehavior::tick() {
  if (_status != BehaviorStatus::NodeRunning) {
    on_init();
  }

  _status = update();

  if (_status != BehaviorStatus::NodeRunning) {
    on_terminate(_status);
  }

  return _status;
}

void ABehavior::set_parent(ABehavior* node) {
  _parent = node;
}

ABehavior* ABehavior::get_parent() {
  return _parent;
}

