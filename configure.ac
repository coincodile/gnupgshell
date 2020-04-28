AC_PREREQ(2.61)
min_automake_version="1.14"

#############################################################################
# Initial
#############################################################################
# Autoconf
AC_INIT([gnupgshell], [1.0], [mostafa.barmshory@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/gnupgshell.vers])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_LIBOBJ_DIR([compat])
AC_CANONICAL_HOST

# Automake
AM_INIT_AUTOMAKE([serial-tests dist-bzip2])
AM_MAINTAINER_MODE
AM_SILENT_RULES

#############################################################################
# Checks for programs.
#############################################################################

AC_PROG_MAKE_SET
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_AWK
AC_PROG_GREP
AC_ISC_POSIX
AC_GNU_SOURCE

missing_dir=`cd $ac_aux_dir && pwd`
AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
# AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
AM_PROG_CC_C_O
AM_PROG_AS


LT_PREREQ([2.2.6])
LT_INIT([win32-dll disable-static])
LT_LANG([Windows Resource])

#############################################################################
# Checks for libraries.
#############################################################################


#############################################################################
# Checks for header files.
#############################################################################
AC_CHECK_HEADER([limits.h])
AC_CHECK_HEADER([unistd.h])

# wxprec
AM_OPTIONS_WXCONFIG
reqwx=2.4.0
AM_PATH_WXCONFIG($reqwx, wxWin=1)
if test "$wxWin" != 1; then
	AC_MSG_ERROR([
		wxWidgets must be installed on your system.

		Please check that wx-config is in path, the directory
		where wxWidgets libraries are installed (returned by
		'wx-config --libs' or 'wx-config --static --libs' command)
		is in LD_LIBRARY_PATH or equivalent variable and
		wxWidgets version is $reqwx or above.
		])
fi
CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"
LIBS="$LIBS $WX_LIBS"


#############################################################################
# Checks for typedefs, structures, and compiler characteristics.
#############################################################################
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T



#############################################################################
# Checks for library functions.
#############################################################################




###################################Ourput####################################
AC_CONFIG_FILES([
 Makefile
 m4/Makefile
 wxTranslationHelper/Makefile
 src/Makefile
])
AC_OUTPUT