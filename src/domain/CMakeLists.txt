set(DOMAIN_SOURCES 
    sudoku.cpp
    sudoku.h)

add_library(domain ${DOMAIN_SOURCES})

target_include_directories(domain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install(FILES sudoku.h DESTINATION ${INSTALL_INCLUDE_DIR})
