#include <ai/ai.hpp>
#include <std_includes.hpp>

BehaviorStatus always_running() {
  std::cout << "RUNNING!!!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return BehaviorStatus::NodeRunning;
}

int main() {
///////////////// CUSTON ACTION LEAF //////////////////////////////////
  Action* say_hello = new Action([](){
    std::cout << "Hello 1!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return BehaviorStatus::NodeSuccess;
  });
  Action* say_hello2 = new Action([](){
    std::cout << "Hello 2!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return BehaviorStatus::NodeSuccess;
  });
  Action* say_hello3 = new Action([](){
    std::cout << "Hello 3" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return BehaviorStatus::NodeSuccess;
  });
  Action* say_hello4 = new Action([](){
    std::cout << "Hello 4!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return BehaviorStatus::NodeSuccess;
  });
///////////////////////////////////////////////////////////////////////

  std::srand(std::time(nullptr));
  BehaviorTreeBuilder* btb = new BehaviorTreeBuilder();
  btb
    ->root(new Sequence())
      ->composite(new Random())
        ->action(say_hello)
        ->action(say_hello2)
        ->action(say_hello3)
        ->action(say_hello4)
        ->action(new Action(always_running));

  BehaviorTree* bt = btb->create_tree();

  while (true) {
    bt->bt_update(5.0f);
  }

  delete btb;
  delete bt;
  return 0;
}
