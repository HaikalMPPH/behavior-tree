#include "random.hpp"

Random::Random() {}

Random::~Random() {}

BehaviorStatus Random::update() {
  if (!_children.empty()) {
    for (;;) {
      _status = get_child_at(std::rand() % _free_id)->tick();
      return _status;
    }
  }

  return _status;
}
