#include <node.h>
#include <node_object_wrap.h>
#include <string>
#include <stdlib.h>
#include "QPULib.h"
#include "GCDObj.h"
namespace nodeqpulib {

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Number;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void CreateObject(const FunctionCallbackInfo<Value>& args) {
	  GCDObj::NewInstance(args);
	}


	void InitAll(Local<Object> exports) {
	  GCDObj::Init(exports);

	  NODE_SET_METHOD(exports, "createObject", CreateObject);
	}

	NODE_MODULE(addon, InitAll)

}
