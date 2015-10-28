#pragma once
#ifndef SOLUTIONS_PETROVA_SRC_CLASSES_H_
#define SOLUTIONS_PETROVA_SRC_CLASSES_H_

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

#endif  // SOLUTIONS_PETROVA_SRC_CLASSES_H
