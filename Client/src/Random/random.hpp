
#pragma once
#include <random>
#include <type_traits>
#include "../Noncopyable/noncopyable.hpp"


class Random : public Noncopyable {
public:
  std::random_device rand_;
  std::mt19937_64    mt_;

  template<typename RandType, std::enable_if_t<std::is_arithmetic<RandType>::value, std::nullptr_t> = nullptr>
  using distribusion_t = std::conditional_t<std::is_integral<RandType>::value, std::uniform_int_distribution<RandType>, std::uniform_real_distribution<RandType>>;

  Random();
};