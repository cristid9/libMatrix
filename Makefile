CC = gcc
CFLAGS = -Wall -std=c99 -fpic
BINARY_LOCATION = ./bin/libMatrix.so
HEADER_LOCATION = ./src/matrix.h
LIB_OPTIONS = -shared -o
SOURCES = src/utility_functions.c src/error.c src/matrix.c src/helpers.c
OBJECT_FILES = utility_functions.o error.o matrix.o helpers.o
LIBFLAGS = -lm -c
INSTALLED_LIB_LOCATION = /usr/lib
INSTALLED_HEADER_LOCATION = /usr/include
TEST_FLAGS = -Wall -std=c99 -o
TEST_SOURCES = ./tests/test_runner.c
TEST_NAME = ./tests/tes_runner
TEST_LIBS = -lMatrix -lm
DOXYGEN_CONFIGFILE = ./docs/Doxyfile

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LIBFLAGS)
	$(CC) $(LIB_OPTIONS) $(BINARY_LOCATION) $(OBJECT_FILES)

install:
	cp $(BINARY_LOCATION) $(INSTALLED_LIB_LOCATION)
	chmod 0755 $(INSTALLED_LIB_LOCATION)/libMatrix.so
	cp $(HEADER_LOCATION) $(INSTALLED_HEADER_LOCATION)
	chmod 0544 $(INSTALLED_HEADER_LOCATION)/matrix.h

uninstall:
	rm $(INSTALLED_LIB_LOCATION)/libMatrix.so
	rm $(INSTALLED_HEADER_LOCATION)/matrix.h

 
clean:
	rm *.o
	rm $(BINARY_LOCATION)
	rm $(TEST_NAME)

check:
	$(CC) $(TEST_SOURCES) $(TEST_FLAGS) $(TEST_NAME) $(TEST_LIBS)	
	@echo --------------------------------------------------------;
	@./$(TEST_NAME)

check-debug:
	$(CC) -g $(TEST_SOURCES) $(TEST_FLAGS) $(TEST_NAME) $(TEST_LIBS)	
	@echo --------------------------------------------------------;
	@./$(TEST_NAME)


html:

	[ "$(ls -A ./docs)" ] || mv ./docs/Doxyfile ./; rm -rf ./docs/*; \
		mv ./Doxyfile ./docs/;

	doxygen $(DOXYGEN_CONFIGFILE)
	rm -rf latex/
	[ -d ./html ] || mkdir ./docs/html
	[ -d ./docs/html ] || mkdir ./docs/html
	[ -d ./html ] && mv  html/* ./docs/html/
	rm -rf html
