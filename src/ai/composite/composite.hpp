#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <std_includes.hpp>
#include <ai/behavior.hpp>

class Composite : public ABehavior {
protected:
  using ChildVec = std::vector<ABehavior*>;
  ChildVec _children;
  ChildVec::iterator _currentChild;

  // The next assignable child index. It's also the number of child it 
  // have.
  unsigned int _freeId;

public:
  Composite();
  virtual ~Composite();

  void AddChild(ABehavior* node);
  ABehavior* GetChildAt(unsigned int i);
  ABehavior* GetActiveChild();
  void MarkNextFreeId();
  void DeallocChild();
  void OnInit() override;
};

#endif
