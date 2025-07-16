#include "cmdline.h"
#include <argp.h>
#include <cstdio>
#include <stdexcept>

static char doc[] =
	"Cppixsort -- A modular pixelsorter written in C++";

static char args_doc[] =
	"<INPUT_FILE> <OUTPUT_FILE>";

static argp_option options[] = {
	{"verbose",	'v', 0,             0, "Produce VERBOSE output"},
	{"quiet",	'q', 0,				0, "MAKE THE PROGRAM be quiet"},
	{"input",	'i', "<INPUT_FILE>",	0, "Input file"},
	{"output",	'o', "OUTPUT_FILE", 0, "Output file"},
	// {"spit",	's', "file", OPTION_ALIAS, "Rofl file"},
	// {"\n=== Yo, drink some water ===", 0, 0, OPTION_DOC, ""},
	{0},
};

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
		case ARGP_KEY_ARG:  // Non-flag command line argument
			printf("Found arg of %d: '%s'\n", state->arg_num, arg);
			if (state->arg_num >= (2 - !args->input_filename.empty() - !args->output_filename.empty())) {
				printf("Too many arguments.\n");
				argp_usage(state);
			}
			args->input_filename = arg;
			break;
		case ARGP_KEY_END:
			if (args->input_filename.empty() || args->output_filename.empty()) {
				printf("You need to specify a input and an output file\n");
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

	// if (args.input_filename.empty())
		// argp_usage(0);


	return args;
}
