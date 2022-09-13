// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef SRC_LOG_H_
#define SRC_LOG_H_

#include <stdarg.h>

namespace sblyzer {
namespace Log {

void Print(const char* format, ...);
void FDPrint(int fd, const char* format, va_list args);

void SetTextOutputFD(int fd);

}
}

#endif  // SRC_LOG_H_