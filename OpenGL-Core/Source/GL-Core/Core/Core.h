#pragma once
#include <memory>

#define GLCORE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#define BIT(x)  1<<x

#define GL_CORE_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1) 