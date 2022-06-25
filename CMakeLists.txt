cmake_minimum_required(VERSION 3.22)
project(McaTools)

set(CMAKE_CXX_STANDARD 11)

# 第三方库目录
add_subdirectory(external)

# 项目源码
add_subdirectory(src)

# 库链接
target_link_libraries(McaTools
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        )

