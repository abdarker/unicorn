#ifndef UNICORN_RESULT_H
#define UNICORN_RESULT_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

#include "unicorn/types.h"


struct UnicornTestResult
{
    bool success;
    char *failed_assertion;
    char *error_message;
    size_t assertion_line;
    UnicornTest *test;
    UnicornCollection *param_snapshots;
    struct timeval start_time;
    struct timeval end_time;
    int pipe[2];
};

UnicornTestResult *unicorn_new_test_result();

void unicorn_pipe_duration(UnicornTestResult *test_result, struct timeval start_time, struct timeval end_time);
void unicorn_pipe_assertion_failure(UnicornTestResult *test_result, char *failed_assertion, size_t assertion_line);
void unicorn_pipe_error_message(UnicornTestResult *test_result, char *error_message, size_t message_size);

void unicorn_set_assertion_failure(UnicornTestResult *test_result, char *failed_assertion, size_t assertion_line);
void unicorn_set_error_message(UnicornTestResult *test_result, char *error_message, size_t message_size);
void unicorn_free_test_result(UnicornTestResult *test_result);


struct UnicornTestParamSnapshot
{
    UnicornTestParam *param;
    size_t index;
};

UnicornTestParamSnapshot *unicorn_new_test_param_snapshot(UnicornTestParam *test_param);
void unicorn_free_test_param_snapshot(UnicornTestParamSnapshot *param_snapshot);


#endif
