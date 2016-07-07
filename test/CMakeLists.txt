project(simmopp_test)

set(TEST_FILES vector_test.cpp point_test.cpp regex_iterator_test.cpp angle_test.cpp bitmatrix_test.cpp)
add_executable(simmopp_test ${TEST_FILES})
target_link_libraries(simmopp_test gtest gtest_main)