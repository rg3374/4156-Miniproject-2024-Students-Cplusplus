Commands run for:

1. Building executable: 
    cmake .. 
    make 

2. Style checking
   make cpplint 

3. Static analysis 
   cd src
   cppcheck . --check-level=exhaustive --force --checkers-report=cppcheck.log

    cppcheck.log checked in.

4. Running Test suite
   (make clean) - optional - if changes madde
   make 
   make test

5. Documentation
   doxygen -g - to create Doxyfile
   Edit Doxyfile
   doxygen
   cd latex; make

   The refman.pdf file generated in the latex directory is checked in.
