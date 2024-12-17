add_library(Builder STATIC person_builder.cc)
target_include_directories(Builder PUBLIC "./")