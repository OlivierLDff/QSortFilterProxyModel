#
#   Kratos CMake script by Olivier Le Doeuff
#

# ┌──────────────────────────────────────────────────────────────────┐
# │                       CMAKE PROPERTIES                           │
# └──────────────────────────────────────────────────────────────────┘

cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       PROJECT SETTINGS                           │
# └──────────────────────────────────────────────────────────────────┘

set(SFPM_TARGET "SortFilterProxyModel" CACHE STRING "Target Name")
set(SFPM_PROJECT "SortFilterProxyModel" CACHE STRING "Project Name")
set(SFPM_BUILD_SHARED OFF CACHE BOOL "Build SortFilterProxyModel as a shared library")
set(SFPM_FOLDER_PREFIX ${SFPM_PROJECT} CACHE STRING "Prefix folder for all SortFilterProxyModel generated targets in generated project (only decorative)")
set(SFPM_ENABLE_TESTS OFF CACHE BOOL "Build SortFilterProxyModel tests")

set(SFPM_VERSION_MAJOR 0)
set(SFPM_VERSION_MINOR 2)
set(SFPM_VERSION_PATCH 1)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
  execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE SFPM_VERSION_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
  set(SFPM_VERSION_TAG 00000000)
endif()

set(SFPM_VERSION_TAG_HEX 0x${SFPM_VERSION_TAG})
set(SFPM_VERSION "${SFPM_VERSION_MAJOR}.${SFPM_VERSION_MINOR}.${SFPM_VERSION_PATCH}" CACHE STRING "Version of sfpm")

