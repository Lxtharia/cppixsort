#include <string>
#include "lib/pixelsorter.h"
#include "lib/path_creator.h"
#include "lib/sorting_algorithm.h"

struct cmdline_args {
    std::string input_filename;
    std::string output_filename;
    Pixelsorter pixelsorter;
    int loglevel = 1;
};

cmdline_args parse_cmdline(int argc, char **argv);

