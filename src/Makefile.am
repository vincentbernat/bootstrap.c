## TODO:1001 Replace all occurrences of `bootstrap` here by the name
## TODO:1001 of your project.

## TODO:1002 Then rename the files `bootstrap.8`, `bootstrap.h` and
## TODO:1002 `bootstrap.c` by their new names.

bin_PROGRAMS = bootstrap
dist_man_MANS = bootstrap.8

## TODO:5000 When you want to add more files, add them below.
## TODO:5000 Automake will find dependencies by itself. Run
## TODO:5000 ./autogen.sh after modifying this file.

bootstrap_SOURCES  = log.c log.h bootstrap.h bootstrap.c
bootstrap_CFLAGS   = @JANSSON_CFLAGS@
bootstrap_LIBS     = @JANSSON_LIBS@

## TODO:2004 Each time you have used `PKG_CHECK_MODULES` macro
## TODO:2004 in `configure.ac`, you get two variables that
## TODO:2004 you can substitute like above.
