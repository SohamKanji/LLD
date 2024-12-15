add_library(SingleResponsibility STATIC single_responsibility_principle.cc)
target_include_directories(SingleResponsibility PUBLIC "./")

add_library(OpenClosed STATIC open_closed_principle.cc)
target_include_directories(OpenClosed PUBLIC "./")

add_library(LiskovSubstitution STATIC liskov_substitution_principle.cc)
target_include_directories(LiskovSubstitution PUBLIC "./")

add_library(InterfaceSegregation INTERFACE)
target_include_directories(InterfaceSegregation INTERFACE "./")

add_library(DependencyInversion INTERFACE)
target_include_directories(DependencyInversion INTERFACE "./")