CC=gcc
CC_FLAGS= -Wall -Werror -Wextra -std=c11 
#-fsanitize=address
test_flags=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)
VALGRIND_FLAGS = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

ifeq ($(OS),Linux)
	test_libs=$(shell pkg-config --libs --cflags check) -lsubunit -lm
	open=xdg-open
else
	test_libs=$(shell pkg-config --libs --cflags check)
	open=open
endif

#all: clean build

# start: install
# 	build/S21_3DViewer

install: clean
	mkdir build
	cd ./build && qmake6 ../S21_3DViewer && make

uninstall:
	rm -rf build
	make clean

build:
	$(CC) $(CC_FLAGS) main.c obj_files_management/*.c lib_matrix/*.c -o parse_test.out -lm

test: clean
	$(CC) $(CC_FLAGS) $(test_flags) tests/*.c obj_files_management/*.c lib_matrix/*.c affine/*.c -o s21_test $(test_libs)
	./s21_test
	mv *.gcda *.gcno tests/

gcov_report: test
	lcov -t "s21_test" -o $(tests_info)test.info -c -d .
	genhtml -o report $(tests_info)test.info
	$(open) report/index.html

dvi:
	@doxygen
	@open Documentation/html/index.html

dist:
	rm -rf 3DViewer/
	mkdir 3DViewer/
	cp -r Makefile affine lib_matrix obj_files_management S21_3DViewer 3DViewer
	tar cf 3DViewer.tgz 3DViewer/
	rm -rf 3DViewer/

clean:
	rm -f *.out s21_test test.info settings
	rm -f ./-lm-*.gcno
	rm -f tests/*.gcda tests/*.gcno *.gcda *.gcno *.txt
	rm -d -rf Documentation report build 3DViewer.tgz build-S21_3DViewer-Desktop-Debug

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c */*.c */*.h */*.cpp 
	rm -f .clang-format

clang_check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c */*.c */*.h */*.cpp 
	rm -f .clang-format
