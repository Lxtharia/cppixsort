#pragma once
#include <string>
#include "lib/pixelsorter.h"

struct cmdline_args {
    std::string input_filename;
    std::string output_filename;
    Pixelsorter pixelsorter;
    int loglevel = 1;
};

cmdline_args parse_arguments(int argc, char **argv);

