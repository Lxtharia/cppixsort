#pragma once
#include <string>
#include "lib/pixelsorter.h"

struct cmdline_args {
    std::string input_filename;
    std::string output_filename;
    Pixelsorter pixelsorter;
    int loglevel = 1;
};

void parse_arguments(int argc, char* argv[], cmdline_args& args);

