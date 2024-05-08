#include <src/ai/ai.h>
#include <src/std_includes.h>

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

  // don't run the main: this thing still cause memory leak. Just wan't
  // to make sure it compiles.
  BehaviorTree* bt = btb->create_tree();

  bt->bt_update();

  delete btb;
  delete bt;
  return 0;
}
