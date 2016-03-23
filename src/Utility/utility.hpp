
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

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
std::vector<char> addArithmeticDataToVector(T src, std::vector<char> data) {
  std::string str;
  str = std::to_string(src);
  data.push_back(NULL); // add NULL for punctuation
  for (size_t i = 0; i < str.size(); i++) {
    data.push_back((char)str[i]);
  }
  return std::move(data);
}