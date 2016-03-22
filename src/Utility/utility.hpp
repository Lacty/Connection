
#pragma once
#include <type_traits>
#include "../Vector/vector.hpp"


double toRadians(float deg);

Vec3f nearPosOnLine(const Vec3f& p,
                    const Vec3f& vA,
                    const Vec3f& vB);


template<typename Vec, typename T>
Vec convertArrayToVec(T* array) {
  Vec v;
  
  for (int i = 0; i < v.rows(); i++) {
    v[i] = array[i];
  }
  
  return v;
}