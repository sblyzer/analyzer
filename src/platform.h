// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef SRC_PLATFORM_H_
#define SRC_PLATFORM_H_

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

namespace sblyzer {
namespace Platform {

void WriteFD(int fd, const void* buffer, uint32_t write_size);

int VSNPrint(char* buffer, size_t count, const char* format, va_list args);

}  // namespace Platform
}  // namespace sblyzer

#endif  // SRC_PLATFORM_H_