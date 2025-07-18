#include "cmdline.h"
#include "lib/path_creator.h"
#include "lib/sorting_algorithm.h"
#include <argp.h>
#include <cstdio>
#include <memory>
#include <stdexcept>

static char doc[] =
	"Cppixsort -- A modular pixelsorter written in C++";

static char args_doc[] =
	"<INPUT_FILE> <OUTPUT_FILE>";

// Argp sorts these alphabetically, which I think is stupid
static argp_option options[] = {
	{"verbose",	'v', 0,				0, "Produce VERBOSE output"},
	{"quiet",	'q', 0,				0, "MAKE THE PROGRAM be quiet"},
	{"input",	'i', "<INPUT_FILE>",	0, "Input file"},
	{"output",	'o', "OUTPUT_FILE", 0, "Output file"},
	{"algo",	'a', "ALGO",		0, "Algorithm to use"},
	{"path",	'p', "PATH",		0, "Direction/Path"},
	{"dir",		'd', "DIRECTION", OPTION_ALIAS, ""},
	{"criteria",'c', "CRITERIA",	0, "Which pixel value to sort by"},
	{"reverse",	'r', 0,		0, "Invert the direction of the sort"},
	{"Available paths: [up,left,down,right]", 0, 0, OPTION_DOC, ""},
	{"Available algorithms: [bubble]", 0, 0, OPTION_DOC, ""},
	// {"spit",	's', "file", OPTION_ALIAS, "Rofl file"},
	// {"\n=== Yo, drink some water ===", 0, 0, OPTION_DOC, ""},
	{0},
};
#define ARG_IS(str) (string(arg) == str)

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
	cmdline_args* args = static_cast<cmdline_args*>(state->input);
	switch (key) {
		case 'v':
			args->loglevel+=1;
			break;
		case 'q':
			args->loglevel = 0;
			break;
		case 'i':
			args->input_filename = arg;
			break;
		case 'o':
			args->output_filename = arg;
			break;
		case 'r':
			args->pixelsorter.inverse = true;
			break;
		case 'c':
			if ARG_IS("brightness")
				args->pixelsorter.sorting_criteria = make_unique<Brightness>();
			break;
		case 'a':
			if ARG_IS("bubble")
				args->pixelsorter.algo = make_unique<BubbleSort>();
			else if (ARG_IS("map") or ARG_IS("mapsort"))
				args->pixelsorter.algo = make_unique<MapSort>();
			else {
				cout << "Not a valid algorithm:" << arg << endl;
				argp_usage(state);
			};
			break;
		case 'p': case 'd':
			if ARG_IS("up")
				args->pixelsorter.pathing = make_unique<LinePath>(LinePath::Direction::UP);
			else if ARG_IS("down")
				args->pixelsorter.pathing = make_unique<LinePath>(LinePath::Direction::DOWN);
			else if ARG_IS("left")
				args->pixelsorter.pathing = make_unique<LinePath>(LinePath::Direction::LEFT);
			else if ARG_IS("right")
				args->pixelsorter.pathing = make_unique<LinePath>(LinePath::Direction::RIGHT);
			else {
				cout << "Not a valid direction: " << arg << endl;
				argp_usage(state);
			};
			break;
		case ARGP_KEY_ARG:  // Non-flag command line argument
			printf("Found arg of %d: '%s'\n", state->arg_num, arg);
			if (state->arg_num >= (2 - !args->input_filename.empty() - !args->output_filename.empty())) {
				cout << "Too many arguments." << endl;
				argp_usage(state);
			}
			if (args->input_filename.empty()) args->input_filename = arg;
			else args->output_filename = arg;
			break;
		case ARGP_KEY_END:
			if (args->input_filename.empty() || args->output_filename.empty()) {
				cout << "You need to specify a input and an output file" << endl;
				argp_usage (state);
			}
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}


cmdline_args parse_arguments(int argc, char* argv[]) {
	cmdline_args args;

	static argp argp { options, parse_opt, args_doc, doc };
	static int FLAGS = 0;

	if (argp_parse(&argp, argc, argv, FLAGS, 0, &args) != 0)
		throw std::runtime_error("Failed to parse arguments.");


	return args;
}
