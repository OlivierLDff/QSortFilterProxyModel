CMAKE_MINIMUM_REQUIRED( VERSION 3.1.0 )

SET( SFPM_TARGET "QSortFilterProxyModel" CACHE STRING "Target Name" )
SET( SFPM_PROJECT "QSortFilterProxyModel" CACHE STRING "Project Name")
SET( SFPM_BUILD_SHARED OFF CACHE BOOL "Build as a shared library" )
SET( SFPM_USE_NAMESPACE ON CACHE BOOL "Should the library be compiled with a namespace. Default: ON" )
SET( SFPM_NAMESPACE "Sfpm" CACHE STRING "Namespace of the library is SFPM_USE_NAMESPACE is ON. Default : Sfpm" )
SET( SFPM_NAMESPACE_IID "qsm.SortFilterProxyModel" CACHE STRING "" )

SET(SFPM_VERSION_MAJOR 0)
SET(SFPM_VERSION_MINOR 2)
SET(SFPM_VERSION_PATCH 0)
IF( EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git" )
    EXECUTE_PROCESS(
        COMMAND git describe --always
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE SFPM_VERSION_TAG
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
ELSE()
    SET( SFPM_VERSION_TAG 00000000 )
ENDIF()
SET( SFPM_VERSION_TAG_HEX 0x${SFPM_VERSION_TAG})
SET( SFPM_VERSION "${SFPM_VERSION_MAJOR}.${SFPM_VERSION_MINOR}.${SFPM_VERSION_PATCH}" CACHE STRING "Version of sfpm" )

PROJECT( ${SFPM_PROJECT} )
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# ─── GLOBAL ────────
MESSAGE( "------ ${SFPM_TARGET} Configuration ------" )
MESSAGE( STATUS "SFPM_PROJECT                : ${SFPM_PROJECT}" )
MESSAGE( STATUS "SFPM_TARGET                 : ${SFPM_TARGET}" )
MESSAGE( STATUS "SFPM_BUILD_SHARED           : ${SFPM_BUILD_SHARED}" )
MESSAGE( STATUS "SFPM_VERSION                : ${SFPM_VERSION_MAJOR}.${SFPM_VERSION_MINOR}.${SFPM_VERSION_PATCH}" )
MESSAGE( STATUS "SFPM_VERSION_TAG_HEX        : ${SFPM_VERSION_TAG_HEX}" )

MESSAGE( "------ ${SFPM_TARGET} End Configuration ------" )

FIND_PACKAGE(Qt5Core CONFIG REQUIRED CMAKE_FIND_ROOT_PATH_BOTH)
FIND_PACKAGE(Qt5Quick CONFIG REQUIRED CMAKE_FIND_ROOT_PATH_BOTH)

SET( CMAKE_AUTOMOC ON )
SET( CMAKE_AUTORCC ON )
set (CMAKE_CXX_STANDARD 11) 

FILE(GLOB SFPM_SRCS     
    ${CMAKE_CURRENT_SOURCE_DIR}/src/QQmlSortFilterProxyModel
    ${CMAKE_CURRENT_SOURCE_DIR}/src/qqmlsortfilterproxymodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/qqmlsortfilterproxymodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/filter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/filter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/filtercontainer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/filtercontainer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/rolefilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/rolefilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/valuefilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/valuefilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/indexfilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/indexfilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/regexpfilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/regexpfilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/rangefilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/rangefilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/expressionfilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/expressionfilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/filtercontainerfilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/filtercontainerfilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/anyoffilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/anyoffilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/alloffilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/alloffilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/filters/filtersqmltypes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/sorter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/sorter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/sortercontainer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/sortercontainer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/rolesorter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/rolesorter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/stringsorter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/stringsorter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/expressionsorter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/expressionsorter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/sortersqmltypes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/proxyrole.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/proxyrole.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/proxyrolecontainer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/proxyrolecontainer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/joinrole.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/joinrole.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/switchrole.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/switchrole.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/expressionrole.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/expressionrole.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/proxyrolesqmltypes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/singlerole.cpp   
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/singlerole.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/regexprole.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/regexprole.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/filtersorter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sorters/filtersorter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/filterrole.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/proxyroles/filterrole.h
    )

foreach(_source IN ITEMS ${SFPM_SRCS})
    get_filename_component(_source_path "${_source}" PATH)
    file(RELATIVE_PATH _source_path_rel ${CMAKE_CURRENT_SOURCE_DIR}/src "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

IF(${SFPM_BUILD_SHARED})
    ADD_LIBRARY( ${SFPM_TARGET} STATIC 
        ${SFPM_SRCS}
    )
    IF( MSVC )
    GENERATE_EXPORT_HEADER( ${SFPM_TARGET}
        BASE_NAME ${SFPM_TARGET}
        EXPORT_MACRO_NAME ${SFPM_TARGET}_EXPORT
        EXPORT_FILE_NAME ${SFPM_TARGET}_Export.h
        STATIC_DEFINE ${SFPM_TARGET}_BUILT_AS_STATIC
    )
    ENDIF( MSVC )
    TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PUBLIC -DSFPM_SHARED )
ELSE(${SFPM_BUILD_SHARED})
    ADD_LIBRARY( ${SFPM_TARGET} STATIC 
        ${SFPM_SRCS}
    )
    TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PUBLIC -DSFPM_STATIC )
ENDIF(${SFPM_BUILD_SHARED})

qt5_use_modules( ${SFPM_TARGET} Core Quick )
TARGET_INCLUDE_DIRECTORIES( ${SFPM_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src )
TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PRIVATE -DSFPM_VERSION_MAJOR=${SFPM_VERSION_MAJOR} )
TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PRIVATE -DSFPM_VERSION_MINOR=${SFPM_VERSION_MINOR} )
TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PRIVATE -DSFPM_VERSION_PATCH=${SFPM_VERSION_PATCH} )
TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PRIVATE -DSFPM_VERSION_TAG=${SFPM_VERSION_TAG} )
TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PRIVATE -DSFPM_VERSION_TAG_HEX=${SFPM_VERSION_TAG_HEX} )
TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PRIVATE -DSFPM_NAMESPACE_IID="${SFPM_NAMESPACE_IID}" )
IF(SFPM_USE_NAMESPACE)
TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PUBLIC -DSFPM_USE_NAMESPACE )
TARGET_COMPILE_DEFINITIONS( ${SFPM_TARGET} PUBLIC -DSFPM_NAMESPACE=${SFPM_NAMESPACE} )
ENDIF(SFPM_USE_NAMESPACE)
