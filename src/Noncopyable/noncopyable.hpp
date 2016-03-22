
#pragma once


class Noncopyable {
public:
  // Object obj = other; �֎~
  Noncopyable(const Noncopyable&) = delete;

  // obj = other; �֎~
  Noncopyable operator = (const Noncopyable&) = delete;
  
  // �R���X�g���N�^,�f�X�g���N�^ default�w��
  Noncopyable() = default;
  ~Noncopyable() = default;
};