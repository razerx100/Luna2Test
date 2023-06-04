cmake_minimum_required(VERSION 3.24)

project(Luna2Test
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

include(FetchContent)

set(GOOGLE_TEST_COMMIT_ID 06f44bc951046150f1348598854b211afdcf37fc CACHE STRING "Supply the latest commit ID from the GitHub repository.")

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/${GOOGLE_TEST_COMMIT_ID}.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE SRC includes/*.hpp src/*.cpp)

add_executable(${PROJECT_NAME}
    ${SRC}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    GTest::gtest_main
)

set(LIBRARY_TYPE STATIC)

FetchContent_Declare(
    Luna2
    https://github.com/razerx100/Luna2.git
    GIT_TAG ${BRANCH}
)

FetchContent_GetProperties(Luna2)

message(STATUS "Fetching Luna2 from the branch ${BRANCH}....")

set(LUNA2_DIR "../Library")

if(NOT Luna2_POPULATED)
    FetchContent_Populate(Luna2
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${LUNA2_DIR}
    )
    add_subdirectory(${luna2_SOURCE_DIR} ${luna2_BINARY_DIR})
else()
    FetchContent_MakeAvailable(Luna2)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    ${LUNA2_DIR}/includes/ ${LUNA2_DIR}/includes/Exceptions/ ${LUNA2_DIR}/exports/ includes/
)

target_compile_definitions(${PROJECT_NAME} PRIVATE "$<$<CONFIG:DEBUG>:_DEBUG>" "$<$<CONFIG:RELEASE>:NDEBUG>")

target_link_libraries(${PROJECT_NAME} PUBLIC
    Luna2
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /fp:fast /MP /EHa /Ot /W4 /Gy)
endif()

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})