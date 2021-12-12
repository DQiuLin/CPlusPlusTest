cmake_minimum_required(VERSION 3.15)
project(CPlusPlusTest)

set(CMAKE_CXX_STANDARD 14)


include(./.SET_LOCAL_PATH.cmake)


if(MSVC)
    SET(CMAKE_CXX_FLAGS "/utf-8" "${CMAKE_CXX_FLAGS}")    # for CPP
    SET(CMAKE_C_FLAGS "/utf-8" "${CMAKE_C_FLAGS}")        # for C
endif(MSVC)

ADD_DEFINITIONS(-D__STDC_LIMIT_MACROS -D_WEBSOCKETPP_CPP11_STL_ -DASIO_STANDALONE)

aux_source_directory(src CPPLIST)

add_executable(
        ${PROJECT_NAME}
        ${CPPLIST}
        )



target_include_directories( ${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

if(UNIX)
    target_link_libraries( ${PROJECT_NAME}
            PRIVATE    
            )
else()
    target_link_libraries( ${PROJECT_NAME}
            PRIVATE
            )
endif()