cmake_minimum_required(VERSION 3.21.1)

project(DemoBudgetTrackerApp LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick Sql)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

include_directories(${CMAKE_SOURCE_DIR}/src)

qt_add_executable(DemoBudgetTrackerApp src/main.cpp
    src/tablemodel.cpp
    src/tablemodel.h
    src/database.h
    src/database.cpp
    src/common.h
)

qt_add_resources(DemoBudgetTrackerApp "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

target_link_libraries(DemoBudgetTrackerApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Sql
)

qt6_add_qml_module(${CMAKE_PROJECT_NAME}
    URI "Main"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    NO_PLUGIN
    QML_FILES main.qml
              ExpensesTable.qml
              ExpenseControls.qml
)

set(QT_QML_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/qml")

include(GNUInstallDirs)
install(TARGETS DemoBudgetTrackerApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# make IDEs aware of the QML import path
set(QML_IMPORT_PATH ${PROJECT_BINARY_DIR}/qml CACHE PATH
    "Path to the custom QML components defined by the project")

set_target_properties(${PROJECT_NAME} PROPERTIES
                                          AUTOMOC TRUE
                                          CMAKE_CXX_STANDARD 20
                                          CMAKE_CXX_STANDARD_REQUIRED ON)
