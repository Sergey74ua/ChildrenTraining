# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appFinal_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appFinal_autogen.dir\\ParseCache.txt"
  "appFinal_autogen"
  )
endif()
