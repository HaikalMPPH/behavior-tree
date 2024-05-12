#ifndef RANDOM_H
#define RANDOM_H

#include <ai/composite/composite.hpp>
#include <std_includes.hpp>

class Random : public Composite {
protected:
public:
  Random();
  ~Random();
  BehaviorStatus Update() override;
};

#endif
