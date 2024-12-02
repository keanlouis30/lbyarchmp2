#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXECUTIONS 30
#define LINE_SIZE 256

double calculate_average(double array[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

void append_averages_to_file(const char *filename, double c_avg, double asm_avg, int count) {
    printf("Appending averages...\n");

    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Error opening averages file");
        return;
    }

    fprintf(file, "Average for last %d executions:\n", count);
    fprintf(file, "C file average execution time: %.6f seconds\n", c_avg);
    fprintf(file, "ASM file average execution time: %.6f seconds\n\n", asm_avg);
    printf("Successfully appended averages to file.\n");

    fclose(file);
}

int main() {
    FILE *file = fopen("readMe.md", "r"); 
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[LINE_SIZE];
    double c_exec_time_array[MAX_EXECUTIONS] = {0};
    double asm_exec_time_array[MAX_EXECUTIONS] = {0};
    int execution_count = 0;
    int array_index = 0;

    const char *averages_file = "readMe.md"; 

    // Read through the file line by line
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Execution #")) {
            execution_count++;

            fgets(line, sizeof(line), file); 
            fgets(line, sizeof(line), file);

            double c_time = atof(line + 23); 
            printf("C Time Extracted: %.6f\n", c_time); 

            fgets(line, sizeof(line), file);
            printf("ASM Line: %s\n", line); 

            double asm_time = 0.0;
            if (sscanf(line, "ASM file execution time: %lf", &asm_time) == 1) {
                printf("ASM Time Extracted: %.6f\n", asm_time); 
            } else {
                printf("Failed to extract ASM time.\n");
            }

            c_exec_time_array[array_index] = c_time;
            asm_exec_time_array[array_index] = asm_time;
            array_index++;

            if (array_index == MAX_EXECUTIONS) {
                double c_avg = calculate_average(c_exec_time_array, MAX_EXECUTIONS);
                double asm_avg = calculate_average(asm_exec_time_array, MAX_EXECUTIONS);

                printf("Average C execution time for last %d runs: %.6f\n", MAX_EXECUTIONS, c_avg);
                printf("Average ASM execution time for last %d runs: %.6f\n", MAX_EXECUTIONS, asm_avg);

                append_averages_to_file(averages_file, c_avg, asm_avg, MAX_EXECUTIONS);

                array_index = 0;
                memset(c_exec_time_array, 0, sizeof(c_exec_time_array));
                memset(asm_exec_time_array, 0, sizeof(asm_exec_time_array));
            }
        }
    }

    if (array_index > 0) {
        double c_avg = calculate_average(c_exec_time_array, array_index);
        double asm_avg = calculate_average(asm_exec_time_array, array_index);

        printf("Average C execution time for last %d runs: %.6f\n", array_index, c_avg);
        printf("Average ASM execution time for last %d runs: %.6f\n", array_index, asm_avg);

        append_averages_to_file(averages_file, c_avg, asm_avg, array_index);
    }

    fclose(file); 
    return EXIT_SUCCESS;
}
