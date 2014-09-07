#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 256

struct employee {
	int ic;
	char name[20];
	char contact[13];
	int ticketType;
	struct tm *expdate;
} Employees[10] = {
	{864378, "Ariel", "016284799", 0, NULL},
	// {},
	// {},
	// {},
	// {},
	// {},
	// {},
	// {},
	// {},
	// {}
};
static const int fee[3][3] = {{1, 5, 60}, {2, 8, 80},{0, 0, 120}};

void buy(int);
void edit(int);
void delete(int);

int main(int argc, char const *argv[])
{	
	char buffer[SIZE];
	time_t curtime;
	struct tm *loctime;
	
	// disini load.
	int user;
	int choice;
	
	curtime = time(NULL);
	loctime = localtime (&curtime);
	strftime (buffer, SIZE, "%d-%m-%Y", loctime);
	printf("%s\n", buffer);
	
	printf("Welcome\n");
	printf("Enter your ID: ");
	scanf("%d", &user);

	printf("Welcome %s\n", Employees[user-1].name);
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
		edit(user-1);
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
	
	// disini save.
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
	scanf("%d", &(Employees[user].ticketType));
	
	printf("Enter duration (h/d/m): ");
	scanf("%d %c", &length, &choice);
	
	
	switch(choice)
	{
		case 'h':
			duration = 0;
			break;
		case 'd':
			duration = 1;
			break;
		case 'm':
			duration = 2;
			break;
		default:
			printf("Invalid input\n");
			exit(1);
	}
	if (Employees[user].ticketType == 3)
		if (duration != 2)
			printf("Ticket is not available...");
	
	printf("Total is: %d\n", length * fee[Employees[user].ticketType - 1][duration]);
}

void edit(int user)
{
	int length, duration, choice;

	printf("Do you want to change your ticket type? (y/n)");
	if (getchar()=='y') {
		printf("1. Open Area\n");
		printf("2. Covered Area\n");
		printf("3. Designated Area\n");
		printf("Enter ticket type (1-3): ");
		scanf("%d", &(Employees[user].ticketType));
	}
	printf("Do you want to change the duration?(y/n)");
	if (getchar()=='y') {
		printf("Enter duration (h/d/m): ");
		scanf("%d %c", &length, &choice);
		
		
		switch(choice)
		{
			case 'h':
				duration = 0;
				break;
			case 'd':
				duration = 1;
				break;
			case 'm':
				duration = 2;
				break;
			default:
				printf("Invalid input\n");
				exit(1);
		}
		if (Employees[user].ticketType == 3)
			if (duration != 2)
				printf("Ticket is not available...");
	}
	printf("Total is: %d\n", length * fee[Employees[user].ticketType-1][duration]);
}

void delete(int user) {
	printf("Are you sure? (y/n)");
	if (getchar()=='y') {
		Employees[user].ticketType = 0;
		printf("deleted.\n");
	}
}

