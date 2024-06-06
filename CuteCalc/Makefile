CC=g++
FLAGS=-Wall -Werror -Wextra -std=c++17 -pedantic -g
LIBS=-lstdc++
TEST=tests/*.cpp
MODEL=model/*.cpp
LIBGTEST=-lgtest -lgtest_main $(LIBS)
OS:=$(shell uname -s)
BIN_FILE=CuteCalc
ALL_FILES := main.cpp $(wildcard s21_*.cpp) $(wildcard */s21_*.cpp) $(wildcard s21_*.h) $(wildcard */s21_*.h) $(wildcard credit_deposit/*.cpp) $(wildcard credit_deposit/*.h)
ifeq ($(OS), Darwin)
	FLAGS += -D MACOS
	OPEN:=open
	QMAKE:=qmake
else
	LIBS += -lsubunit -lrt -lm -lpthread
	OPEN:=xdg-open
	QMAKE:=qmake6
endif

rebuild: clean all

all: clean gcov_report dvi install

clean: uninstall
	@rm -rf *.o *.gcda *.gcno gcov_test ./report ./build ./html ./latex CPPLINT.cfg cpplint.py ./gcov_test.dSYM ./test.dSYM test

build: clean
	@mkdir -p ./build
	$(QMAKE) CuteCalc.pro -o ./build/$(BIN_FILE)_makefile
	cd ./build && make -f $(BIN_FILE)_makefile
	rm -rf ./build/moc_* ./build/*.o ./build/*.h ./build/$(BIN_FILE)_makefile ./build/.qmake.stash

install: build
ifeq ($(OS), Darwin)
	open ./build/$(BIN_FILE).app
else 
	./build/$(BIN_FILE)
endif

uninstall:
ifeq ($(OS), Darwin)
	@rm -rf ./build/$(BIN_FILE).app ./build/$(BIN_FILE).tar.gz
else
	@rm -rf ./build/$(BIN_FILE) ./build/$(BIN_FILE).tar.gz
endif

dist: build
ifeq ($(OS), Darwin)
	cd ./build && tar -czvf $(BIN_FILE).tar.gz $(BIN_FILE).app
else
	cd ./build && tar -czvf $(BIN_FILE).tar.gz $(BIN_FILE)
endif

tests: clean
	@$(CC) $(FLAGS) $(TEST) $(MODEL) ./credit_deposit/credit_deposit.cpp $(LIBGTEST) -o test
	@./test
	@rm -rf test

gcov_report: clean
	@$(CC) $(FLAGS) $(TEST) $(MODEL) ./credit_deposit/credit_deposit.cpp --coverage $(LIBGTEST) -o gcov_test
	@./gcov_test
	@mkdir -p report
	@gcovr . -e "tests/*" --html --html-details report/index.html
	@rm -rf *.gcda *.gcno *.info gcov_test
	@sh -c "if grep -iq microsoft /proc/version ; then cd ./report; cmd.exe /c start index.html; else $(OPEN) ./report/index.html; fi"

dvi:
	open readme.pdf

clf:
	clang-format -n --style=Google ${ALL_FILES}

cpk:
	cppcheck --language=c++ ${ALL_FILES}

style: clf cpk

fix_style:
	@clang-format -i --style=Google ${ALL_FILES}

leaks:
	@$(CC) $(FLAGS) ./tests/s21_test_model.cpp ./model/s21_model.cpp ./credit_deposit/credit_deposit.cpp $(LIBGTEST) -o test
	valgrind --leak-check=full --show-leak-kinds=all ./test
	@rm -rf test

.PHONY: all clean
