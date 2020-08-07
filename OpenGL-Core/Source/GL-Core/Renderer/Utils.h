#pragma once
#include <stdlib.h>

#include <ctime>
#include <type_traits>

inline float GetNCV(int i_Value)
{
	return static_cast<float>(i_Value)/ 255.0f;
}
template<typename T>
T RandomInRange(T i_MinValue, T i_MaxValue)
{
	T randValue;
	constexpr int c = std::is_same<T, int>::value;
#if c
	if (std::is_same<T, int>::value)
	{
		randValue = rand() % i_MaxValue + i_MinValue;
	}
#endif
	if (std::is_same<T, float>::value)
	{
		randValue = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (i_MaxValue-i_MinValue)));
	}

	return randValue;
}