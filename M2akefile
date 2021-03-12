TEST_FILES_SRC=temp_lib_ut.cpp iostream_pp_ut.cpp
FLAGS=-Wall -Wextra -Wpedantic -O3
STANDARD=c++20
PROJECT_ROOT_DIR=C:/Users/antek/Desktop/informatyka/GITHUB_Projekty/library-plus-plus
.PHONY googletest
googletest :
	md googletest
	cd googletest
	git clone https://github.com/google/googletest.git
	cd googletest
	#
	GMOCK=googletest/googlemock
	GTEST=googletest/googletest
stdc++pp.lib : iostream_pp.o temp_lib.o
	mingw32-gcc-ar -rcs stdc++pp.lib iostream_pp.o temp_lib.o
lib++ut.exe : maintest.o $(TEST_FILES) $(GTEST_FILES) $(GMOCK_FILES)
	g++ $< $(TEST_FILES) -o $@ -lstdc++pp  $(FLAGS) -std=$(STANDARD)
iostream_pp.o : iostream_pp.hpp
	g++ -c $< $(FLAGS) -std=$(STANDARD) -I.
temp_lib.o : temp_lib.hpp
	g++ -c $< $(FLAGS) -std=$(STANDARD) -I.
maintest.o : maintest.cpp
	g++ -c $< $(FLAGS) -std=$(STANDARD) -I.
temp_lib_ut.o : temp_lib_ut.cpp

# gtest
git clone https://github.com/google/googletest.git
md googletest.build
cd googletest.build
# Variables
GT=gtest
# GTest sources
GTESTSRC_FILES_1=$(GT)-all.cc $(GT)-death-test.cc $(GT)-matchers.cc #Only header: $(GT)-message.h
GTESTSRC_FILES_2=$(GT)-printers.cc $(GT)-test-part.cc #Only header: $(GT)-param-test.h, $(GT)-spi.cc 
GTESTSRC_FILES_3=$(GT)-typed-test.cc $(GT)-filepath.cc $(GT)-internal-inl.h $(GT)-port.cc
GTESTSRC_FILES_4=$(GT).cc $(GT)_main.cc
GTESTSRC_FILES=$(GTESTSRC_FILES_1) $(GTESTSRC_FILES_2) $(GTESTSRC_FILES_3) $(GTESTSRC_FILES_4)
# GTest header files
GTESTINC_FILES_1=$(GT)-death-test.h $(GT)-matchers.h $(GT)-message.h $(GT)-param-test.h
GTESTINC_FILES_2=$(GT)-printers.h $(GT)-spi.h $(GT)-test-part.h $(GT)-typed-test.h
GTESTINC_FILES_3=$(GT).h $(GT)_pred_impl.h $(GT)_prod.h
GTESTINC_FILES=$(GTESTINC_FILES_1) $(GTESTINC_FILES_2) $(GTESTINC_FILES_3)
# GTest internal header files
GTESTINC_INTERNAL_FILES_1=$(GT)-death-test-internal.h $(GT)-filepath.h $(GT)-internal.h $(GT)-param-util.h
GTESTINC_INTERNAL_FILES_2=$(GT)-port-arch.h $(GT)-port.h $(GT)-string.h $(GT)-type-util.h
GTESTINC_INTERNAL_FILES=$(GTESTINC_INTERNAL_FILES_1) $(GTESTINC_INTERNAL_FILES_2)
# Compilation dependices
DEPENDICES=$(GTESTSRC_FILES) $(GTEST_INC_FILES) $(GTESTINC_INTERNAL_FILES) $(GTESTINC_INTERNAL_CUSTOM_FIlES)
# GTest directories
GTESTINCDIR=../googletest/googletest/include/gtest
GTESTSRCDIR=../googletest/googletest/src
# Compiler include arguments
INCLUDE_GTESTINC_INTERNAL=-I$(GTESTINCDIR)/internal/
INCLUDE_GTESTTINC_INTERNAL_CUSTOM=-I$(GTESTINCDIR)/internal/custom/
INCLUDE_GTESTINC=-I$(GTESTINCDIR)/
INCLUDE_GTESTSRC=-I$(GTESTSRCDIR)/
INCLUDE_GTEST_LIBS=$(INCLUDE_GTESTINC) $(INCLUDE_GTESTSRC) $(INCLUDE_GTESTINC_INTERNAL) $(INCLUDE_GTESTINC_INTERNAL_CUSTOM)
# ================================================= RULES =====================================================
# normal-use files
gtest-death-test.o : $(DEPENDICES)
	g++ $(GTESTSRCDIR)/$(GT)-death-test.cc $(GTESTINCDIR)/$(GT)-death-test.h -o $@ $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
gtest-matchers.o : $(DEPENDICES)
	g++ $(GTESTSRCDIR)/$(GT)-matchers.cc $(GTESTINCDIR)/$(GT)-matchers.h -o $@ $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
gtest-message.o : $(DEPENDICES)
	g++ $(GTESTINCDIR)/$(GT)-message.h -o $@ $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
gtest-param-test.o : $(DEPENDICES)
	g++ $(GTESTINCDIR)/$(GT)-param-test.h -o $@ $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
gtest-printers.o : $(DEPENDICES)
	g++ $(GTESTSRCDIR)/$(GT)-printers.cc $(GTESTINCDIR)/$(GT)-printers.h -o $@ $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
gtest-spi.o : $(DEPENDICES)
	g++ $(GTESTINCDIR)/$(GT)-spi.h -o $@ $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
gtest-test-part.o : $(DEPENDICES)
	g++ $(GTESTSRCDIR)/$(GT)-test-part.cc $(GTESTINCDIR)/$(GT)-test-part.h -o $@ $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
gtest-typed-test.o : $(DEPENDICES)
	g++ $(GTESTSRCDIR)/$(GT)-typed-test.cc $(GTESTINCDIR)/$(GT)-typed-test.h -o $@ $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
# internal files
md internal
cd internal
gtest-death-test-internal.o : $(DEPENDICES)
	g++ ../$(GTESTINCDIR)/internal/$(GT)-death-test-internal.h -o $(GT)-test-internal.o $(FLAGS) -std=$(STANDARD) $(INCLUDE_GTEST_LIBS)
## common internal files