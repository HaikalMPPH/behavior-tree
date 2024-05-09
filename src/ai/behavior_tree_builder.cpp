#include <ai/behavior_tree_builder.hpp>

BehaviorTreeBuilder::BehaviorTreeBuilder() 
    : _bt {new BehaviorTree()} {
}

BehaviorTreeBuilder::~BehaviorTreeBuilder() {}

BehaviorTreeBuilder* BehaviorTreeBuilder::root(ABehavior* node) {
  _bt->set_root(node);
  _bt->get_root()->set_parent(nullptr);
  _current = _bt->get_root();
  return this;
}

// Add a composite node to child of a node
BehaviorTreeBuilder* BehaviorTreeBuilder::composite(Composite* node) {
  if (_current->_can_have_child) {
    if (_current->_can_have_multi_child) {
      static_cast<Composite*>(_current)->add_child(node);

      // _current is now pointing to at it's newly added child.
      //_current = 
      //  static_cast<Sequence*>(_current)
      //  ->get_child_at(_current->_free_id);
      _current = static_cast<Composite*>(_current)->get_active_child();

      // mark the vec index of _current parent index of the vector 
      // as "filled" so it wont reassign to this index.
      static_cast<Composite*>(_current->get_parent())->mark_next_free_id();
    }
    else {
      static_cast<Decorator*>(_current)->add_child(node);
      _current = static_cast<Decorator*>(_current)->get_child();
    }
  }
  return this;
}

// Add a action node to child of a node
BehaviorTreeBuilder* BehaviorTreeBuilder::action(Action::ActionFn fn) {
  // if the parent is either composite. or decorators (can have child).
  if (_current->_can_have_child) {
    // if the parent is a composite (multiple child).
    if (_current->_can_have_multi_child) {
      static_cast<Composite*>(_current)->add_child(new Action(fn));
      static_cast<Composite*>(_current)->mark_next_free_id();
    }
    // if the parent is a decorator.
    else {
      static_cast<Decorator*>(_current)->add_child(new Action(fn));
    }
  }


  return this;
}


// return to the previous node (it's parent).
BehaviorTreeBuilder* BehaviorTreeBuilder::end() {
  if (_current->get_parent() != nullptr) {
    _current = _current->get_parent();
  }
  return this;
}

BehaviorTree* BehaviorTreeBuilder::create_tree() {
  return _bt;
}
