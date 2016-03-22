
#pragma once


class Noncopyable {
public:
  // Object obj = other; 禁止
  Noncopyable(const Noncopyable&) = delete;

  // obj = other; 禁止
  Noncopyable operator = (const Noncopyable&) = delete;
  
  // コンストラクタ,デストラクタ default指定
  Noncopyable() = default;
  ~Noncopyable() = default;
};