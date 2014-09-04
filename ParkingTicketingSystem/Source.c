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
static const int day[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const int month[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const int year[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


void buy();
void edit();
void cancel();
void check();


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
	printf("Purchase Ticket\n");
	printf("1. per hour\n");
	printf("2. per day\n");
	printf("3. per month\n");
	
	// switch
	perhour();
}

void perhour()
{

}
void edit()
{
	printf("1. Change ticket type\n");
	printf("2. Change ticket date\n");
}
void cancel()
{
	printf("1. Cancel ticket\n");

}
void check()
{

}