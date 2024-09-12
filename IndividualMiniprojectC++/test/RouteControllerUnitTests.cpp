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
