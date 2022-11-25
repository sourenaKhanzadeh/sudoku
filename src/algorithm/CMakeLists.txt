set(ALG_SOURCES
    solver.cpp
    solver.h)

add_library(alg ${ALG_SOURCES})

target_include_directories(alg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install(FILES solver.h DESTINATION ${INSTALL_INCLUDE_DIR})