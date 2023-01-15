# Generated by devtools/yamaker from nixpkgs 5852a21819542e6809f68ba5a798600e69874e76.

LIBRARY()



VERSION(1.0.6.0.1)

LICENSE(BSD-4-Clause)

ADDINCL(
    contrib/libs/libbz2
)

NO_COMPILER_WARNINGS()

NO_RUNTIME()

IF (SANITIZER_TYPE STREQUAL undefined)
    NO_SANITIZE()
ENDIF()

SRCS(
    blocksort.c
    bzlib.c
    compress.c
    crctable.c
    decompress.c
    huffman.c
    randtable.c
)

END()
