cmake_minimum_required(VERSION 3.1)

include_directories(
  include
  include/gio
  include/glib
  include/gmodule
  include/gobject
  include/gthread)

add_executable(glib_test glib_test.cpp)

file(GLOB GLIB_PREBUILT_LIBRARIES "lib/*.so*")
message("LIBRARIES = ${GLIB_PREBUILT_LIBRARIES}")
target_link_libraries(glib_test ${GLIB_PREBUILT_LIBRARIES})

add_library(gio2 SHARED IMPORTED)
set_property(TARGET gio2 PROPERTY IMPORTED_LOCATION "lib/libgio-2.0.so")

add_library(glib2 SHARED IMPORTED)
set_property(TARGET glib2 PROPERTY IMPORTED_LOCATION "lib/libglib-2.0.so")

add_library(gmodule2 SHARED IMPORTED)
set_property(TARGET gmodule2 PROPERTY IMPORTED_LOCATION "lib/libgmodule-2.0.so")

add_library(gobject2 SHARED IMPORTED)
set_property(TARGET gobject2 PROPERTY IMPORTED_LOCATION "lib/libgobject-2.0.so")

add_library(gthread2 SHARED IMPORTED)
set_property(TARGET gthread2 PROPERTY IMPORTED_LOCATION "lib/libgthread-2.0.so")
