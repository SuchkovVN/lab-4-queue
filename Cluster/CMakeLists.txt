file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_executable(${clst} ${srcs} ${hdrs})

target_link_libraries(${clst} ${clib})