#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <src/ai/composite/composite.h>

class Sequence : public Composite {
protected:
public:
  Sequence();
  ~Sequence();
  BehaviorStatus update() override;
};

#endif
