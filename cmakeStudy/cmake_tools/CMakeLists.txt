# 设置最低版本要求
cmake_minimum_required(VERSION 3.18)
# 设置项目名称
project(TestCMakeTools)
# 添加项目目标
add_executable(main Main.cpp)
# 集成单元测试
include(CTest)
add_test(
    NAME testAdd
    COMMAND main   
)
# 本地安装
include(GNUInstallDirs)
install(TARGETS main)
# 打包
include(CPack)