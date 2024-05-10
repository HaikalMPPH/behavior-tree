#include "behavior_tree.hpp"

BehaviorTree::BehaviorTree() 
    : _frame {0} {}
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

void BehaviorTree::bt_update(float tick_rate) {
  if (_frame >= tick_rate) {
    _root->tick();
    _frame = 0;
  }
  _frame++;
}

void BehaviorTree::dealloc_root() {
  delete _root;
}
