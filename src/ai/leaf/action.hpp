#ifndef ACTION_HPP
#define ACTION_HPP

#include <ai/behavior.hpp>
#include <std_includes.hpp>

class Action : public ABehavior {
public:
  using ActionFn = std::function<BehaviorStatus()>;
protected:
   ActionFn _actionFn;
public:
  Action(ActionFn actionFn);
  ~Action();

  BehaviorStatus Update() override;
};

#endif
