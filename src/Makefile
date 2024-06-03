CXX=g++
CFLAGS=-Wall -Werror -Wextra -Wpedantic
STANDART=-std=c++17
DIR_OBJECT=object
DIR_PARSER=parser
DIR_MANIPULATION=manipulation
DIR_TRANSFORMATION=transformation
VALGRIND=valgrind --tool=memcheck --leak-check=yes
GTEST=-lgtest

all: clean install 

install: uninstall
	mkdir -p build && cd build && qmake ../view
	cd build && make
	mv build/view 3D_Viewer
	rm -rf build/* build/.qmake.stash
	mv 3D_Viewer build

dvi:
	doxygen

dist: install dvi
	mkdir -p dist
	tar cf dist/3D_Viewer_V2.0 build doxygen
	
tests: clean all_objects
	$(CXX) $(CFLAGS) $(STANDART) -c tests/*.cpp $(GTEST)
	$(CXX) $(CFLAGS) $(STANDART) -o test *.o $(GTEST)
	$(VALGRIND) ./test

all_objects: object.o parser.o manipulation.o transformation.o

uninstall:
	rm -rf build

object.o:
	$(CXX) $(CFLAGS) $(STANDART) -c $(DIR_OBJECT)/*.cpp

parser.o:
	$(CXX) $(CFLAGS) $(STANDART) -c $(DIR_PARSER)/*.cpp

manipulation.o:
	$(CXX) $(CFLAGS) $(STANDART) -c $(DIR_MANIPULATION)/*.cpp

transformation.o:
	$(CXX) $(CFLAGS) $(STANDART) -c $(DIR_TRANSFORMATION)/*.cpp

clean:
	@rm -rf \
	*.o main
	rm -rf doxygen
	rm -rf test
	rm -rf build dist

style:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -i manipulation/*.* object/*.* parser/*.*  tests/*.* transformation/*.* view/*.*
	clang-format -n manipulation/*.* object/*.* parser/*.*  tests/*.* transformation/*.* view/*.*
	rm -rf .clang-format
