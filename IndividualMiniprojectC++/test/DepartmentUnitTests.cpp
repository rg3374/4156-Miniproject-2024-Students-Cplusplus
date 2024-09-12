/**
 * Copyright 2024 <Columbia University>
 */

#include <gtest/gtest.h>
#include "Department.h" 
#include "Course.h" 

class DepartmentUnitTests : public ::testing::Test {
protected:
    static Department* testDepartment;

    static void SetUpTestSuite() {
        auto math1004 = std::make_shared<Course>(400, "Adam Cannon", "417 IAB", "11:40-12:55");
        math1004->setEnrolledStudentCount(249);

        auto math2004 = std::make_shared<Course>(600, "Brian Borowski", "309 HAV", "10:10-11:25");
        math2004->setEnrolledStudentCount(102);

        std::map<std::string, std::shared_ptr<Course>> courses;
        courses["1004"] = math1004;
        courses["2004"] = math2004;

        testDepartment = new Department("MATH", courses, "Luca Carloni", 205);

    }

    static void TearDownTestSuite() {
        delete testDepartment;
    }
};

Department* DepartmentUnitTests::testDepartment = nullptr;

TEST_F(DepartmentUnitTests, ToStringTest) {
    std::string expectedResult = "MATH 1004: \nInstructor: Adam Cannon; Location: 417 IAB; Time: 11:40-12:55\nMATH 2004: \nInstructor: Brian Borowski; Location: 309 HAV; Time: 10:10-11:25\n";
    ASSERT_EQ(expectedResult, testDepartment->display());
}

TEST_F(DepartmentUnitTests, DefaultDepartmentTest) {
    Department* newDepartment = new Department();
    EXPECT_EQ(0, newDepartment->getNumberOfMajors());
}

TEST_F(DepartmentUnitTests, GetNumberOfMajorsTest) {
    EXPECT_EQ(205, testDepartment->getNumberOfMajors());
}

TEST_F(DepartmentUnitTests, GetDepartmentChairTest) {
    EXPECT_EQ("Luca Carloni", testDepartment->getDepartmentChair());
}

TEST_F(DepartmentUnitTests, AddPersonToMajorTest) {
    testDepartment->addPersonToMajor();
    EXPECT_EQ(206, testDepartment->getNumberOfMajors());
}

TEST_F(DepartmentUnitTests, DropPersonFromMajorTest) {
    testDepartment->dropPersonFromMajor();
    EXPECT_EQ(204, testDepartment->getNumberOfMajors());
}

TEST_F(DepartmentUnitTests, AddCourseTest) {
        auto testCourse = new Course(250, "Griffin Newbold", "417 IAB", "11:40-12:55");
        testDepartment->createCourse("3000", "Griffin Newbold", "417 IAB", "11:40-12:55", 250);

        std::string expectedResult = "MATH 1004: \nInstructor: Adam Cannon; Location: 417 IAB; Time: 11:40-12:55\nMATH 2004: \nInstructor: Brian Borowski; Location: 309 HAV; Time: 10:10-11:25\nMATH 3000: \nInstructor: Griffin Newbold; Location: 417 IAB; Time: 11:40-12:55\n";
        ASSERT_EQ(expectedResult, testDepartment->display());

        delete testCourse;
}
