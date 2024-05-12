#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <ai/composite/composite.hpp>

class Sequence : public Composite {
protected:
public:
  Sequence();
  ~Sequence();
  BehaviorStatus Update() override;
};

#endif
