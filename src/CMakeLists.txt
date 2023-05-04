add_executable(indiv5_test_prog main.cpp)
  
add_subdirectory(indiv_func)
add_subdirectory(matrix_class)
add_subdirectory(supp_func)

target_link_libraries(indiv5_test_prog
  PRIVATE
    indiv_func
    matrix_class
    supp_func
  )