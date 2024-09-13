Commands run for:

1. Building executable: 
   In build:
   > cmake .. 
   > make 

2. Style checking
   In build:
   > make cpplint 

3. Static analysis 
   > cd src
   > cppcheck . --check-level=exhaustive --force --checkers-report=cppcheck.log

    cppcheck.log checked in.

4. Running Test suite
   > (make clean) - optional - only if changes made
   > make 
   > make test

5. Code Coverage
   In build:
   > cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS_DEBUG="-g -fprofile-arcs -ftest-coverage" \\n    -DCMAKE_C_FLAGS_DEBUG="-g -fprofile-arcs -ftest-coverage"
   > make -j
   > ctest -T Test -T Coverage

   Output:
   	Covered LOC:         435
	Not covered LOC:     363
	Total LOC:           798
	Percentage Coverage: 54.51%

5. Documentation
   To create Doxyfile
   > doxygen -g
   Edit Doxyfile
   > doxygen
   > cd latex; make

   The refman.pdf file generated in the latex directory is checked in.
