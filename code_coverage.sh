# create code coverage info
mkdir -p code_coverage
cd code_coverage/
shopt -s globstar
for x in ../src/**/*.cpp; do
    gcov -b -o ../bin-int/Debug-linux-x86_64/bahamutGUI ${x}
done

#-------------------------------------------
# OLD CODE COVERAGE STUFF BELOW
#-------------------------------------------

# make sure that the tests have been run
#./bin/Debug-linux-x86_64/tests/tests

#mkdir -p code_coverage
#cd code_coverage/

#gcov -o ../bin-int/Debug-linux-x86_64/tests ../tests/*.cpp

#lcov --directory ../bin-int/Debug-linux-x86_64/tests --directory ../bin-int/Debug-linux-x86_64/bahamutGUI --output-file main_coverage.info -c

#genhtml main_coverage.info --output-directory out