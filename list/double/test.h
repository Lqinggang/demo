#ifndef LIST_DOUBLE_TEST_H
#define LIST_DOUBLE_TEST_H

#include "list.h"

struct student {
    unsigned int    stu_id;             /* student ID */
    char            stu_name[32];       /* student name */
    unsigned int    stu_age;            /* student age */
    unsigned int    stu_gender;         /* student gender */
};

extern int test_insert_into_before_list(plist head);
extern int test_insert_into_after_list(plist head);

extern int print_student_list(plist head);

extern int test_get_node_by_index(plist head);


#endif  /* LIST_DOUBLE_TEST_H */
