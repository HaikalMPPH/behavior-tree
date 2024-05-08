#ifndef BEHAVIOR_TREE_BUILDER_H
#define BEHAVIOR_TREE_BUILDER_H

#include <src/std_includes.hpp>
#include <src/ai/composite/composite.hpp>
#include <src/ai/leaf/action.hpp>
#include <src/ai/ai.hpp>

class BehaviorTreeBuilder {
private:
  BehaviorTree* _bt;
  ABehavior* _current;
public:
  BehaviorTreeBuilder();
  ~BehaviorTreeBuilder();

  // can be composites or decorators (root must be able to have child).
  BehaviorTreeBuilder* root(ABehavior* node);

  BehaviorTreeBuilder* composite(Composite* node);

  // Actions and Conditions won't change _current to itself.
  BehaviorTreeBuilder* action(Action::ActionFn fn);

  BehaviorTreeBuilder* end();

  BehaviorTree* create_tree();
};


#endif
