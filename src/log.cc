// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "src/log.h"
#include "src/base.h"
#include "src/platform.h"

namespace sblyzer {
namespace Log {

// stdout
static int output = 1;

void PrintError(const char* format, ...) {
  va_list args;
  va_start(args, format);
  FDPrint(2, format, args);
  va_end(args);
}

void Print(const char* format, ...) {
  va_list args;
  va_start(args, format);
  FDPrint(output, format, args);
  va_end(args);
}

void FDPrint(int fd, const char* format, va_list args) {
  va_list measure_args;
  va_copy(measure_args, args);
  int len = Platform::VSNPrint(NULL, 0, format, measure_args) + 1;
  va_end(measure_args);

  char* buffer = new char[len];
  va_list print_args;
  va_copy(print_args, args);
  Platform::VSNPrint(buffer, len, format, print_args);
  va_end(print_args);

  Platform::WriteFD(output, buffer, len);
  delete[] buffer;
}

void SetTextOutputFD(int fd) {
  output = fd;
}

}  // namespace Log
}  // namespace sblyzer