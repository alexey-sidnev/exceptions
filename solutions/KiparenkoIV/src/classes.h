#pragma once
#ifndef SOLUTIONS_KIPARENKOIV_SRC_CLASSES_H_
#define SOLUTIONS_KIPARENKOIV_SRC_CLASSES_H_

class A {
 public:
  virtual bool member() {
    return false;
  }
};

class B : public A {
 public:
  bool member() {
    return true;
  }
};

#endif  // SOLUTIONS_KIPARENKOIV_SRC_CLASSES_H_
