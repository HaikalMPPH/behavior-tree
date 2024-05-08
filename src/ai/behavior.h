#ifndef BEHAVIOR_H
#define BEHAVIOR_H

enum BehaviorStatus {
  NodeRunning,
  NodeFailed,
  NodeSuccess,
  NodeInvalid,
};

class ABehavior {
protected:
  BehaviorStatus _status;
  ABehavior* _parent;
  ABehavior* _child;
public:
  bool _can_have_child;
  bool _can_have_multi_child;
public:
  ABehavior();
  virtual ~ABehavior();

  ABehavior* get_parent();
  void set_parent(ABehavior* node);
  BehaviorStatus tick();
  virtual BehaviorStatus update() = 0;
  virtual void cleanup() {}; 
  virtual void on_init() {};
  virtual void on_terminate(BehaviorStatus status) {};
};

#endif
