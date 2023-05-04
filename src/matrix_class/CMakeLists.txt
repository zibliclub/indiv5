add_library(matrix_class "")

target_sources(matrix_class
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/matrix_class.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/matrix_class.hpp
  )
target_include_directories(matrix_class
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )