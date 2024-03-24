#pragma once

template <class T>
void Limit(T& _t, T min, T max)
{
    if (_t < min) _t = min;
    if (_t > max) _t = max;
}
