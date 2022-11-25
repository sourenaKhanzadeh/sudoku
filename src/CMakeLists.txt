set(SOURCE 
    main.cpp
)
add_subdirectory(algorithm)
add_subdirectory(domain)


add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries( ${PROJECT_NAME} alg domain)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${INCLUDE_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/bin)