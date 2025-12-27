# 最低版本要求
cmake_minimum_required(VERSION 3.18)
# 设置项目名称
project(InstallHello)
# 添加构建目标
add_executable(hello main.cpp)

# 安装到本地
include(GNUInstallDirs)

install(TARGETS hello)