#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rabbit_interfaces::rabbit_interfaces__rosidl_typesupport_cpp" for configuration ""
set_property(TARGET rabbit_interfaces::rabbit_interfaces__rosidl_typesupport_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(rabbit_interfaces::rabbit_interfaces__rosidl_typesupport_cpp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librabbit_interfaces__rosidl_typesupport_cpp.so"
  IMPORTED_SONAME_NOCONFIG "librabbit_interfaces__rosidl_typesupport_cpp.so"
  )

list(APPEND _cmake_import_check_targets rabbit_interfaces::rabbit_interfaces__rosidl_typesupport_cpp )
list(APPEND _cmake_import_check_files_for_rabbit_interfaces::rabbit_interfaces__rosidl_typesupport_cpp "${_IMPORT_PREFIX}/lib/librabbit_interfaces__rosidl_typesupport_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)