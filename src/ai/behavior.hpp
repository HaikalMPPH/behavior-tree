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
  bool _canHaveChild;
  bool _canHaveMultiChild;
public:
  ABehavior();
  virtual ~ABehavior();

  ABehavior* GetParent();
  void SetParent(ABehavior* node);
  BehaviorStatus Tick();
  virtual BehaviorStatus Update() = 0;
  virtual void Cleanup() {}; 
  virtual void OnInit() {};
  virtual void OnTerminate(BehaviorStatus status) {};
};

#endif
