#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hospital_information {
	char firstname[12];
	int lastname[12];
	int age;
	char gender[7];
	int date[3];
	int ID;
	char status[10];
} patient[5];

// Number of patients
int i = 0;

int main()
{
	int ID = 007;
	int hospital;
	
	isiaqs_hospital:
	
	system("cls");
	printf("1.Create patient\n"
	"2.Display patients\n"
	"3.Change patient admission\n"
	"4.Search patients\n"
	"5.Filter patients\n"
	"6.Exit\n");
	
	printf("CHOICE: ");
	scanf("%d", &hospital);
	
	
	// Conditions
	
	switch (hospital)
	{
		stage_one:
		case 1:
			system("cls");
			printf("Create patient data\n");
			printf("Input firstname: ");
			scanf("%s", &patient[i].firstname);
			printf("Input lastname: ");
			scanf("%s", &patient[i].lastname);
			printf("Input age: ");
			scanf("%d", &patient[i].age);
			printf("Input gender: ");
			scanf("%s", &patient[i].gender);
			printf("Input date (d m y): ");
			scanf("%d %d %d", &patient[i].date[0], &patient[i].date[1], &patient[i].date[2]);
			patient[i].ID = ID;
			printf("ID NUMBER: %d", patient[i].ID);
			strcpy(patient[i].status, "admitted");
			i++;
			ID++;
			
			char reply[4];
			printf("\nRegister another patient? yes/no\n");
			scanf("%s", &reply);
			
			if (strcmp(reply, "yes") == 0) goto stage_one;
			
			// Ask if you want to see the menu
			char response[4];
			printf("Would you like to see the menu again?\n");
			scanf("%s", &response);
			
			if (strcmp(response, "yes") == 0) goto isiaqs_hospital;
			else return 0;
			break;
			
		case 2:
		{
			system("cls");
			int j;
			printf("Firstname\tLastname\tAge\tGender\t\tDate\t\tID\n");
			for (j = 0; j<i; j++)
			{
				if (strcmp(patient[j].status, "admitted") == 0) {
					printf("%s\t\t%s\t\t%d\t%s\t\t%d %d %d\t%d\n",
					patient[j].firstname,
					patient[j].lastname,
					patient[j].age,
					patient[j].gender,
					patient[j].date[0], patient[j].date[1], patient[j].date[2],
					patient[j].ID
					);
				}
			}
			
			// Ask if you want to see the menu
			char response[4];
			printf("Would you like to see the menu again?\n");
			scanf("%s", &response);
			
			if (strcmp(response, "yes") == 0) goto isiaqs_hospital;
			else return 0;
		}
		break;
		case 3:
		{
			system("cls");
			char name_HOUSE[12];
			printf("Enter patient's name\n");
			scanf("%s", &name_HOUSE);
			int j;
			for (j = 0; j<i; j++){
				if (strcmp(patient[j].firstname, name_HOUSE) == 0) {
					// Change status from admitted to discharged.
					strcpy(patient[j].status, "discharged");
					break;
				}
			}
			printf("%s's status has been changed to 'discharged'.\n", name_HOUSE);
			
			char response[4];
			printf("Would you like to see the menu again?\n");
			scanf("%s", &response);
			
			if (strcmp(response, "yes") == 0) goto isiaqs_hospital;
			else return 0;
		}
			break;
			
		case 4:
		{
			system("cls");
			char answer[5];
			// ask to search by name or ID
			// ID:
			// go through the array
			// check for the patient with the ID the user needs
			// and print the patient
			
			printf("search by name or ID\n");
			scanf("%s", &answer);
			if (strcmp(answer, "name") == 0) {
			char name_HOUSE[12];
			printf("enter first name\n");
			scanf("%s", &name_HOUSE);
			int j;
			for (j = 0; j<i; j++){
				if ((strcmp(patient[j].firstname, name_HOUSE) == 0)
					&& (strcmp(patient[j].status, "admitted") == 0)) {
					printf("%s\t\t%s\t\t%d\t%s\t\t%d %d %d\t%d\n",
					patient[j].firstname,
					patient[j].lastname,
					patient[j].age,
					patient[j].gender,
					patient[j].date[0], patient[j].date[1], patient[j].date[2],
					patient[j].ID
					);
				}
			}
			}
			else if (strcmp(answer, "ID") == 0) {
				//...
			}
			
			char response[4];
			printf("Would you like to see the menu again?\n");
			scanf("%s", &response);
			
			if (strcmp(response, "yes") == 0) goto isiaqs_hospital;
			else return 0;
		}
			break;
		case 5:
		{
			system ("cls");
			// Ask to show male or female
			// If male:
			char gender[7];
			int j;
			printf("Choose gender\n");
			scanf("%s", gender);
			printf("Firstname\tLastname\tAge\tGender\t\tDate\t\tID\n");
			for (j = 0; j<i; j++);
			{
				if ((strcmp(gender, "male") == 0)
					&& (strcmp(patient[j].status, "admitted") == 0)
					&& strcmp(patient[j].gender, "male") == 0) {
					printf("%s\t\t%s\t\t%d\t%s\t\t%d %d %d\t%d\n",
					patient[j].firstname,
					patient[j].lastname,
					patient[j].age,
					patient[j].gender,
					patient[j].date[0], patient[j].date[1], patient[j].date[2],
					patient[j].ID
					);
				}
					
				if ((strcmp(gender, "female") == 0)
					&& (strcmp(patient[j].status, "admitted") == 0)
					&& strcmp(patient[j].gender, "female") == 0) {
					printf("%s\t\t%s\t\t%d\t%s\t\t%d %d %d\t%d\n",
					patient[j].firstname,
					patient[j].lastname,
					patient[j].age,
					patient[j].gender,
					patient[j].date[0], patient[j].date[1], patient[j].date[2],
					patient[j].ID);
				}
			}
			
			char response[4];
			printf("Would you like to see the menu again?\n");
			scanf("%s", &response);
			
			if (strcmp(response, "yes") == 0) goto isiaqs_hospital;
			else return 0;
		}
	}
	
	return 0;
}

