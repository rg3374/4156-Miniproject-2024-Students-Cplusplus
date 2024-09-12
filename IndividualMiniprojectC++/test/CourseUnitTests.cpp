/**
 * Copyright 2024 <Columbia University>
 */

#include <gtest/gtest.h>
#include "Course.h" 

class CourseUnitTests : public ::testing::Test {
protected:
    static Course* testCourse;

    static void SetUpTestSuite() {
        testCourse = new Course(250, "Griffin Newbold", "417 IAB", "11:40-12:55");
    }

    static void TearDownTestSuite() {
        delete testCourse;
    }
};

Course* CourseUnitTests::testCourse = nullptr;

TEST_F(CourseUnitTests, ToStringTest) {
    std::string expectedResult = "\nInstructor: Griffin Newbold; Location: 417 IAB; Time: 11:40-12:55";
    ASSERT_EQ(expectedResult, testCourse->display());
}

TEST_F(CourseUnitTests, DefaultEnrollStudentTest) {
    EXPECT_EQ(0, testCourse->getEnrolledStudentCount());
}

TEST_F(CourseUnitTests, EnrollStudentTest) {
    testCourse->enrollStudent();
    testCourse->enrollStudent();
    EXPECT_EQ(2, testCourse->getEnrolledStudentCount());
}

TEST_F(CourseUnitTests, DropStudentTest) {
    testCourse->enrollStudent();
    testCourse->enrollStudent();
    testCourse->dropStudent();
    EXPECT_EQ(1, testCourse->getEnrolledStudentCount());
}

TEST_F(CourseUnitTests, GetCourseLocationTest) {
    EXPECT_EQ("417 IAB", testCourse->getCourseLocation());
}

TEST_F(CourseUnitTests, GetInstructorNameTest) {
    EXPECT_EQ("Griffin Newbold", testCourse->getInstructorName());
}

TEST_F(CourseUnitTests, GetCourseTimeSlotTest) {
    EXPECT_EQ("11:40-12:55", testCourse->getCourseTimeSlot());
}

TEST_F(CourseUnitTests, SetEnrolledStudentCountTest) {
    testCourse->setEnrolledStudentCount(23);
    EXPECT_EQ(23, testCourse->getEnrolledStudentCount());
}

TEST_F(CourseUnitTests, EnrolledStudentUpperLimitTest) {
    testCourse->setEnrolledStudentCount(250);
    EXPECT_FALSE(testCourse->enrollStudent());
}

TEST_F(CourseUnitTests, EnrolledStudentLowerLimitTest) {
    testCourse->setEnrolledStudentCount(0);
    EXPECT_FALSE(testCourse->dropStudent());
}

TEST_F(CourseUnitTests, ReassignLocationTest) {
    testCourse->reassignLocation("309 HAV");
    EXPECT_EQ("309 HAV", testCourse->getCourseLocation());
}

TEST_F(CourseUnitTests, ReassignTimeTest) {
    testCourse->reassignTime("10:10-11:25");
    EXPECT_EQ("10:10-11:25", testCourse->getCourseTimeSlot());
}

TEST_F(CourseUnitTests, ReassignInstructorTest) {
    testCourse->reassignInstructor("Brian Borowski");
    EXPECT_EQ("Brian Borowski", testCourse->getInstructorName());
}

TEST_F(CourseUnitTests, IsCourseFullTest) {
    testCourse->setEnrolledStudentCount(23);
    EXPECT_EQ(false, testCourse->isCourseFull());
}