project(${SFPM_PROJECT} VERSION ${SFPM_VERSION} LANGUAGES CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ─── GLOBAL ────────

message(STATUS "------ ${SFPM_TARGET} Configuration ------")
message(STATUS "SFPM_PROJECT                : ${SFPM_PROJECT}")
message(STATUS "SFPM_TARGET                 : ${SFPM_TARGET}")
message(STATUS "SFPM_BUILD_SHARED           : ${SFPM_BUILD_SHARED}")
message(STATUS "SFPM_ENABLE_TESTS           : ${SFPM_ENABLE_TESTS}")
message(STATUS "SFPM_VERSION                : ${SFPM_VERSION_MAJOR}.${SFPM_VERSION_MINOR}.${SFPM_VERSION_PATCH}")
message(STATUS "SFPM_VERSION_TAG_HEX        : ${SFPM_VERSION_TAG_HEX}")

message(STATUS "------ ${SFPM_TARGET} End Configuration ------")

# ┌──────────────────────────────────────────────────────────────────┐
# │                         QT5 CMAKE                                │
# └──────────────────────────────────────────────────────────────────┘

find_package(Qt5 REQUIRED COMPONENTS
  Core
  Qml
  Quick
)

# ┌──────────────────────────────────────────────────────────────────┐
# │                          SOURCES                                 │
# └──────────────────────────────────────────────────────────────────┘

file(GLOB SFPM_SRCS
  src/qqmlsortfilterproxymodel.cpp
  src/utils.cpp

  src/filters/filter.cpp
  src/filters/filtercontainer.cpp
  src/filters/rolefilter.cpp
  src/filters/valuefilter.cpp
  src/filters/indexfilter.cpp
  src/filters/regexpfilter.cpp
  src/filters/rangefilter.cpp
  src/filters/expressionfilter.cpp
  src/filters/filtercontainerfilter.cpp
  src/filters/anyoffilter.cpp
  src/filters/alloffilter.cpp
  src/filters/filtersqmltypes.cpp

  src/sorters/sorter.cpp
  src/sorters/sortercontainer.cpp
  src/sorters/rolesorter.cpp
  src/sorters/stringsorter.cpp
  src/sorters/expressionsorter.cpp
  src/sorters/sortersqmltypes.cpp
  src/sorters/filtersorter.cpp

  src/proxyroles/proxyrole.cpp
  src/proxyroles/proxyrolecontainer.cpp
  src/proxyroles/joinrole.cpp
  src/proxyroles/switchrole.cpp
  src/proxyroles/expressionrole.cpp
  src/proxyroles/proxyrolesqmltypes.cpp
  src/proxyroles/singlerole.cpp
  src/proxyroles/regexprole.cpp
  src/proxyroles/filterrole.cpp
)

file(GLOB SFPM_INCS
  include/SortFilterProxyModel/SortFilterProxyModel.hpp
  include/SortFilterProxyModel/utils.h
  include/SortFilterProxyModel/qqmlsortfilterproxymodel.h

  include/SortFilterProxyModel/filters/filter.h
  include/SortFilterProxyModel/filters/filtercontainer.h
  include/SortFilterProxyModel/filters/rolefilter.h
  include/SortFilterProxyModel/filters/valuefilter.h
  include/SortFilterProxyModel/filters/indexfilter.h
  include/SortFilterProxyModel/filters/regexpfilter.h
  include/SortFilterProxyModel/filters/rangefilter.h
  include/SortFilterProxyModel/filters/expressionfilter.h
  include/SortFilterProxyModel/filters/filtercontainerfilter.h
  include/SortFilterProxyModel/filters/anyoffilter.h
  include/SortFilterProxyModel/filters/alloffilter.h

  include/SortFilterProxyModel/sorters/sorter.h
  include/SortFilterProxyModel/sorters/sortercontainer.h
  include/SortFilterProxyModel/sorters/rolesorter.h
  include/SortFilterProxyModel/sorters/stringsorter.h
  include/SortFilterProxyModel/sorters/expressionsorter.h
  include/SortFilterProxyModel/sorters/filtersorter.h

  include/SortFilterProxyModel/proxyroles/proxyrole.h
  include/SortFilterProxyModel/proxyroles/proxyrolecontainer.h
  include/SortFilterProxyModel/proxyroles/joinrole.h
  include/SortFilterProxyModel/proxyroles/switchrole.h
  include/SortFilterProxyModel/proxyroles/expressionrole.h
  include/SortFilterProxyModel/proxyroles/singlerole.h
  include/SortFilterProxyModel/proxyroles/regexprole.h
  include/SortFilterProxyModel/proxyroles/filterrole.h
)

# ┌──────────────────────────────────────────────────────────────────┐
# │                     SORTFILTERPROXYMODEL                         │
# └──────────────────────────────────────────────────────────────────┘

foreach(_source IN ITEMS ${SFPM_SRCS})
  get_filename_component(_source_path "${_source}" PATH)
  file(RELATIVE_PATH _source_path_rel ${CMAKE_CURRENT_SOURCE_DIR}/src "${_source_path}")
  string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
  source_group("${_group_path}" FILES "${_source}")
endforeach()

foreach(_source IN ITEMS ${SFPM_INCS})
  get_filename_component(_source_path "${_source}" PATH)
  file(RELATIVE_PATH _source_path_rel ${CMAKE_CURRENT_SOURCE_DIR}/include/SortFilterProxyModel "${_source_path}")
  string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
  source_group("${_group_path}" FILES "${_source}")
endforeach()

if(${SFPM_BUILD_SHARED})
  add_library(${SFPM_TARGET} SHARED ${SFPM_INCS} ${SFPM_SRCS})
  target_compile_definitions(${SFPM_TARGET} PUBLIC -DSFPM_SHARED)
else()
  add_library(${SFPM_TARGET} STATIC ${SFPM_INCS} ${SFPM_SRCS})
  target_compile_definitions(${SFPM_TARGET} PUBLIC -DSFPM_STATIC)
endif()

target_compile_features(${SFPM_TARGET} PUBLIC cxx_std_11)
target_link_libraries(${SFPM_TARGET} PUBLIC Qt5::Core Qt5::Qml Qt5::Quick)
set_target_properties(${SFPM_TARGET} PROPERTIES
  FOLDER ${SFPM_FOLDER_PREFIX}
  AUTOMOC TRUE
  AUTORCC TRUE
)
target_include_directories(${SFPM_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${SFPM_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/SortFilterProxyModel)
target_include_directories(${SFPM_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/SortFilterProxyModel/filters)
target_include_directories(${SFPM_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/SortFilterProxyModel/proxyroles)
target_include_directories(${SFPM_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/SortFilterProxyModel/sorters)

# ┌──────────────────────────────────────────────────────────────────┐
# │                            TESTS                                 │
# └──────────────────────────────────────────────────────────────────┘

if(SFPM_ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()