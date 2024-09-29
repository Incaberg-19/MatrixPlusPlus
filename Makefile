COMPILER = g++
FLAGS_COMPILER = -std=c++17 -Wall -Wextra -Werror -pedantic-errors
SRC=source/*.cpp
LIB=s21_matrix_oop.a

all: $(LIB)

s21_matrix_oop.a:
	$(COMPILER) $(FLAGS_COMPILER) -c $(SRC) 
	ar rc $(LIB) *.o
	ranlib $(LIB)

test: clean s21_matrix_oop.a
	$(COMPILER) $(FLAGS_COMPILER) s21_matrix_oop_test.cpp -lgtest -pthread s21_matrix_oop.a -o test
	./test

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf s21_matrix_oop
	rm -rf test

clang:
	cp ../materials/linters/.clang-format source/
	cp ../materials/linters/.clang-format .
	clang-format -n source/*.cpp
	clang-format -n *.cpp
	clang-format -i *.cpp
	clang-format -i *.h
	clang-format -i source/*.cpp
	rm -rf .clang-format
	rm -rf source/.clang-format

memcheck: test
ifeq ($(OS), Darwin)
	leaks -atExit -- ./test
else 
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
endif

