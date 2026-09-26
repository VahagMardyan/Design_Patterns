#pragma once
#include <iostream>

// // Inline variable logic before C++17

static int x = 5;

inline int& get_x() {
    return x;
}
