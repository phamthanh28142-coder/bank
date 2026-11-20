# Yêu cầu CMake phiên bản 3.20 trở lên
cmake_minimum_required(VERSION 3.20)

# Khai báo tên dự án và ngôn ngữ C++
project(Banking LANGUAGES CXX)

# Sử dụng chuẩn C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Tìm mọi file .cpp trong src/ và các thư mục con
# CONFIGURE_DEPENDS giúp CMake cập nhật khi thêm hoặc xóa file .cpp
file(GLOB_RECURSE BANKING_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Tìm mọi file .h và .hpp để hiển thị trong project của IDE
# Các header không cần biên dịch riêng
file(GLOB_RECURSE BANKING_HEADERS
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

# Báo lỗi nếu chưa có file .cpp nào để tạo chương trình
if(NOT BANKING_SOURCES)
    message(FATAL_ERROR "Khong tim thay file .cpp trong thu muc src/")
endif()

# Tạo chương trình thực thi tên banking từ các file nguồn và header
add_executable(banking
    ${BANKING_SOURCES}
    ${BANKING_HEADERS}
)

# Cho phép compiler tìm header trong include/ và các thư mục con
target_include_directories(banking PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/common"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/customer"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/account"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/event"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/card"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/repository"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/transaction"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/factory"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/storage"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/presentation"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/service"
)

