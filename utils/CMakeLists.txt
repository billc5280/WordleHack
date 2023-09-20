project(utils_lib)

set(HEADER_FILES
        Utils.h
        )

set(SOURCE_FILES
        Utils.cpp
        )

add_library(utils_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
