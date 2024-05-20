# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\fiokokKezeleseAdminisztrator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\fiokokKezeleseAdminisztrator_autogen.dir\\ParseCache.txt"
  "fiokokKezeleseAdminisztrator_autogen"
  )
endif()
