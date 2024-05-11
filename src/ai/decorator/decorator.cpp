#include <ai/decorator/decorator.hpp>

Decorator::Decorator() 
    : _child {nullptr} {
  _can_have_child = true;
  _can_have_multi_child = false;
}

Decorator::~Decorator() {
  dealloc_child();
}

void Decorator::dealloc_child() {
  delete _child;
  _child = nullptr;
}

void Decorator::add_child(ABehavior* node) {
  _child = node;
  _child->set_parent(this);
}

ABehavior* Decorator::get_child() {
  return _child;
}
