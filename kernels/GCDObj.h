// myobject.h
#ifndef GCD_H
#define GCD_H

#include <node.h>
#include <node_object_wrap.h>
#include "QPULib.h"

namespace nodeqpulib {
typedef void (*krnl)(Ptr<Int> p, Ptr<Int> q, Ptr<Int> r);
class GCDObj : public node::ObjectWrap {
 public:
  static void Init(v8::Local<v8::Object> exports);
  static void NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args);
  static krnl getKernel();

 private:
  explicit GCDObj();
  ~GCDObj();

  static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
  static v8::Persistent<v8::Function> constructor;
  double value_;
};

}  // namespace nodeqpulib

#endif
