#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char sentence[] = "Practice makes a person better at programming";
    char input[200];

    int correct = 0;
    int total;
    double accuracy, timeTaken, wpm;

    time_t start, end;

    printf("====================================\n");
    printf("       TYPING SPEED TEST\n");
    printf("====================================\n");

    printf("\nType the following sentence:\n\n");
    printf("%s\n\n", sentence);

    printf("Press ENTER when you are ready...");
    getchar();

    printf("\nStart typing:\n");

    start = time(NULL);

    fgets(input, sizeof(input), stdin);

    end = time(NULL);

    input[strcspn(input, "\n")] = '\0';

    timeTaken = difftime(end, start);

    total = strlen(sentence);

    for (int i = 0; i < total && input[i] != '\0'; i++) {
        if (input[i] == sentence[i]) {
            correct++;
        }
    }

    accuracy = (total > 0) ? (correct * 100.0 / total) : 0;

    if (timeTaken > 0) {
        wpm = (strlen(input) / 5.0) / (timeTaken / 60.0);
    } else {
        wpm = 0;
    }

    printf("\n====================================\n");
    printf("             YOUR RESULTS\n");
    printf("====================================\n");

    printf("Time Taken : %.0f seconds\n", timeTaken);
    printf("WPM        : %.2f\n", wpm);
    printf("Accuracy   : %.2f%%\n", accuracy);
    printf("Correct Characters : %d/%d\n", correct, total);

    printf("====================================\n");

    if (accuracy >= 90) {
        printf("Excellent typing!\n");
    } else if (accuracy >= 70) {
        printf("Good effort! Keep practicing.\n");
    } else {
        printf("Keep practicing to improve!\n");
    }

    return 0;
}





