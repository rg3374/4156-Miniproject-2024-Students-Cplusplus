Commands run for:

1. Building executable: 
   > cd build
   > cmake .. 
   > make 

2. Style checking
   In build:
   > make cpplint 

   Errors fixed.
   Final Output:
        rumighosh@unknown403f8cae694a build % make cpplint
        [100%] Running cpplint for Google C++ Style Guide compliance
        Done processing src/Course.cpp
        Done processing src/Department.cpp
        Done processing src/Globals.cpp
        Done processing src/MyApp.cpp
        Done processing src/MyFileDatabase.cpp
        Done processing src/RouteController.cpp
        Done processing src/main.cpp
        Done processing test/CourseUnitTests.cpp
        Done processing test/sample.cpp
        [100%] Built target cpplint
        rumighosh@unknown403f8cae694a build % 

3. Static analysis 
   > cd src
   > cppcheck . --check-level=exhaustive --force --checkers-report=cppcheck.log

    The generated log file, cppcheck.log is checked in.
    Errors in Crow external library are ignored.
    Final message in cppcheck.log:
    "Critical errors
     ---------------
     No critical errors, all files were checked."

4. Running Test suite
   > cd build
   > (make clean) - optional - only if changes made
   > make 
   > make test

5. Code Coverage
   > cd build
   > cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS_DEBUG="-g -fprofile-arcs -ftest-coverage" \\n    -DCMAKE_C_FLAGS_DEBUG="-g -fprofile-arcs -ftest-coverage"
   > make -j
   > ctest -T Test -T Coverage

   CTestCustom.cmake has been added to exclude directories with external code.
   Final Output:
        Covered LOC:         465
	Not covered LOC:     333
	Total LOC:           798
	Percentage Coverage: 58.27% 

5. Documentation
   > cd src
   To create Doxyfile :
   > doxygen -g
   Edit Doxyfile :
   > doxygen
   > cd latex; make

   The refman.pdf file generated in the latex directory is checked in.
