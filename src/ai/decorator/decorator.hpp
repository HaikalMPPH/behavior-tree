#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <src/ai/behavior.hpp>

class Decorator : public ABehavior {
protected:
  ABehavior* _child;
public:
  Decorator();
  virtual ~Decorator();
  void add_child(ABehavior* node);
  ABehavior* get_child();
  void dealloc_child();
};

#endif
