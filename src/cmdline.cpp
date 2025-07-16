#include "cmdline.h"
#include <argp.h>
#include <stdexcept>

static char doc[] =
	"Cppixsort -- A modular pixelsorter written in C++";

static char args_doc[] =
	"<INPUT_FILE> <OUTPUT_FILE>";

static argp_option options[] = {
	{"verbose",	'v', 0,             0, "Produce VERBOSE output"},
	{"quiet",	'q', 0,				0, "MAKE THE PROGRAM be quiet"},
	{0},
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
	cmdline_args* args = static_cast<cmdline_args*>(state->input);
	printf("Found arg: '%s'\n", arg);
	switch (key) {
		case 'v':
			args->loglevel+=1;
			break;
		case 'q':
			args->loglevel = 0;
			break;
		case ARGP_KEY_ARG:
			if (state->arg_num != 2)
				argp_usage(state);
			args->input_filename = arg;
			break;
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
