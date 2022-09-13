// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include <stdlib.h>

namespace sblyzer {
namespace base {

void Exit(int exit_code) {
  exit(exit_code);
}

}
}