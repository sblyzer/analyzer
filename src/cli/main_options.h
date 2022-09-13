// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef SRC_CLI_MAIN_OPTIONS_H_
#define SRC_CLI_MAIN_OPTIONS_H_

#include <stdint.h>

#include <unordered_map>

#include "src/options.h"

namespace sblyzer {

class DefaultHashHelper {
 public:
  static uint32_t Hash32Str(const char* value) {
    if (*value == NULL)
      return 0;
    return Hash32(value, strlen(value));
  }

  template <typename T>
  static uint32_t Hash32(const T* value, uintptr_t len) {
    const uint8_t* ptr = reinterpret_cast<const uint8_t*>(value);
    return Fnv1A(ptr, len);
  }

  static const uint32_t kFnvBasis32 = 2166136261U;
  static const uint32_t kFnvPrime32 = 16777619U;

  static uint32_t Fnv1A(const uint8_t* ptr, size_t len) {
    uint32_t h = kFnvBasis32;
    for (size_t i = 0; i < len; ++i) {
      h = (h * kFnvPrime32) ^ ptr[i];
    }
    return h;
  }
};

template <typename T, typename HashHelper = DefaultHashHelper>
class UnorderedMapForCharArrayKeyHelper {
 public:
  UnorderedMapForCharArrayKeyHelper() : hash_table_() {}

  T& operator[](const char* key) { return hash_table_[HashHelper::Hash32Str(key)]; }

  size_t size() { return hash_table_.size(); }

 private:
  std::unordered_map<uint32_t, T> hash_table_;
};

class CliCommandLineParser : ArgumentParser {
 public:
  CliCommandLineParser() : arguments_table_() {}

  bool HasOption(const char* name);

  void ShowHelp();

  void ParseArguments(int argc, char** args);

 private:
  UnorderedMapForCharArrayKeyHelper<bool> arguments_table_;
};

}  // namespace sblyzer

#endif  // SRC_CLI_MAIN_OPTIONS_H_