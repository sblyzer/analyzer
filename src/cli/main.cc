// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "src/base.h"
#include "src/cli/main_options.h"
#include "src/log.h"

#include <stdio.h>

namespace sblyzer {
namespace cli {

void Main(int argc, char** args) {
  const int kExitSuccess = 0;
  const int kExitFailure = 1;

  CliCommandLineParser parser;
  parser.ParseArguments(argc, args);

  bool show_help = false;
  if (parser.HasOption("-h") || parser.HasOption("--help") || argc == 1)
    show_help = true;
  if (show_help) {
    parser.ShowHelp();
    base::Exit(kExitSuccess);
  }

  base::Exit(kExitSuccess);
}

}  // namespace cli
}  // namespace sblyzer

int main(int argc, char* argv[]) {
  sblyzer::cli::Main(argc, argv);
  return 1;
}