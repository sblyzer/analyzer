// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef SRC_OPTIONS_H_
#define SRC_OPTIONS_H_

namespace sblyzer {

class ArgumentParser {
 public:
  virtual bool HasOption(const char* name) = 0;

  virtual void ParseArguments(int argc, char** args) = 0;
};

}  // namespace sblyzer

#endif  // SRC_OPTIONS_H_