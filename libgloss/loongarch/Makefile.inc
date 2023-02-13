multilibtool_DATA += %D%/crt0.o
libobjs_a_SOURCES += %D%/crt0.S

multilibtool_LIBRARIES += %D%/libgloss.a
%C%_libgloss_a_CPPFLAGS = \
	$(AM_CPPFLAGS) \
	-I$(srcdir)/%D%
%C%_libgloss_a_SOURCES = \
	%D%/_exit.c \
	%D%/chown.c \
	%D%/close.c \
	%D%/conv_stat.c \
	%D%/fstat.c \
	%D%/getpid.c \
	%D%/gettod.c \
	%D%/isatty.c \
	%D%/kill.c \
	%D%/link.c \
	%D%/lseek.c \
	%D%/open.c \
	%D%/read.c \
	%D%/readlink.c \
	%D%/sbrk.c \
	%D%/stat.c \
	%D%/symlink.c \
	%D%/times.c \
	%D%/unlink.c \
	%D%/wait.c \
	%D%/write.c
