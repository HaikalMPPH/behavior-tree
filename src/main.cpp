#include <src/ai/ai.hpp>
#include <src/std_includes.hpp>

BehaviorStatus say_hello() {
  std::cout << "Hello 1!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return BehaviorStatus::NodeSuccess;
}
BehaviorStatus say_hello2() {
  std::cout << "Hello 2!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return BehaviorStatus::NodeSuccess;
}

int main() {
  BehaviorTreeBuilder* btb = new BehaviorTreeBuilder();
  btb
    ->add_root(new Repeat())
      ->add_sequence(new Sequence())
        ->add_action(say_hello)
        ->add_action(say_hello2);

  BehaviorTree* bt = btb->create_tree();

  bt->bt_update();

  delete btb;
  delete bt;
  return 0;
}
