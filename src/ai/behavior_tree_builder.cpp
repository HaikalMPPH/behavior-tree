#include <ai/behavior_tree_builder.hpp>

BehaviorTreeBuilder::BehaviorTreeBuilder() 
    : _bt {new BehaviorTree()} {
}

BehaviorTreeBuilder::~BehaviorTreeBuilder() {}

BehaviorTreeBuilder* BehaviorTreeBuilder::AddRoot(ABehavior* node) {
  _bt->SetRoot(node);
  _bt->GetRoot()->SetParent(nullptr);
  _current = _bt->GetRoot();
  return this;
}

// Add a Composite node to child of a node
BehaviorTreeBuilder* BehaviorTreeBuilder::AddComposite(Composite* node) {
  if (_current->_canHaveChild) {
    if (_current->_canHaveMultiChild) {
      static_cast<Composite*>(_current)->AddChild(node);

      // _current is now pointing to at it's newly added child.
      _current = static_cast<Composite*>(_current)->GetActiveChild();

      // mark the vec index of _current parent index of the vector 
      // as "filled" so it wont reassign to this index.
      static_cast<Composite*>(_current->GetParent())->MarkNextFreeId();
    }
    else {
      static_cast<Decorator*>(_current)->AddChild(node);
      _current = static_cast<Decorator*>(_current)->GetChild();
    }
  }
  return this;
}

// Add a Decorator node to child of a node
BehaviorTreeBuilder* BehaviorTreeBuilder::AddDecorator(Decorator* node) {
  if (_current->_canHaveChild) {
    if (_current->_canHaveMultiChild) {
      static_cast<Composite*>(_current)->AddChild(node);

      _current = static_cast<Composite*>(_current)->GetActiveChild();

      static_cast<Composite*>(_current->GetParent())->MarkNextFreeId();
    }
    else {
      static_cast<Decorator*>(_current)->AddChild(node);
      _current = static_cast<Decorator*>(_current)->GetChild();
    }
  }
  return this;
}

// Add a Action node to child of a node
BehaviorTreeBuilder* BehaviorTreeBuilder::AddAction(Action* node) {
  // if the parent is either AddComposite. or decorators (can have child).
  if (_current->_canHaveChild) {
    // if the parent is a AddComposite (multiple child).
    if (_current->_canHaveMultiChild) {
      static_cast<Composite*>(_current)->AddChild(node);
      static_cast<Composite*>(_current)->MarkNextFreeId();
    }
    // if the parent is a AddDecorator.
    else {
      static_cast<Decorator*>(_current)->AddChild(node);
    }
  }
  return this;
}
// Add a Condition node to child of a node
BehaviorTreeBuilder* BehaviorTreeBuilder::AddCondition(Condition* node) {
  if (_current->_canHaveChild) {
    if (_current->_canHaveMultiChild) {
      static_cast<Composite*>(_current)->AddChild(node);
      static_cast<Composite*>(_current)->MarkNextFreeId();
    }
    else {
      static_cast<Decorator*>(_current)->AddChild(node);
    }
  }
  return this;
}


// return to the previous node (it's parent).
BehaviorTreeBuilder* BehaviorTreeBuilder::End() {
  if (_current->GetParent() != nullptr) {
    _current = _current->GetParent();
  }
  return this;
}

BehaviorTree* BehaviorTreeBuilder::CreateTree() {
  return _bt;
}
