#ifndef RANDOM_H
#define RANDOM_H

#include <src/ai/composite/composite.hpp>
#include <src/std_includes.hpp>

class Random : public Composite {
protected:
public:
  Random();
  ~Random();
  BehaviorStatus update() override;
};

#endif
