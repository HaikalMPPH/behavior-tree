#include "random.hpp"

Random::Random() {}

Random::~Random() {}

BehaviorStatus Random::Update() {
  if (!_children.empty()) {
    for (;;) {
      _status = GetChildAt(std::rand() % _freeId)->Tick();
      return _status;
    }
  }

  return _status;
}
