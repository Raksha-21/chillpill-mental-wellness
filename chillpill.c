#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void assign_tasks(const char *mood, char tasks[4][100]) {
    const char *mild_depression[] = {
        "Do light stretching for 10 minutes",
        "Drink a glass of water and rest",
        "Talk to a trusted friend",
        "Write something you're grateful for"
    };
    const char *moderate_depression[] = {
        "Engage in a hobby you enjoy",
        "Spend time with a loved one",
        "Learn a new skill",
        "Practice gratitude journaling"
    };
    const char *severe_depression[] = {
        "Practice mindfulness for 5 minutes",
        "Take a short walk outside",
        "Listen to calming music",
        "Write in your journal about positive experiences"
    };
    const char *extreme_depression[] = {
        "Call a mental health helpline",
        "Talk to a therapist immediately",
        "Do deep breathing",
        "Sit with someone you trust"
    };
    const char *good[] = {
        "Try a new recipe",
        "Volunteer your time",
        "Learn a new language",
        "Set a challenging goal"
    };
    const char *bad[] = {
        "Take a relaxing bath",
        "Watch a funny movie",
        "Practice deep breathing exercises",
        "Spend time in nature"
    };

    const char **selected = NULL;

    if (strcmp(mood, "mild depression") == 0) selected = mild_depression;
    else if (strcmp(mood, "moderate depression") == 0) selected = moderate_depression;
    else if (strcmp(mood, "severe depression") == 0) selected = severe_depression;
    else if (strcmp(mood, "extreme depression") == 0) selected = extreme_depression;
    else if (strcmp(mood, "good") == 0) selected = good;
    else if (strcmp(mood, "bad") == 0) selected = bad;
    else {
        printf("Invalid mood input.\n");
        exit(1);
    }

    for (int i = 0; i < 4; ++i) strcpy(tasks[i], selected[i]);

    srand(time(NULL));
    for (int i = 0; i < 4; ++i) {
        int j = rand() % 4;
        char temp[100];
        strcpy(temp, tasks[i]);
        strcpy(tasks[i], tasks[j]);
        strcpy(tasks[j], temp);
    }
}

void simulate_online_consultation() {
    printf("\nConnecting to a certified mental health specialist...\n");
    printf("Estimated wait time: 2 minutes.\n");
    printf(" Connection established with Dr. Meera (Psychologist).\n");
    printf(" Consultation scheduled. Duration: 30 mins\n");
}

void schedule_session() {
    printf("\nSchedule a session (format: HH:MM): ");
    char time[10];
    scanf("%s", time);
    printf("Your therapy session is booked for %s today.\n", time);
}

void check_bp_pulse() {
    int systolic, diastolic, pulse;
    printf("\n Enter your BP (systolic and diastolic): ");
    scanf("%d %d", &systolic, &diastolic);
    printf(" Enter your pulse rate: ");
    scanf("%d", &pulse);

    if (systolic > 140 || diastolic > 90) {
        printf(" High blood pressure. Please relax, hydrate, and consult a doctor if needed.\n");
    } else if (systolic < 90 || diastolic < 60) {
        printf(" Low blood pressure. Take rest and eat something light.\n");
    } else {
        printf("BP is within normal range.\n");
    }

    if (pulse < 60 || pulse > 100) {
        printf("Pulse rate is unusual. Consider resting or seeking help.\n");
    } else {
        printf("✅Pulse rate looks normal.\n");
    }
}

void emergency_contact() {
    printf("\n If you're in immediate distress, please call a helpline:\n");
    printf("India Helpline: 9152987821 (iCall - Mental Health Support)\n");
    printf("AASRA: 91-9820466726 | Snehi: +91-9582208181\n");
}

int main() {
    char name[100], mood[100];
    char tasks[4][100];
    int completed[4] = {0};

    printf("Welcome to Chill Pill - Your Mental Wellness Companion!\n\n");

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\nHi %s! How are you feeling today?\n", name);
    printf("Choose: good / bad / mild depression / moderate depression / severe depression / extreme depression\n> ");
    fgets(mood, sizeof(mood), stdin);
    mood[strcspn(mood, "\n")] = '\0';

    assign_tasks(mood, tasks);

    printf("\nHere are your suggested tasks:\n");
    for (int i = 0; i < 4; ++i)
        printf("%d. %s\n", i + 1, tasks[i]);

    printf("\n Mark completed tasks (enter number 1–4, 0 to finish):\n");
    int choice;
    while (1) {
        printf("Completed task: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice >= 1 && choice <= 4) {
            completed[choice - 1] = 1;
            printf("Marked as completed.\n");
        }
    }

    // Extra features
    int option;
    printf("\n Choose additional options:\n");
    printf("1. Consult a specialist online\n");
    printf("2. Schedule a therapy session\n");
    printf("3. Enter BP and pulse rate\n");
    if (strcmp(mood, "extreme depression") == 0) {
        printf("4. Show emergency contact\n");
    }
    printf("0. Exit\n");

    do {
        printf("Select option: ");
        scanf("%d", &option);
        switch (option) {
            case 1: simulate_online_consultation(); break;
            case 2: schedule_session(); break;
            case 3: check_bp_pulse(); break;
            case 4: if (strcmp(mood, "extreme depression") == 0) emergency_contact(); break;
            case 0: printf("👋 Take care, %s. Stay strong!\n", name); break;
            default: printf("Invalid option.\n");
        }
    } while (option != 0);

    return 0;
}
