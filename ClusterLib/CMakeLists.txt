file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${clib} STATIC ${srcs} ${hdrs})