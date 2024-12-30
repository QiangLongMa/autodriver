# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dipgseg_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dipgseg_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dipgseg_FOUND FALSE)
  elseif(NOT dipgseg_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dipgseg_FOUND FALSE)
  endif()
  return()
endif()
set(_dipgseg_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dipgseg_FIND_QUIETLY)
  message(STATUS "Found dipgseg: 0.0.0 (${dipgseg_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dipgseg' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${dipgseg_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dipgseg_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dipgseg_DIR}/${_extra}")
endforeach()
