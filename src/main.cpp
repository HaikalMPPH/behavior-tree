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
BehaviorStatus say_hello3() {
  std::cout << "Hello 3!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return BehaviorStatus::NodeSuccess;
}
BehaviorStatus say_hello4() {
  std::cout << "Hello 4!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return BehaviorStatus::NodeSuccess;
}

int main() {
  std::srand(std::time(nullptr));
  BehaviorTreeBuilder* btb = new BehaviorTreeBuilder();
  btb
    ->root(new Repeat())
      ->composite(new Sequence())
        ->composite(new Random())
          ->action(say_hello)
          ->action(say_hello2)
          ->action(say_hello3)
          ->action(say_hello4);

  BehaviorTree* bt = btb->create_tree();

  bt->bt_update();

  delete btb;
  delete bt;
  return 0;
}
