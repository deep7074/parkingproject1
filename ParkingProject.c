#include <stdio.h>

#define MAX_SPOTS 20

// Define prices for different vehicle types
#define CAR_PRICE 10
#define MOTORCYCLE_PRICE 5
#define TRUCK_PRICE 15

// Global variables
char parkingSpots[MAX_SPOTS][10]; // Array to store vehicle license plates
int occupied[MAX_SPOTS] = {0};   // Array to track occupied spots

// Function prototypes
void displayMenu();
void parkVehicle();
void removeVehicle();
void displayStatus();

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStatus();
                break;
            case 2:
                parkVehicle();
                break;
            case 3:
                removeVehicle();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nParking Lot Management System\n");
    printf("1. Display Parking Lot Status\n");
    printf("2. Park a Vehicle\n");
    printf("3. Remove a Vehicle\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void parkVehicle() {
    char plate[10];
    int type;
    
    printf("Enter vehicle license plate: ");
    scanf("%s", plate);

    printf("Select vehicle type:\n");
    printf("1. Car\n");
    printf("2. Motorcycle\n");
    printf("3. Truck\n");
    scanf("%d", &type);

    if (type < 1 || type > 3) 
    {
        printf("Invalid vehicle type.\n");
        return;
    }

    for (int i = 0; i < MAX_SPOTS; i++) 
    {
        if (!occupied[i]) 
        {
            strcpy(parkingSpots[i], plate);
            occupied[i] = 1;

            printf("Vehicle parked successfully.\n");
            return;
        }
    }

    printf("Sorry, parking lot is full.\n");
}

void removeVehicle() 
{
    char plate[10];
    int spot;

    printf("Enter vehicle license plate to remove: ");
    scanf("%s", plate);

    for (int i = 0; i < MAX_SPOTS; i++) {
        if (occupied[i] && strcmp(parkingSpots[i], plate) == 0) 
        {
            spot = i;
            occupied[i] = 0;
            break;
        }
    }

    if (occupied[spot]) 
    {
        printf("Vehicle not found.\n");
        return;
    }

    int type;
    printf("Enter vehicle type (1: Car, 2: Motorcycle, 3: Truck): ");
    scanf("%d", &type);

    int charges = 0;
    switch (type) 
    {
        case 1:
            charges = CAR_PRICE;
            break;
        case 2:
            charges = MOTORCYCLE_PRICE;
            break;
        case 3:
            charges = TRUCK_PRICE;
            break;
        default:
            printf("Invalid vehicle type.\n");
            return;
    }

    printf("Vehicle removed. Parking charges: $%d\n", charges);
}

void displayStatus() 
{
    printf("\nParking Lot Status:\n");
    printf("Spot\tLicense Plate\n");
    for (int i = 0; i < MAX_SPOTS; i++) 
    {
        if (occupied[i]) 
        {
            printf("%d\t%s\n", i + 1, parkingSpots[i]);
        } else 
        {
            printf("%d\tEmpty\n", i + 1);
        }
    }
}
