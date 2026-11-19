cmake_minimum_required(VERSION 3.10)
project(BankSystem)

# Bắt buộc toàn bộ project dùng chuẩn C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Bắt lỗi ngay nếu compiler không hỗ trợ C++20
set(CMAKE_CXX_EXTENSIONS OFF)         # Dùng đúng chuẩn C++20 thuần, không dùng extension riêng của GCC/Clang

# Cho compiler biết tìm file .h trong các folder include/ và từng zone
include_directories(
    include
    include/zone_a
    include/zone_b
    include/zone_c
)

# Tự động gom TẤT CẢ file .cpp trong mọi folder con của src/ (zone_a, zone_b, zone_c, ...)
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Tạo file chạy tên "bank" từ toàn bộ file .cpp tìm được ở trên
add_executable(bank ${SOURCES})

# (Tuỳ chọn) Bật thêm cảnh báo lỗi để code sạch hơn, có thể xoá dòng dưới nếu không cần
target_compile_options(bank PRIVATE -Wall -Wextra)
