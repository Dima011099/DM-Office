cmake_minimum_required(VERSION 3.10)
project(DM-Office)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)

add_executable(dmoffice ${SOURCES} ${HEADERS})

file(GLOB_RECURSE ALL_HEADERS "src/*.h")
set(INCLUDE_DIRS "")
foreach(header_file ${ALL_HEADERS})
    get_filename_component(header_dir ${header_file} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${header_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

target_include_directories(dmoffice PRIVATE ${INCLUDE_DIRS})
target_link_libraries(dmoffice PkgConfig::GTKMM)