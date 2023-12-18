#include <ros/ros.h>
#include <gtest/gtest.h>
#include "../Strategy/Test/Test.h"

Test *test;
Eigen::Matrix<float, 4, 4> transform_matrix_test;

TEST(TestSuite, testCase1) {
  // ASSERT_*;
  ASSERT_EQ(transform_matrix_test, test->StartStrategy()); 
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "test_node");
  ros::NodeHandle nh;
  bool pTerminate = false;
  test = new Test(&pTerminate);

  transform_matrix_test << 1, -0, 0, 0,
                           0, 1, -0, 0,
                           0, 0, 1, 0,
                           0, 0, 0, 1;

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}