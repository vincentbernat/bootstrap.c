/* -*- mode: c; c-file-style: "openbsd" -*- */
/* TODO:5002 You may want to change the copyright of all files. This is the
 * TODO:5002 ISC license. Choose another one if you want.
 */
/*
 * Copyright (c) 2014 {{cookiecutter.full_name}} <{{cookiecutter.email}}>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "{{cookiecutter.project_name}}.h"

#include <stdio.h>
#include <unistd.h>
#include <argtable2.h>
#include <string.h>

extern const char *__progname;

int
main(int argc, char *argv[])
{
	int exitcode = EXIT_FAILURE;

	/* TODO:3001 If you want to add more options, add them here. */
	struct arg_end *arg_fini    = arg_end(5);
	struct arg_lit *arg_debug   = arg_litn("d", "debug", 0, 3, "be more verbose");
	struct arg_lit *arg_help    = arg_lit0("h", "help", "display help and exit");
	struct arg_lit *arg_version = arg_lit0("v", "version", "print version and exit");
	struct arg_str *arg_filter  = arg_strn("D", NULL, NULL, 0, 10, "set allowed debug tokens");
	void *argtable[] = { arg_debug,
			     arg_help,
			     arg_version,
			     arg_filter,
			     /* Other arguments should be here */
			     arg_fini
	};

	if (arg_nullcheck(argtable) != 0) {
		fprintf(stderr, "%s: insufficient memory\n", __progname);
		goto exit;
	}

	int n = arg_parse(argc, argv, argtable);
	if (n != 0 || arg_help->count) {
		if (n != 0)  arg_print_errors(stderr, arg_fini, __progname);
		else exitcode = EXIT_SUCCESS;
		fprintf(stderr, "Usage: %s", __progname);
		arg_print_syntax(stderr, argtable, "\n");
		arg_print_glossary(stderr, argtable, "  %-25s %s\n");
		fprintf(stderr, "\n");
		fprintf(stderr, "see manual page " PACKAGE "(8) for more information\n");
		goto exit;
	}

	if (arg_version->count) {
		fprintf(stdout, "%s\n", PACKAGE_VERSION);
		exitcode = EXIT_SUCCESS;
		goto exit;
	}

	for (int i = 0; i < arg_filter->count; i++)
		log_accept(arg_filter->sval[i]);

	log_init(arg_debug->count, __progname);

	/* TODO:3000 It's time for you program to do something. Add anything
	 * TODO:3000 you want here. */
	log_info("main", "hello world!");
	log_warnx("main", "your program does nothing");

	exitcode = EXIT_SUCCESS;
exit:
	arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
	return exitcode;
}
