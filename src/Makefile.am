## TODO:10011 Replace all occurrences of `bootstrap` here by the name
## TODO:10012 of your project.

## TODO:10021 Then rename the files `bootstrap.8`, `bootstrap.h` and
## TODO:10022 `bootstrap.c` by their new names.

bin_PROGRAMS = bootstrap
dist_man_MANS = bootstrap.8

## TODO:50001 When you want to add more files, add them below.
## TODO:50002 Automake will find dependencies by itself. Run
## TODO:50003 ./autogen.sh after modifying this file.

bootstrap_SOURCES  = log.c log.h bootstrap.h bootstrap.c
bootstrap_CFLAGS   = @JANSSON_CFLAGS@
bootstrap_LIBS     = @JANSSON_LIBS@

## TODO:20041 Each time you have used `PKG_CHECK_MODULES` macro
## TODO:20042 in `configure.ac`, you get two variables that
## TODO:20043 you can substitute like above.
