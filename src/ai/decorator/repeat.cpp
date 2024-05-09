#include <ai/decorator/repeat.hpp>

Repeat::Repeat() {}
Repeat::~Repeat() {}

BehaviorStatus Repeat::update() {
  while (true) {
    _status = _child->tick();
  }

  return _status;
}
