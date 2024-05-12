#include "ai/ai.hpp"
#include <std_includes.hpp>

BehaviorStatus AlwaysRunning() {
  std::cout << "RUNNING!!!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  return BehaviorStatus::NodeRunning;
}

int main() {
///////////////// CUSTON ACTION LEAF //////////////////////////////////
  Action* SayHello = new Action([](){
    std::cout << "Hello 1!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return BehaviorStatus::NodeSuccess;
  });
  Action* SayHello2 = new Action([](){
    std::cout << "Hello 2!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return BehaviorStatus::NodeSuccess;
  });
  Action* SayHello3 = new Action([](){
    std::cout << "Hello 3" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return BehaviorStatus::NodeSuccess;
  });
  Action* SayHello4 = new Action([](){
    std::cout << "Hello 4!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return BehaviorStatus::NodeSuccess;
  });

  Condition* AlwaysFalse = new Condition([](){
    return false;
  });
///////////////////////////////////////////////////////////////////////

  std::srand(std::time(nullptr));
  BehaviorTreeBuilder* btb = (new BehaviorTreeBuilder())->AddRoot(new Sequence())
      ->AddComposite(new Sequence())
        ->AddAction(SayHello)
        ->AddAction(SayHello2)
        ->AddCondition(AlwaysFalse)
        ->AddDecorator(new Invert())
          ->AddAction(SayHello3)
          ->End()
        ->AddAction(SayHello4);

  BehaviorTree* bt = btb->CreateTree();

  while (true) {
    bt->BTUpdate(5.0f);
  }

  delete btb;
  delete bt;
  return 0;
}
