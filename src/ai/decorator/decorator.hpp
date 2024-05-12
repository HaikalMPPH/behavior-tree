#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <ai/behavior.hpp>

class Decorator : public ABehavior {
protected:
  ABehavior* _child;
public:
  Decorator();
  virtual ~Decorator();
  void AddChild(ABehavior* node);
  ABehavior* GetChild();
  void DeallocChild();
};

#endif
