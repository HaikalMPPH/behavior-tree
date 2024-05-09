#ifndef BEHAVIOR_TREE_H
#define BEHAVIOR_TREE_H

#include <ai/behavior.hpp>

class BehaviorTree {
private:
  ABehavior* _root;
public:
  BehaviorTree();
  ~BehaviorTree();
  void set_root(ABehavior* node);
  ABehavior* get_root();
  void bt_update();

  /*
     Optional: tick the bt_update() for a certain rate. Usually ties to
     game frame rate. Example: a tick_rate of 5 means it ticks every 5
     frame.
  */
  void bt_update(float tick_rate);
  void dealloc_root();
};

#endif
