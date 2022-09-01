/*
 * @brief A simple demonstration of how to use the http_parser library.
 *
 * It is recommended to run the program first then match the program's output
 * with the printfs below and observe/interpret the library interface's behavior.
 *
 * It is also highly recommended to reference the http_parser.h file for detailed
 * interface declarations and enum definitions.
 *
 * Feel free to play with the code, add printfs, etc.
 *
 * @author Yufei Shi <yshi2@andrew.cmu.edu>
 * TODO: make it more interactive and add support for printing "\r\n" explicitly.
 */


#include <stdio.h>
#include <assert.h>
#include "http_parser.h"


/* Macro for stringifying the state of parser. FOR DEMONSTRATIVE PURPOSES ONLY. */
#define STRINGIFY(str) #str
#define GETSTATE(state) STRINGIFY(state)


/* line1: An HTTP request line */
const char line1[] = "GET http://www.cmu.edu:80/index.html HTTP/1.0\r\n"
                     "\r\n"; /* TODO: Why is there another "\r\n"? */

/* line2: A single HTTP header line  */
const char line2[] = "Host: www.cmu.edu\r\n";

/* line3, line4, line5: More HTTP header lines */
const char line3[] = "Port: 80\r\n";
const char line4[] = "Connection: close\r\n";
const char line5[] = "Proxy-Connection: close\r\n";


int main() {

    /* Below are some of the variables you'll need when using the parser */
    parser_state state;     /* parser's parsing state, can be any of
                               {REQUEST, HEADER, ERROR} */
    int parser_retval;      /* parser's return value, can be {0, -1, -2} */
    const char *val;        /* value (retrieved by parser), a const char
                               pointer declared on the stack */
    parser_value_type type; /* type of value to be retrieved, can be any of
                               {METHOD, HOST, SCHEME, URI, PORT, PATH, HTTP_VERSION} */
    header_t *header;       /* pointer to a header_t struct */


    /* To get the parser working, you'll need to have a parser first. */
    parser_t *parser = parser_new();


    /* Begin parsing line1. Results will be printed to stdout. */
    printf("========== Parsing a single HTTP request line ==========\n");
    printf("line1: [%s]\n", line1);

    state = parser_parse_line(parser, line1);
    printf("parser_parse_line returns state [%s]\n", GETSTATE(state));

    type = METHOD;          /* HTTP request method */
    parser_retval = parser_retrieve(parser, type, &val);
    printf("parser_retrieve returns [%d], indicating success\n", parser_retval);
    printf("parser_retrieve yields val [%s] for type [METHOD]\n", val);

    parser_retval = parser_retrieve(parser, PORT, &val); /* Use enum directly. */
    printf("parser_retrieve returns [%d], indicating success\n", parser_retval);
    printf("parser_retrieve yields val [%s] for type [PORT]\n", val);

    /* Begin parsing line2, a single HTTP header line */
    printf("\n========== Parsing a single HTTP header line ==========\n");
    printf("line2: [%s]\n", line2);

    state = parser_parse_line(parser, line2);
    printf("parser_parse_line returns state [%s]\n", GETSTATE(state));

    header = parser_lookup_header(parser, "Host");
    printf("parser_lookup_header returns a non-NULL pointer to a header_t [%p],"
            " indicating success\n", header);
    printf("The header contains a header name header->name [%s]"
            " and a header value header->value [%s]\n", header->name, header->value);

    /* Begin parsing more HTTP header lines */
    printf("\n========== Parsing more HTTP header lines ==========\n");
    printf("line3: [%s]\n", line3);
    printf("line4: [%s]\n", line4);
    printf("line5: [%s]\n", line5);

    parser_parse_line(parser, line3);
    parser_parse_line(parser, line4);
    parser_parse_line(parser, line5);

    /* You could use parser_retrieve_next_header to loop through all parsed headers. */
    int ite = 1;
    while (header = parser_retrieve_next_header(parser)) {
        printf("parser_retrieve_next_header returns header (%d): [%s: %s]\n",
                ite, header->name, header->value);
        ite++;
    }


    /* Free memory allocated by the parser */
    parser_free(parser);

    return 0;

}
