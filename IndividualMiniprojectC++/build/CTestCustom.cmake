list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE ".*test.*")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./Testing/*")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./CMakefiles/*")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./_deps/*")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./lib/*")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./*.cmake")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./*.tcl")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./*.txt")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./*.bin")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./CMakeFiles/IndividualMiniprojectTests.dir/src/*.gcda")
# Exclude try_compile sources from coverage results
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE  "/CMakeFiles/CMakeTmp/")

# Exclude files from the Testing directories
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE".*/Testing/.*")
    
# Exclude generated python files
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE".*Python.cxx")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE".*PythonInit.cxx")

# Exclude generated cpp files
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE".*/generated_cpp/.*")

list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./IndividualMiniprojectTests")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "./Makefile")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "../external_libraries")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "../test")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "../*.cmake")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "../*.txt")
list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE "../*.pdf")
