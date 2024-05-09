#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <std_includes.hpp>
#include <ai/behavior.hpp>

class Composite : public ABehavior {
protected:
  using ChildVec = std::vector<ABehavior*>;
  ChildVec _children;
  ChildVec::iterator _current_child;

  // The next assignable child index. It's also the number of child it 
  // have.
  unsigned int _free_id;

public:
  Composite();
  virtual ~Composite();

  void add_child(ABehavior* node);
  ABehavior* get_child_at(unsigned int i);
  ABehavior* get_active_child();
  void mark_next_free_id();
  void dealloc_child();
  void on_init() override;
};

#endif
