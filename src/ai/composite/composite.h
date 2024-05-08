#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <src/std_includes.h>
#include <src/ai/behavior.h>

class Composite : public ABehavior {
protected:
  using ChildVec = std::vector<ABehavior*>;
  ChildVec _children;
  unsigned int _free_id;

public:
  Composite();
  virtual ~Composite();

  void add_child(ABehavior* node);
  //ABehavior* get_child_at(unsigned int i);
  ABehavior* get_active_child();
  void mark_next_free_id();
  void dealloc_child();
};

#endif