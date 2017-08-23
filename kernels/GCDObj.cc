// myobject.cc
#include <node.h>
#include "GCDObj.h"
#include "QPULib.h"
namespace nodeqpulib {

	using v8::Context;
	using v8::Function;
	using v8::FunctionCallbackInfo;
	using v8::FunctionTemplate;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::Persistent;
	using v8::String;
	using v8::Value;

	Persistent<Function> GCDObj::constructor;

	void kernel(Ptr<Int> p, Ptr<Int> q, Ptr<Int> r) {
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
        };

	GCDObj::GCDObj() {
	}

	GCDObj::~GCDObj() {
	}

	void GCDObj::Init(Local<Object> exports) {
	 Isolate* isolate = exports->GetIsolate();
	  // Prepare constructor template
	  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
	  tpl->SetClassName(String::NewFromUtf8(isolate, "GCDObj"));
	  tpl->InstanceTemplate()->SetInternalFieldCount(1);

	  constructor.Reset(isolate, tpl->GetFunction());
	}

	void GCDObj::New(const FunctionCallbackInfo<Value>& args) {
	  Isolate* isolate = args.GetIsolate();

	  if (args.IsConstructCall()) {
	    // Invoked as constructor: `new GCDObj(...)`
	    GCDObj* obj = new GCDObj();
	    obj->Wrap(args.This());
	    args.GetReturnValue().Set(args.This());
	  } else {
	    // Invoked as plain function `GCDObj(...)`, turn into construct call.
	    const int argc = 0;
	    Local<Value> argv[0] = { };
	    Local<Context> context = isolate->GetCurrentContext();
	    Local<Function> cons = Local<Function>::New(isolate, constructor);
	    Local<Object> instance =
	        cons->NewInstance(context, argc, argv).ToLocalChecked();
	    args.GetReturnValue().Set(instance);
	  }
	}

	void GCDObj::NewInstance(const FunctionCallbackInfo<Value>& args) {
	  Isolate* isolate = args.GetIsolate();

	  const unsigned argc = 0;
	  Local<Value> argv[0] = { };
	  Local<Function> cons = Local<Function>::New(isolate, constructor);
	  Local<Context> context = isolate->GetCurrentContext();
	  Local<Object> instance =
	      cons->NewInstance(context, argc, argv).ToLocalChecked();

	  args.GetReturnValue().Set(instance);
	}

	krnl GCDObj::getKernel() {
		return kernel;
	}
}  // namespace gcd
