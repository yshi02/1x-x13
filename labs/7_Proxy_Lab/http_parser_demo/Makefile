CC = gcc
INPUT = http_parser_demo.c http_parser.h
PARSER_LIB_PATH = .
LDLIBS = -Wl,-rpath,$(PARSER_LIB_PATH)
LDLIBS += -L$(PARSER_LIB_PATH) -lhttp_parser
TARGET = http_parser_demo

all:
	$(CC) -o $(TARGET) $(INPUT) $(LDLIBS)

clean:
	rm -f $(TARGET)
