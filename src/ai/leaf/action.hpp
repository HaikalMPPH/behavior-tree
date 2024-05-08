#ifndef ACTION_H
#define ACTION_H

#include <src/ai/behavior.hpp>
#include <src/std_includes.hpp>

class Action : public ABehavior {
public:
  using ActionFn = std::function<BehaviorStatus()>;
protected:
   ActionFn _action_fn;
public:
  Action(ActionFn action_fn);
  ~Action();

  BehaviorStatus update() override;
};

#endif
