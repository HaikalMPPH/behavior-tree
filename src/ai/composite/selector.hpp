#ifndef SELETOR_HPP
#define SELETOR_HPP

class Selector : public Composite {
protected:
public:
  Selector();
  ~Selector();
  BehaviorStatus update() override;
}

#endif
