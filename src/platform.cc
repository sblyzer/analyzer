// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "src/platform.h"

#if defined(OS_WIN)
#include <io.h>
#elif defined(OS_MAC) || defined(OS_LINUX)
#include <unistd.h>
#endif

namespace sblyzer {
namespace Platform {

void WriteFD(int fd, const void* buffer, uint32_t write_size) {
#if defined(OS_WIN)
  _write(fd, buffer, write_size);
#elif defined(OS_MAC) || defined(OS_LINUX)
  write(fd, buffer, write_size);
#endif
}

int VSNPrint(char* buffer, size_t count, const char* format, va_list args) {
#if defined(OS_WIN)
  return _vsnprintf(buffer, count, format, args);
#elif defined(OS_MAC) || defined(OS_LINUX)
  return vsnprintf(buffer, count, format, args);
#else
  return 0;
#endif
}

}  // namespace Platform
}  // namespace sblyzer