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
using v8::Array;
using v8::Number;

void SetNumQPUsMethod(const FunctionCallbackInfo<Value>& args) {
  GCDObj* gcdObj = node::ObjectWrap::Unwrap<GCDObj>(
              args[0]->ToObject());
  void (*kernel)(Ptr<Int>, Ptr<Int>, Ptr<Int>)  = gcdObj->getKernel(); 
  auto k = compile(*kernel);
  int numQPUs = args[1]->NumberValue();
  k.setNumQPUs(numQPUs);

}

void GCDMethod(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  // Construct kernel

  GCDObj* gcdObj = node::ObjectWrap::Unwrap<GCDObj>(
              args[0]->ToObject());
  void (*kernel)(Ptr<Int>, Ptr<Int>, Ptr<Int>)  = gcdObj->getKernel(); 
  
  auto k = compile(*kernel);
  k.setNumQPUs(8);
 
  Local<Array> inputA = Local<Array>::Cast(args[1]);
  Local<Array> inputB = Local<Array>::Cast(args[2]);
  unsigned int numberOfElements = inputA->Length();
  // Allocate and initialise arrays shared between ARM and GPU
  SharedArray<int> a(numberOfElements), b(numberOfElements), r(numberOfElements);
  srand(0);
  for (int i = 0; i < numberOfElements; i++) {
    
    a[i] = inputA->Get(i)->NumberValue();
    b[i] = inputB->Get(i)->NumberValue();
  }

  // Invoke the kernel and display the result
  k(&a, &b, &r);
  for (int i = 0; i < 16; i++)
    printf("gcd(%i, %i) = %i\n", a[i], b[i], r[i]);

  std::string s = std::to_string(r[0]);
 
  // we'll populate this with the results
    Local<Array> result_list = Array::New(isolate);
    for (unsigned int i = 0; i < numberOfElements; i++ ) {
        result_list->Set(i, Number::New(isolate, r[i]));
    }
   
    // ... and send it back to Node.js as the return value
    args.GetReturnValue().Set(result_list);

  //Isolate* isolate = args.GetIsolate();
  //args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Done"));
}



void init(Local<Object> exports) {
  GCDObj::Init(exports);
  NODE_SET_METHOD(exports, "qpugcd", GCDMethod);
  NODE_SET_METHOD(exports, "setNumQPUs", SetNumQPUsMethod);
}

NODE_MODULE(addon, init)

}  // namespace nodeqpulib
