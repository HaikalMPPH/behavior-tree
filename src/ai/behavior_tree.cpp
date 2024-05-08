#include <src/ai/behavior_tree.hpp>

BehaviorTree::BehaviorTree() {}
BehaviorTree::~BehaviorTree() {
  dealloc_root();
}
void BehaviorTree::set_root(ABehavior* node) {
  _root = node;
}
ABehavior* BehaviorTree::get_root() {
  return _root;
}

void BehaviorTree::bt_update() {
  _root->tick();
}

void BehaviorTree::dealloc_root() {
  delete _root;
}
