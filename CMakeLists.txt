cmake_minimum_required(VERSION 3.19)

project(repose VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt6 COMPONENTS Widgets Network Xml REQUIRED)


set(PROJECT_SOURCES
        main.cpp
        src/widgets/mainwindow.h        src/widgets/mainwindow.cpp        src/widgets/mainwindow.ui
        src/widgets/requesttree.h       src/widgets/requesttree.cpp       src/widgets/requesttree.ui
        src/widgets/requesteditor.h     src/widgets/requesteditor.cpp     src/widgets/requesteditor.ui
        src/widgets/requestcontainer.h  src/widgets/requestcontainer.cpp  src/widgets/requestcontainer.ui
        src/widgets/responsecontainer.h src/widgets/responsecontainer.cpp src/widgets/responsecontainer.ui
        src/widgets/paramtable.h        src/widgets/paramtable.cpp        src/widgets/paramtable.ui
        src/models/paramtablemodel.h    src/models/paramtablemodel.cpp
        src/models/paramtablerow.h      src/models/paramtablerow.cpp
        src/models/request.h            src/models/request.cpp
        src/models/response.h           src/models/response.cpp
        src/models/rootstate.h          src/models/rootstate.cpp
        src/services/httpclient.h       src/services/httpclient.cpp
        src/utils/mimemapper.h          src/utils/mimemapper.cpp
        src/utils/humanize.h            src/utils/humanize.cpp
        src/utils/defer.h
        vendor/QtWaitingSpinner/waitingspinnerwidget.h vendor/QtWaitingSpinner/waitingspinnerwidget.cpp
        vendor/hexdump/Hexdump.hpp
)


qt_add_executable(repose
        ${PROJECT_SOURCES}
)

target_link_libraries(repose PRIVATE Qt6::Widgets Qt6::Network Qt6::Xml)
