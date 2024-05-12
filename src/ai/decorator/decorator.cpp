#include <ai/decorator/decorator.hpp>

Decorator::Decorator() 
    : _child {nullptr} {
  _canHaveChild = true;
  _canHaveMultiChild = false;
}

Decorator::~Decorator() {
  DeallocChild();
}

void Decorator::DeallocChild() {
  delete _child;
  _child = nullptr;
}

void Decorator::AddChild(ABehavior* node) {
  _child = node;
  _child->SetParent(this);
}

ABehavior* Decorator::GetChild() {
  return _child;
}
