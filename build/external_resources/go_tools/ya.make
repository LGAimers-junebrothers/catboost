

RESOURCES_LIBRARY()

IF (NOT HOST_OS_DARWIN AND NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS)
    MESSAGE(FATAL_ERROR Unsupported host platform for GO_TOOLS)
ELSEIF(GOSTD_VERSION == 1.17.5)
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        GO_TOOLS
        sbr:2615736040 FOR DARWIN-ARM64
        sbr:2615734678 FOR DARWIN
        sbr:2615737306 FOR LINUX
        sbr:2615738776 FOR WIN32
    )
ELSEIF(GOSTD_VERSION == 1.18beta1)
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        GO_TOOLS
        sbr:2627176028 FOR DARWIN-ARM64
        sbr:2627174675 FOR DARWIN
        sbr:2627176927 FOR LINUX
        sbr:2627178053 FOR WIN32
    )
ELSE()
    MESSAGE(FATAL_ERROR Unsupported version [${GOSTD_VERSION}] of Go Standard Library)
ENDIF()

END()
