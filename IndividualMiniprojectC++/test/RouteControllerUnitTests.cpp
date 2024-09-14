/**
 * Copyright 2024 <Columbia University>
 */

#include <gtest/gtest.h>
#include "RouteController.h" 
#include "MyApp.h"

class RouteControllerUnitTests : public ::testing::Test {
protected:
    static RouteController testRouteController;

    static void SetUpTestSuite() {
        MyApp::run("run");

        crow::SimpleApp app;
        app.signal_clear();
  
        testRouteController.initRoutes(app);
        testRouteController.setDatabase(MyApp::getDatabase());
    }

    static void TearDownTestSuite() {
    }
};

RouteController RouteControllerUnitTests::testRouteController;

TEST_F(RouteControllerUnitTests, ToStringTest) {
    std::string expectedResult = "Welcome, in order to make an API call direct your browser or Postman to an endpoint \n\n This can be done using the following format: \n\n http://127.0.0.1:8080/endpoint?arg=value";
    crow::response res;
    testRouteController.index(res);
    ASSERT_EQ(expectedResult, res.body);
}

TEST_F(RouteControllerUnitTests, RetrieveDepartmentTest) {
    std::string url_ = "http://127.0.0.1:8080/endpoint?deptCode=CHEM";
    std::vector<char*> key_value_pairs_;
    key_value_pairs_.push_back((char*)"deptCode=CHEM");
    crow::query_string qs(url_, true);

    crow::request req;
    req.url_params = qs;
    crow::response res;

    testRouteController.retrieveDepartment(req, res);
    EXPECT_EQ(200, res.code);
}

TEST_F(RouteControllerUnitTests, IsCourseFullTest) {
    std::string url_ = "http://127.0.0.1:8080/endpoint?deptCode=CHEM&courseCode=1403";
    std::vector<char*> key_value_pairs_;
    key_value_pairs_.push_back((char*)"deptCode=CHEM&courseCode=1403");
    crow::query_string qs(url_, true);

    crow::request req;
    req.url_params = qs;
    crow::response res;

    testRouteController.isCourseFull(req, res);
    EXPECT_EQ("false", res.body);
}

TEST_F(RouteControllerUnitTests, GetMajorCountFromDeptTest) {
    std::string expectedResult = "Welcome, in order to make an API call direct your browser or Postman to an endpoint \n\n This can be done using the following format: \n\n http://127.0.0.1:8080/endpoint?arg=value";
    std::string url_ = "http://127.0.0.1:8080/endpoint?deptCode=CHEM&numberOfMajors=250";
    std::vector<char*> key_value_pairs_;
    key_value_pairs_.push_back((char*)"deptCode=CHEM");
    crow::query_string qs(url_, true);

    crow::request req;
    req.url_params = qs;
    crow::response res;

    testRouteController.getMajorCountFromDept(req, res);
    EXPECT_EQ("There are: 250 majors in the department", res.body);
}

