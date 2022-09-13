// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef SRC_BASE_H_
#define SRC_BASE_H_

namespace sblyzer {
namespace base {

void Exit(int exit_code);

template <typename T>
void SetExitHook(T exit_hook) {
  atexit(exit_hook);
}

}
}

#endif  // SRC_BASE_H_