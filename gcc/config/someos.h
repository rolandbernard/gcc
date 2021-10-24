
#undef TARGET_SOMEOS
#define TARGET_SOMEOS 1
 
/* Default arguments you want when running the toolchain */
#undef LIB_SPEC
#define LIB_SPEC "-lc" /* link against C standard library */
 
/* Files that are linked before user code. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s crti.o%s crtbegin.o%s"
 
/* Files that are linked after user code. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"
 
#undef STANDARD_STARTFILE_PREFIX
#define STANDARD_STARTFILE_PREFIX "/lib/"

/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__someos__");      \
    builtin_define ("__unix__");      \
    builtin_assert ("system=someos");   \
    builtin_assert ("system=unix");   \
    builtin_assert ("system=posix");   \
  } while(0);

