find_package(Qt5 REQUIRED COMPONENTS
  Gui
  Quick
  QuickTest
  Test
)
find_package(Qt5 QUIET COMPONENTS QmlWorkerScript)

set(SFPM_TEST_TARGET ${SFPM_TARGET}_Tests)

set(SFPM_TEST_SRCS
  indexsorter.h
  testroles.h

  tst_sortfilterproxymodel.cpp
  indexsorter.cpp
  testroles.cpp
)

add_executable(${SFPM_TEST_TARGET} ${SFPM_TEST_SRCS})
set_target_properties(${SFPM_TEST_TARGET} PROPERTIES AUTOMOC TRUE AUTORCC TRUE)
target_include_directories(${SFPM_TEST_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${SFPM_TEST_TARGET} PRIVATE
  Qt5::Core
  Qt5::Gui
  Qt5::Qml
  Qt5::QuickTest
  Qt5::Test
  Qt5::Quick
  ${SFPM_TARGET}
)
set_target_properties(${SFPM_TEST_TARGET} PROPERTIES FOLDER ${SFPM_FOLDER_PREFIX}/Tests)

get_target_property(QT_TARGET_TYPE Qt5::Core TYPE)
if(${QT_TARGET_TYPE} STREQUAL "STATIC_LIBRARY")
  include(../cmake/FetchQtStaticCMake.cmake)
  qt_generate_qml_plugin_import(${SFPM_TEST_TARGET}
    QML_SRC ${CMAKE_CURRENT_SOURCE_DIR}
    VERBOSE
    )
  #qt_generate_plugin_import(${SFPM_TEST_TARGET} VERBOSE)
endif()

if(TARGET Qt5::QmlWorkerScript)
  target_link_libraries(${SFPM_TEST_TARGET} PUBLIC Qt5::QmlWorkerScript)
endif()

file(GLOB SFPM_TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/tst_*.qml")

foreach(SFPM_TEST_FILE ${SFPM_TEST_FILES})
  get_filename_component(SFPM_TEST_FILE_NAME ${SFPM_TEST_FILE} NAME_WE)
  add_test(NAME ${SFPM_TEST_TARGET}_${SFPM_TEST_FILE_NAME} COMMAND "$<TARGET_FILE:${SFPM_TEST_TARGET}>" -input "${SFPM_TEST_FILE}")
endforeach(SFPM_TEST_FILE)