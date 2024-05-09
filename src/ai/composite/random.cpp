#include <ai/composite/random.hpp>

Random::Random() {}

Random::~Random() {}

BehaviorStatus Random::update() {
  if (!_children.empty()) {
    _status = get_child_at(std::rand() % _free_id)->tick();
  }

  return _status;
}
