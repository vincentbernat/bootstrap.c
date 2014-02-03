bin_PROGRAMS = {{cookiecutter.project_name|lower}}
dist_man_MANS = {{cookiecutter.project_name|lower}}.8

## TODO:5000 When you want to add more files, add them below.
## TODO:5000 Automake will find dependencies by itself. Run
## TODO:5000 ./autogen.sh after modifying this file.

{{cookiecutter.project_name|lower}}_SOURCES  = log.c log.h {{cookiecutter.project_name|lower}}.h {{cookiecutter.project_name|lower}}.c
{{cookiecutter.project_name|lower}}_CFLAGS   = @ARGTABLE_CFLAGS@
{{cookiecutter.project_name|lower}}_LDFLAGS  = @ARGTABLE_LIBS@

## TODO:2004 Each time you have used `PKG_CHECK_MODULES` macro
## TODO:2004 in `configure.ac`, you get two variables that
## TODO:2004 you can substitute like above.
