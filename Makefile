CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -std=c11

all: s21_3dviewer


style:
	cp ../../materials/linters/.clang-format ./	
	clang-format -n *.c *.h
	clang-format -i *.c *.h
git:
	git add . && git commit -m "Build fixed, parser_test.c errors while tests" && git push -f origin develop