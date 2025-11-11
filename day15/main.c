#include <stdio.h>

int main() {
    int n, marks[10];
    int i, sum = 0, pass = 0, fail = 0;
    int highest, lowest;
    int gradeAplus = 0, gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0;

    printf("Student Performance Analyzer \n");
    printf("Enter total number of students (max 10): ");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Invalid number of students!\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    highest = lowest = marks[0];

    for (i = 0; i < n; i++) {
        sum += marks[i];
        if (marks[i] > highest) highest = marks[i];
        if (marks[i] < lowest) lowest = marks[i];

        if (marks[i] >= 90) gradeAplus++;
        else if (marks[i] >= 80) gradeA++;
        else if (marks[i] >= 70) gradeB++;
        else if (marks[i] >= 60) gradeC++;
        else if (marks[i] >= 50) gradeD++;
        else fail++;

        if (marks[i] >= 50) pass++;
    }

    float avg = (float)sum / n;

    printf(" Result Summary \n");
    printf("Average Marks: %.2f\n", avg);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks : %d\n", lowest);
    printf("Total Passed Students: %d\n", pass);
    printf("Total Failed Students: %d\n", fail);

    printf("\nGrade Distribution:\n");
    printf("A+ = %d\nA = %d\nB = %d\nC = %d\nD = %d\nFail = %d\n",
           gradeAplus, gradeA, gradeB, gradeC, gradeD, fail);

    return 0;
}
