// hello.cc
#include <node.h>
#include <string>
#include <stdlib.h>
#include "QPULib.h"
#include "kernels/GCDObj.h"

namespace nodeqpulib {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void gcd(Ptr<Int> p, Ptr<Int> q, Ptr<Int> r)
{
  Int a = *p;
  Int b = *q;
  While (any(a != b))
    Where (a > b)
      a = a-b;
    End
    Where (a < b)
      b = b-a;
    End
  End
  *r = a;
}

void GCDMethod(const FunctionCallbackInfo<Value>& args) {

  
  // Construct kernel
 // auto k = compile(gcd);

  GCDObj* gcdObj = node::ObjectWrap::Unwrap<GCDObj>(
              args[0]->ToObject());
  void (*kernel)(Ptr<Int>, Ptr<Int>, Ptr<Int>)  = gcdObj->getKernel(); 
  
  auto k = compile(*kernel);
  
  // Allocate and initialise arrays shared between ARM and GPU
  SharedArray<int> a(16), b(16), r(16);
  srand(0);
  for (int i = 0; i < 16; i++) {
    a[i] = 100 + (rand() % 100);
    b[i] = 100 + (rand() % 100);
  }

  // Invoke the kernel and display the result
  k(&a, &b, &r);
  for (int i = 0; i < 16; i++)
    printf("gcd(%i, %i) = %i\n", a[i], b[i], r[i]);

  std::string s = std::to_string(r[0]);
 
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Done"));
}



void init(Local<Object> exports) {
  GCDObj::Init(exports);
  //NODE_SET_METHOD(exports, "qpulib", Method);
  NODE_SET_METHOD(exports, "qpugcd", GCDMethod);
}

NODE_MODULE(addon, init)

}  // namespace nodeqpulib
