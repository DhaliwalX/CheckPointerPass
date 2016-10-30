cmake_minimum_required(VERSION 3.1)
# A convenience variable:
set(LLVM_ROOT "" CACHE PATH "Root of LLVM install.")
# A bit of a sanity check:
if( NOT EXISTS ${LLVM_ROOT}/include/llvm)
	message(FATAL_ERROR "LLVM_ROOT (${LLVM_ROOT}) is not a valid LLVM install. Please specify LLVM_ROOT (build directory where LLVM lives).")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${LLVM_ROOT}/lib/cmake/llvm")
include(LLVMConfig)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_ROOT}/lib/cmake/llvm")
message(STATUS "Looking for LLVM cmake modules: ${LLVM_ROOT}/lib/cmake/llvm")
include_directories("${LLVM_SRC}/include")
include_directories("${LLVM_ROOT}/include")
link_directories("${LLVM_ROOT}/lib")

add_subdirectory(checkpointer)  # Use your pass name here.
