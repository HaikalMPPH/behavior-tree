#include <ai/behavior.hpp>

ABehavior::ABehavior() 
    : _status {BehaviorStatus::NodeInvalid} 
    // By default can't have a child
    , _canHaveChild {false} 
    , _canHaveMultiChild {_canHaveChild} {
}

ABehavior::~ABehavior() {}

BehaviorStatus ABehavior::Tick() {
  if (_status != BehaviorStatus::NodeRunning) {
    OnInit();
  }

  _status = Update();

  if (_status != BehaviorStatus::NodeRunning) {
    OnTerminate(_status);
  }

  return _status;
}

void ABehavior::SetParent(ABehavior* node) {
  _parent = node;
}

ABehavior* ABehavior::GetParent() {
  return _parent;
}

