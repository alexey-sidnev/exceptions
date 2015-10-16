#pragma once
#ifndef CLASSES_H
#define CLASSES_H

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

#endif  // CLASSES_H
