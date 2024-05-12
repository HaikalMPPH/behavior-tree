#ifndef BEHAVIOR_TREE_H
#define BEHAVIOR_TREE_H

#include <ai/behavior.hpp>
#include <std_includes.hpp>

class BehaviorTree {
private:
  ABehavior* _root;
  uint8_t _frame;
public:
  BehaviorTree();
  ~BehaviorTree();
  void SetRoot(ABehavior* node);
  ABehavior* GetRoot();
  void BTUpdate();

  /*
     Optional: tick the BTUpdate() for a certain rate. Usually ties to
     game frame rate. Example: a tickRate of 5 means it ticks every 5
     frame.
  */
  void BTUpdate(uint8_t tickRate);
  void DeallocRoot();
};

#endif
