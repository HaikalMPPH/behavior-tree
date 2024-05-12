#include <ai/composite/composite.hpp>

Composite::Composite() 
    : _children {} 
    , _freeId {0} {
  _canHaveChild = _canHaveMultiChild = true;
}

Composite::~Composite() {
  DeallocChild();
}

void Composite::AddChild(ABehavior* node) {
  _children.push_back(node);
  GetActiveChild()->SetParent(this);
  //MarkNextFreeId();
}

ABehavior* Composite::GetChildAt(unsigned int i) {
  return _children[i];
}

ABehavior* Composite::GetActiveChild() {
  return _children[_freeId];
}

void Composite::MarkNextFreeId() {
  _freeId++;
}

void Composite::OnInit() {
  _currentChild = _children.begin();
}

void Composite::DeallocChild() {
  if (!_children.empty()) {
    for (ABehavior* child : _children) {
      delete child;
      child = nullptr;
    }
  }
}
