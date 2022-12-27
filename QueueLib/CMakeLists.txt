file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${qulib} STATIC ${srcs} ${hdrs})