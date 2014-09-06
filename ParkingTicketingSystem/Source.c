#include <stdio.h>
#include <stdlib.h>

static char name[10][20] = {"Ariel", "Beca",
							"Caroline", "Daphne",
							"Faustine", "Gretel", 
							"Hercules", "Ignatius",
							"Jacquard", "Keith" };
							
static const int ic[10] = {	864378, 854653, 
							234890, 975384, 
							986574,	745235, 
							436578, 970874, 
							162789, 686664 };
	
static const char contact[10][13] = { "016284799", "016284799",
									  "016284799", "016284799",
									  "016284799", "016284799",
									  "016284799", "016284799",
									  "016284799", "016284799" };

static const int fee[3][3] = { { 1, 5, 60  },
							   { 2, 8, 80  },
							   { 0, 0, 120 } };
								
static int ticketType[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };	
static int day[10] 		  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static int month[10]	  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static int year[10] 	  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


void buy(int);
void edit();

int main(int argc, char const *argv[])
{
	FILE* f = fopen("data.txt", "w+");
	for (int i=0; i<10;i++)
		fscanf(f, "%d %d %d", day[i], month[i], year[i]);
	
	int currentDay, currentMonth, currentYear;
	int user;
	int choice;

	printf("Welcome\n");
	printf("Enter today's date: (eg: 03-05-2014)");
	scanf("%d-%d-%d", &currentDay, &currentMonth, &currentYear);

	printf("Enter your ID: ");
	scanf("%d", &user);

	printf("Welcome %s\n", name[user - 1]);
	printf("Contact Number: %s\n", contact[user - 1]);
	printf("\n1. Purchase new ticket\n");
	printf("2. Edit ticket type\n");
	printf("3. Cancel ticket\n");
	printf("4. Check ticket validity\n");
	printf("5. Exit\n");
	printf("Enter number 1-5: ");
	scanf("%d", &choice);

	printf("%d\n", choice);
	switch (choice)
	{
	case 1:
		buy(user-1);
		break;
	case 2:
		edit();
		break;
	case 3:
		// cancel();
		break;
	case 4:
		// check();
		break;
	case 5:
		break;
	default:
		printf("Invalid Menu\n");
		break;
	}
	
	for (int i=0; i<10;i++)
		fprintf(f, "%d %d %d\n", day[i], month[i], year[i]);
	fclose(f);
	return 0;
}


void buy(int user)
{
	int length, duration, choice;

	printf("Purchase Ticket\n");
	printf("1. Open Area\n");
	printf("2. Covered Area\n");
	printf("3. Designated Area\n");
	printf("Enter ticket type (1-3): ");
	scanf("%d", &ticketType[user]);
	
	printf("Enter duration (h/d/m): ");
	scanf("%d %c", &length, &choice);
	
	
	switch(choice)
	{
		case 'h':
			duration = 0;
			day[user] = currentDay+1;
			break;
		case 'd':
			day[user] = currentDay+length;
			duration = 1;
			break;
		case 'm':
			duration = 2;
			break;
		default:
			printf("Invalid input\n");
			exit(1);
	}
	if (ticketType[user] == 3)
		if (duration != 2)
			printf("Ticket is not available...");
	
	month[user] = currentMonth;
	printf("Total is: %d\n", length * fee[ticketType[user]-1][duration]);
}

void edit()
{
	int choice;
	printf("1. Change ticket type\n");
	printf("2. Change ticket date\n");
	scanf("%d", &choice);

	printf("%d\n", choice);
	switch (choice) {
	case 1:
		// changetype();
		break;
	case 2:
		// changedate();
		break;
	case 3:
	default:
		printf("Invalid Menu\n");
		break;
	}
}