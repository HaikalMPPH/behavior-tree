#include <ai/leaf/action.hpp>

// Two ways to use this contructor:
// 1. A function that actually returns BehaviorStatus:
//    Action(actual_funtion_that_return_behaviorstatus);
//
// 2. Using lambda to wrap a function so it's return BehaviorStatus
//    Action([](){
//      another_function();
//      if (some_conditional_checking) {
//        return BehaviorStatus::NodeSuccess;
//      }
//      return BehaviorStatus::NodeRunning;
//    });

Action::Action(ActionFn actionFn) 
    : _actionFn {actionFn} {
  _canHaveChild = false;
}

Action::~Action() {}

BehaviorStatus Action::Update() {
  _status = _actionFn();

  return _status;
}
