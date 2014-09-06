#include <stdio.h>
#include <stdlib.h>

static const char name[10][20] = {
	"Ariel", "Beca", "Caroline", "Daphne",
	"Faustine", "Gretel", "Hercules",
	"Ignatius", "Jacquard", "Keith" };
	
static const int ic[10] = {
	864378, 854653, 234890, 975384, 986574,
	745235, 436578, 970874, 162789, 686664 };
	
static const char contact[10][13] = {
	"016284799", "016284799", "016284799", "016284799", "016284799",
	"016284799", "016284799", "016284799", "016284799", "016284799" };

static const int ticketType[10] = {
	0, 1, 1, 2, 0,		// 0 : per hour, 1 : per day
	-1, 0, 1, 0, -1 };	// 2 : per month, -1 : invalid ticket

static int day[10] 		= { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static int month[10]	= { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static int year[10] 	= { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static const int fee[4][4] =  {	{ 0, 0, 0, 0   },
								{ 0, 1, 5, 60  },
								{ 0, 2, 8, 80  },
								{ 0, 0, 0, 120 } };

void buy();
void edit();
void cancel();
void check();
void open();
void covered();
void perhour();
void perday();
void permonth();
void designated();
void changetype();
void changedate();

int main(int argc, char const *argv[])
{
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
	switch (choice) {
	case 1:
		buy();
		break;
	case 2:
		edit();
		break;
	case 3:
		cancel();
		break;
	case 4:
		check();
		break;
	case 5:
		break;
	default:
		printf("Invalid Menu\n");
		break;
	}

	system("pause");
	return 0;
}


void buy()
{
	int type, length, duration;

	printf("Purchase Ticket\n");
	printf("1. Open Area\n");
	printf("2. Covered Area\n");
	printf("3. Designated Area\n");
	printf("Enter ticket type (1-3): ");
	scanf("%d", &type);
	
	printf("Enter duration (h/d/m): ");
	scanf("%d %c", &length, &duration);
	
	printf("Total is: %d\n", length * fee[type][duration]);
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
		changetype();
		break;
	case 2:
		changedate();
		break;
	case 3:
	default:
		printf("Invalid Menu\n");
		break;
	}
}

void changetype()
{
	int choice;
	printf("choose ticket type that you want to chane\n");
	printf("1. Opened area\n");
	printf("2. Covered area\n");
	printf("3. Designated\n");
	scanf("%d", &choice);

	printf("%d\n", choice);
	switch (choice) {
	case 1:
		open();
		break;
	case 2:
		covered();
		break;
	case 3:
		designated();
		break;
	case 4:
	default:
		printf("Invalid Menu\n");
		break;
	}
	if (choice == 1)
	{
		printf("choose the duration :\n");
		printf("1. per hour\n");
		printf("2. per day\n");
		printf("3. per month\n");
	}
	else if (choice == 2)
	{
		printf("choose the duration :\n");
		printf("1. per hour\n");
		printf("2. per day\n");
		printf("3. per month\n");
	}
	else if (choice == 3)
	{
		printf("choose the duration :\n");
		printf("1. per hour\n");
		printf("2. per day\n");
		printf("3. per month\n");
	}
}

void changedate()
{
	int Date;
	int month;
	int year;
		printf("Enter ticket's date : \n)");
	scanf("%d-%d-%d", &Date, &month, &year);
	printf("Enter the updated date : \n");
	scanf("%d-%d-%d", &Date, &month, &year);

}

void cancel()
{
	printf("1. Cancel ticket\n");

}
void check()
{

}