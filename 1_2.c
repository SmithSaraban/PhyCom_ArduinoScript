#include <stdio.h>

int main() {
    char info[41];
    int g1, g2, g3, g4, g5, g6;
    double gpa;

    scanf(" %[^\n]%d %d %d %d %d %d", info, &g1, &g2, &g3, &g4, &g5, &g6);
    gpa = ((g1+g2+g3+g4+g5+g6)*3)/18.0;
    printf("Grade announcement 1/2568: %s\nGPS/GPA: %.2f", info, gpa);

    return 0;
}