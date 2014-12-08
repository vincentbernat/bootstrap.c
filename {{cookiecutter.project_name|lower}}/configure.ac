#                                               -*- Autoconf -*-
AC_PREREQ([2.64])

AC_INIT([{{cookiecutter.project_name}}],
        [m4_esyscmd_s([./get-version])],
        [{{cookiecutter.email}}])
AC_CONFIG_SRCDIR([src/log.c])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror tar-ustar])
AM_MAINTAINER_MODE
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES(yes)])
m4_pattern_allow([AM_PROG_AR])
AM_PROG_AR

# Configure libtool
LT_INIT

#######################
### Checks

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_CXX
AM_PROG_CC_C_O
AC_PROG_LIBTOOL
AC_PROG_LN_S
AC_PROG_EGREP

# Check some compiler flags
AX_CFLAGS_GCC_OPTION([-fdiagnostics-show-option])
AX_CFLAGS_GCC_OPTION([-pipe])
AX_CFLAGS_GCC_OPTION([-Wall])
AX_CFLAGS_GCC_OPTION([-W])
AX_CFLAGS_GCC_OPTION([-Wextra])
AX_CFLAGS_GCC_OPTION([-Wformat])
AX_CFLAGS_GCC_OPTION([-Wformat-security])
AX_CFLAGS_GCC_OPTION([-Wfatal-errors])
AX_CFLAGS_GCC_OPTION([-Wcast-align])
AX_CFLAGS_GCC_OPTION([-Winline])
AX_CFLAGS_GCC_OPTION([-fstack-protector])
AX_CFLAGS_GCC_OPTION([-D_FORTIFY_SOURCE=2])
AX_CFLAGS_GCC_OPTION([-Wno-unused-parameter])
AX_CFLAGS_GCC_OPTION([-Wno-missing-field-initializers])
AX_LDFLAGS_OPTION([-Wl,-z,relro])
AX_LDFLAGS_OPTION([-Wl,-z,now])

dnl Enable _GNU_SOURCE and the like
AX_CFLAGS_GCC_OPTION([-D_GNU_SOURCE])    dnl GNU systems (asprintf, ...)
case $host_os in
   solaris*)
     AX_CFLAGS_GCC_OPTION([-D__EXTENSIONS__]) dnl (CMSG_*)
     AX_CFLAGS_GCC_OPTION([-D_XPG4_2])        dnl (CMSG_*)
     ;;
   hpux*)
     AX_CFLAGS_GCC_OPTION([-D_XOPEN_SOURCE=500])      dnl HP-UX
     AX_CFLAGS_GCC_OPTION([-D_XOPEN_SOURCE_EXTENDED]) dnl HP-UX
     ;;
esac

AC_CACHE_SAVE

## TODO:2003 Add the dependencies of your project here.
## TODO:2003 The use of "argtable2" here is not mandatory. You don't have
## TODO:2003 to keep it.

PKG_CHECK_MODULES([ARGTABLE], [argtable2 >= 9])

AC_CACHE_SAVE

AC_OUTPUT

cat <<EOF

------------------ Summary ------------------
 $PACKAGE_NAME version $PACKAGE_VERSION
  Prefix.........: $prefix
  C Compiler.....: $CC $CFLAGS $CPPFLAGS
  Linker.........: $LD $LDFLAGS $LIBS
---------------------------------------------

Check the above options and compile with:
 ${MAKE-make}

EOF
