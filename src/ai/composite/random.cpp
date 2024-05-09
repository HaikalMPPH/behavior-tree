#include <ai/composite/random.hpp>

Random::Random() {}

Random::~Random() {}

BehaviorStatus Random::update() {
  ABehavior* random_child = get_child_at(std::rand() % _free_id);
  if (!_children.empty()) {
    for (;;) {
      _status = random_child->tick();

      if (_status != BehaviorStatus::NodeRunning) {
        return _status;
      }
    }
  }

  return _status;
}
