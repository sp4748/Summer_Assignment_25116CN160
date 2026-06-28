#include <stdio.h>

#define TOTAL_SEATS 10

int main() {
    int seats[TOTAL_SEATS] = {0};
    int choice, seat, i;

    do {
        printf("\n===== Ticket Booking System =====\n");
        printf("1. View Available Seats\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Display Booking Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nAvailable Seats:\n");
                for(i = 0; i < TOTAL_SEATS; i++) {
                    if(seats[i] == 0)
                        printf("Seat %d : Available\n", i + 1);
                }
                break;

            case 2:
                printf("Enter seat number (1-%d): ", TOTAL_SEATS);
                scanf("%d", &seat);

                if(seat >= 1 && seat <= TOTAL_SEATS) {
                    if(seats[seat - 1] == 0) {
                        seats[seat - 1] = 1;
                        printf("Ticket booked successfully!\n");
                    } else {
                        printf("Seat already booked!\n");
                    }
                } else {
                    printf("Invalid seat number!\n");
                }
                break;

            case 3:
                printf("Enter seat number to cancel: ");
                scanf("%d", &seat);

                if(seat >= 1 && seat <= TOTAL_SEATS) {
                    if(seats[seat - 1] == 1) {
                        seats[seat - 1] = 0;
                        printf("Ticket cancelled successfully!\n");
                    } else {
                        printf("Seat is not booked.\n");
                    }
                } else {
                    printf("Invalid seat number!\n");
                }
                break;

            case 4:
                printf("\nBooking Status:\n");
                for(i = 0; i < TOTAL_SEATS; i++) {
                    printf("Seat %d : %s\n", i + 1,
                           seats[i] ? "Booked" : "Available");
                }
                break;

            case 5:
                printf("Thank you for using the Ticket Booking System.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}