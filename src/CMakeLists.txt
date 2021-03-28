# 打印信息
message(STATUS "src This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "src This is SOURCE dir " ${PROJECT_SOURCE_DIR})

# 定义工程根目录; CMAKE_SOURCE_DIR为内建变量，表示工程根目录的CMakeLists.txt文件路径
SET(ROOT_DIR ${CMAKE_SOURCE_DIR})

# 指定头文件搜索路径
INCLUDE_DIRECTORIES(${ROOT_DIR}/lib/stk/4.6.1/include)

# 指定引用的外部库的搜索路径
LINK_DIRECTORIES(${ROOT_DIR}/lib/stk/4.6.1/lib)

# 指定可执行文件存放目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 构建可执行程序
ADD_EXECUTABLE(Chordmata main.cpp)
TARGET_LINK_LIBRARIES(Chordmata libstk.a)