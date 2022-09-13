// Copyright (c) 2022, the SBLyzer project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "src/cli/main_options.h"

#include "src/log.h"

namespace sblyzer {

void CliCommandLineParser::ShowHelp() {
  Log::Print(
      "Usage: sblyzer <options> <-i target-sb3-file>\n"
      "\n"
      "Getting help:\n"
      "  -h or --help\n"
      "\n"
      "Common options:\n"
      "-i or --input <path>\n"
      "  Specify the target sb3 file.\n"
      "  Currently, sb2 and sb1 file formats are not supported.\n"
      "\n"
      "-o or --output <path>\n"
      "  Specify the path to the destination file.\n"
      "\n"
      "-e or --extract <element-name>\n"
      "  Extracts the given element in the sb3 file.\n"
      "\n"
      "-q or --query\n"
      "  Enumerates files present in the sb3 file."
      "\n"
      "\n"
      "Example:\n"
      "Extract JSON:\n"
      "  sblyzer -e json -o extracted.json -i foo.sb3\n"
      "\n"
      "Enumerate files in sb3 file:\n"
      "  sblyzer -q -i bar.sb3\n"
      "\n"
      "Add indentation to the json file to be expanded:\n"
      "  sblyzer -e json-indent -o extracted.json -i foo.sb3\n"
      "\n"
      "Packaging:\n"
      "  sblyzer -o output.sb3 -i baz.sb3 extracted.json"
      "\n"
  );
}

bool CliCommandLineParser::HasOption(const char* name) {
  return arguments_table_[name] == true;
}

void CliCommandLineParser::ParseArguments(int argc, char** args) {
  for (int i = 0; i < argc; ++i)
    arguments_table_[args[i]] = true;
}

}  // namespace sblyzer