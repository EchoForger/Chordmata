# 打印信息
message(STATUS "src This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "src This is SOURCE dir " ${PROJECT_SOURCE_DIR})

# 定义工程根目录; CMAKE_SOURCE_DIR为内建变量，表示工程根目录的CMakeLists.txt文件路径
set(ROOT_DIR ${CMAKE_SOURCE_DIR})

# 指定头文件搜索路径
include_directories(${ROOT_DIR}/lib/stk/4.6.1/include)

# 指定引用的外部库的搜索路径
link_directories(${ROOT_DIR}/lib/stk/4.6.1/lib)

# 指定可执行文件存放目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

find_package(Qt5 COMPONENTS Widgets LinguistTools Multimedia REQUIRED)

set(TS_FILES Chordmata_en_US.ts)

if(ANDROID)
  add_library(Chordmata SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    midievent.cpp
    midievent.h
    track.cpp
    track.h
    miditrack.cpp
    miditrack.h
    clip.cpp
    clip.h
    midiclip.cpp
    midiclip.h
    project.cpp
    project.h
    mixer.cpp
    mixer.h
    chord.cpp
    chord.h
    pianowork.cpp
    pianowork.h
    ${TS_FILES}
  )
else()
  add_executable(Chordmata
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    midievent.cpp
    midievent.h
    track.cpp
    track.h
    miditrack.cpp
    miditrack.h
    clip.cpp
    clip.h
    midiclip.cpp
    midiclip.h
    project.cpp
    project.h
    mixer.cpp
    mixer.h
    chord.cpp
    chord.h
    pianowork.cpp
    pianowork.h
    ${TS_FILES}
  )
endif()

target_link_libraries(Chordmata PRIVATE Qt5::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

# 构建可执行程序
target_link_libraries(Chordmata libstk.a)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_link_libraries(Chordmata PRIVATE Qt5::Multimedia)
