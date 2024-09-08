Commands run for:

1. Building executable: 
    cmake .. 
    make 

2. Style checking
   make cpplint 

3. Static analysis 
   cd src
   cppcheck . --check-level=exhaustive --force --checkers-report=cppcheck.log

   2 errors were found:
       a. ../external_libraries/Crow-1.2.0-Darwin/include/crow/routing.h:1798:17: error: Rethrowing current exception with 'throw;', it seems there is no current exception to rethrow. If there is no current exception this calls std::terminate(). More: https://isocpp.org/wiki/faq/exceptions#throw-without-an-object [rethrowNoCurrentException]
                throw;
                ^
       b. ../external_libraries/Crow-1.2.0-Darwin/include/crow/logging.h:78:25: error: Uninitialized variable: &my_tm [uninitvar]
            localtime_s(&my_tm, &t);
    But these are both in external Crow library. So not fixed.

    Message in cppcheck.log:
    "Critical errors
     ---------------
     No critical errors, all files were checked."
    cppcheck.log checked in.

4. Running Test suite
   (make clean) - optional - if changes madde
   make 
   make test
