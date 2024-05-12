#include "behavior_tree.hpp"

BehaviorTree::BehaviorTree() 
    : _frame {0} 
{}

BehaviorTree::~BehaviorTree() {
  DeallocRoot();
}
void BehaviorTree::SetRoot(ABehavior* node) {
  _root = node;
}
ABehavior* BehaviorTree::GetRoot() {
  return _root;
}

void BehaviorTree::BTUpdate() {
  _root->Tick();
}

void BehaviorTree::BTUpdate(uint8_t tickRate) {
  if (_frame >= tickRate) {
    _root->Tick();
    _frame = 0;
  }
  _frame++;
}

void BehaviorTree::DeallocRoot() {
  delete _root;
  _root = nullptr;
}
