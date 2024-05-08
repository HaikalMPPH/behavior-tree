#ifndef BEHAVIOR_TREE_H
#define BEHAVIOR_TREE_H

#include <src/ai/behavior.hpp>

class BehaviorTree {
private:
  ABehavior* _root;
public:
  BehaviorTree();
  ~BehaviorTree();
  void set_root(ABehavior* node);
  ABehavior* get_root();
  void bt_update();
  void dealloc_root();
};

#endif
