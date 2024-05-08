#include <src/ai/ai.hpp>
#include <src/std_includes.hpp>

BehaviorStatus say_hello() {
  std::cout << "Hello, World!" << std::endl;
  return BehaviorStatus::NodeFailed;
}

int main() {
  BehaviorTreeBuilder* btb = new BehaviorTreeBuilder();
  btb
    ->add_root(new Sequence())
      ->add_sequence(new Sequence())
        ->add_action(say_hello)
        ->add_action(say_hello);

  BehaviorTree* bt = btb->create_tree();

  bt->bt_update();

  delete btb;
  delete bt;
  return 0;
}
