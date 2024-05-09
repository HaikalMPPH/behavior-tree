#include <ai/composite/composite.hpp>

Composite::Composite() 
    : _children {} 
    , _free_id {0} {
  _can_have_child = _can_have_multi_child = true;
}

Composite::~Composite() {
  dealloc_child();
}

void Composite::add_child(ABehavior* node) {
  _children.push_back(node);
  get_active_child()->set_parent(this);
  //mark_next_free_id();
}

ABehavior* Composite::get_child_at(unsigned int i) {
  return _children[i];
}

ABehavior* Composite::get_active_child() {
  return _children[_free_id];
}

void Composite::mark_next_free_id() {
  _free_id++;
}

void Composite::dealloc_child() {
  if (!_children.empty()) {
    for (ABehavior* child : _children) {
      delete child;
    }
  }
}
