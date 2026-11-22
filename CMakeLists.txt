cmake_minimum_required(VERSION 3.16)
project(bank LANGUAGES CXX)

# Bắt buộc toàn bộ project build trên C++20, không cho rơi về chuẩn thấp hơn.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Tự động gom hết .cpp trong src/ và .h trong include/ -> không cần liệt kê
# tay từng file, thêm file mới chỉ cần chạy lại cmake.
file(GLOB_RECURSE BANK_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE BANK_HEADERS CONFIGURE_DEPENDS include/*.h)

add_executable(bank_app ${BANK_SOURCES} ${BANK_HEADERS})

# Tự động lấy toàn bộ thư mục con bên trong include/ (account, card, common, ...)
# để thêm vào include path -> trong code chỉ cần #include "Money.h" thay vì
# #include "common/Money.h". Thêm thư mục con mới cũng không cần sửa tay ở đây.
file(GLOB BANK_INCLUDE_SUBDIRS LIST_DIRECTORIES true ${CMAKE_SOURCE_DIR}/include/*)
set(BANK_INCLUDE_DIRS include)
foreach(item ${BANK_INCLUDE_SUBDIRS})
    if(IS_DIRECTORY ${item})
        list(APPEND BANK_INCLUDE_DIRS ${item})
    endif()
endforeach()

target_include_directories(bank_app PRIVATE ${BANK_INCLUDE_DIRS})

# Ép rõ ràng từng target phải dùng tính năng C++20 (không chỉ dựa vào biến global ở trên).
target_compile_features(bank_app PRIVATE cxx_std_20)