# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\IMDAP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\IMDAP_autogen.dir\\ParseCache.txt"
  "IMDAP_autogen"
  )
endif()
