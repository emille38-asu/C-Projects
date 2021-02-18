#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student // A structure to store first and last names of students
{
    char last_name[30];

    char first_name[30];
};

struct examination_seating // Structure to create a pointer to examination_seating
{
    struct student **seating;

    int row;

    int col;
};

void student_init_default(struct student *p) // Initialization for char arrays
{
    char last[30] = "";

    char first[30] = "";

    strcpy(p->first_name, first);

    strcpy(p->last_name, last);
}

void student_init (struct student *p, char *info) // student_init
{
    char *name;

    char delimit [] = {','};

    name = strtok(info , delimit);

    strcpy (p->first_name , name);

    name = strtok (NULL , delimit);

    strcpy (p->last_name , name);
}

void student_to_string (struct student *p ) // Printing the student first and last names
{
    printf ("%c.%c.", p->first_name[0], p->last_name[0]);
}

void examination_seating_init (int rowNum, int columnNum, struct examination_seating *t )  /*** Checking to if the
        row is valid***/
        {
    if (rowNum == 0 || columnNum == 0)
    {
        printf("Input not valid.");
    }
        }

    int assign_student_at (int row, int col, struct examination_seating *t, struct student *p) /*** Assigning students to
 *
 specific rows***/
            {

        if (!strcmp (t->seating[row][col].first_name, "")
            && !strcmp (t->seating[row][col].last_name, ""))
        {
            t->seating[row][col] = *p;

            return 1;
        }

        return 0;
    }

    int check_boundaries(int row, int col, struct examination_seating *t) 
    {// Check for boundaries of the the rows
            
        if (t->seating == NULL)
        {
            return 0;
        }
        if (row >= 0 && row < t->row && col >= 0 && col < t->col)
        {
            return 1;
        }
        return 0;
    }

    void examination_seating_to_string(struct examination_seating *t)  //  Converting the input data to text
            {
        printf("\nThe current seating\n-----------------------\n");
        int i;

        int j;

        for (i = 0; i < t->row; i++)
        {
            for (j = 0; j < t->col; j++)
            {
                printf("%s%s ", t->seating[i][j].first_name, t->seating[i][j].last_name);
            }
            printf("\n");
        }
    }
    void main()  // Beginning of program
    {
        struct examination_seating examination_seating;

        struct student temp_student;

        int row, col, rowNum, columnNum;

        char student_info[30];

        // Ask a user to enter a number of rows for an examination seating
        printf("Please enter a number of rows for an examination seating.\n");
        scanf("%d", &rowNum);

        // Ask a user to enter a number of columns for an examination seating
        printf("Please enter a number of columns for an examination seating.\n");
        scanf("%d", &columnNum);

        // examination_seating
        examination_seating_init(rowNum, columnNum, &examination_seating);

        printf("Please enter a student information or enter \"Q\" to quit.\n");
/*** reading a student's information ***/

        scanf("%s", student_info);

/* we will read line by line **/

        while (strcmp(student_info, "Q")) // change
        {
            printf("\nA student information is read.\n");

// printing information.
            printf("%s", student_info);
// student
            student_init(&temp_student, student_info);

// Ask a user to decide where to seat a student by asking
// for row and column of a seat
            printf("\nPlease enter a row number where the student wants to sit.\n");
            scanf("%d", &row);

            printf("\nPlease enter a column number where the student wants to sit.\n");
            scanf("%d", &col);

// Checking if the row number and column number are valid
// (exist in the theatre that we created.)
            if (check_boundaries(row, col, &examination_seating) == 0) 
            {
                printf("\nrow or column number is not valid.");

                printf("A student %s %s is not assigned a seat.", temp_student.first_name, temp_student.last_name);

            } else
                {
                // Assigning a seat for a student
                if (assign_student_at(row, col, &examination_seating, &temp_student) == 1) 
                {
                    printf("\nThe seat at row %d and column %d is assigned to the student \n", row, col);
                    student_to_string(&temp_student);
                    examination_seating_to_string(&examination_seating);

                } else
                    {
                    printf("\nThe seat at row %d and column %d is taken.\n", row, col);
                }
            }
// Read the next studentInfo
            printf("Please enter a student information or enter \"Q\" to quit.\n");
/*** reading a student's information ***/
            scanf("%s", student_info);
        }
    }