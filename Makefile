##by @bnatalha.

# - - - - - - - - - - - - - - - - - - - -
# - - ---------- VARIABLES ---------- - -
# - - - - - - - - - - - - - - - - - - - -

# Compilation flags
#CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0
# For debugging
CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g

# include directory
INC =-I include


# - - - - - - - - - - - - - - - - - - - -
# - - ----------- TARGETS ----------- - -
# - - - - - - - - - - - - - - - - - - - -

# ================ PHONY =================
.PHONY: all init val clean docs

# ================= ALL ==================
# Creates everything that is needed in order to compile, compiles and then deletes the .o files
all: init bin/QLT clean

# Creates the 'bin' folder at the current directory if there's no other folder with this name on it.
init:
	mkdir -p bin

# ============ DOCUMENTATION ==============
# Creates the 'docs' folder at the current directory if there's no other folder with this name on it.
# Generates .html documentation via doxygen at the folder 'docs'
docs: Doxyfile
	mkdir -p docs ;\
	doxygen	

# ============== VALGRIND =================
# Runs valgrind with 'bin/QLT'
val1:
	valgrind --leak-check=yes bin/QLT

# ============== EXECUTABLES ==============
# For QLT:
bin/QLT: bin/main.o
	g++ $^ -o $@

# ================ OBJECTS ================
# For QLT:
bin/main.o: src/main.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

# ================ CLEANER ================
# Removes objects
clean:
	$(RM) bin/*.o