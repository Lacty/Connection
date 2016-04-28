
#pragma once
#include "../Noncopyable/noncopyable.hpp"
#include <set>


class Key : public Noncopyable {
private:
  std::set<int> push_;
  std::set<int> pull_;
  std::set<int> press_;

public:
  void clear() {
    push_.clear();
    pull_.clear();
  }

  void setKeyPush(int key) { push_.emplace(key); }
  void setKeyPull(int key) { pull_.emplace(key); }
  void setKeyPress(int key) { press_.emplace(key); }

  void popKeyPress(int key) { press_.erase(press_.find(key)); }

  bool isPush(int key) {
    if (push_.find(key) == push_.end()) return false;
    push_.erase(push_.find(key));
    return true;
  }

  bool isPull(int key) {
    if (pull_.find(key) == pull_.end()) return false;
    pull_.erase(pull_.find(key));
    return true;
  }

  bool isPress(int key) {
    if (press_.find(key) == press_.end()) return false;
    return true;
  }
};
