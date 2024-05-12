#ifndef BEHAVIOR_TREE_BUILDER_H
#define BEHAVIOR_TREE_BUILDER_H

#include <std_includes.hpp>
#include <ai/composite/composite.hpp>
#include <ai/leaf/action.hpp>
#include <ai/ai.hpp>

class BehaviorTreeBuilder {
private:
  BehaviorTree* _bt;
  ABehavior* _current;
public:
  BehaviorTreeBuilder();
  ~BehaviorTreeBuilder();

  // can be composites or decorators (Root must be able to have child).
  BehaviorTreeBuilder* AddRoot(ABehavior* node);

  BehaviorTreeBuilder* AddComposite(Composite* node);
  BehaviorTreeBuilder* AddDecorator(Decorator* node);

  // Actions and Conditions won't change _current to itself.
  BehaviorTreeBuilder* AddAction(Action* node);
  BehaviorTreeBuilder* AddCondition(Condition* node);

  BehaviorTreeBuilder* End();

  BehaviorTree* CreateTree();
};


#endif
