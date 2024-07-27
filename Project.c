#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_PTR ((void*)0)

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------

//structure

typedef struct Patient {
    char name[50];
    u8 age;
    char gender[10];
    u32 ID;
    struct Patient *next;
} Patient;

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------

// Function declarations

Patient* create_patient(char name[], u8 age, char gender[], u32 ID);
Patient* add_patient(char name[], u8 age, char gender[], u32 ID, Patient* PrePatient);
void Del_a_Patient_in_med(Patient* PrePatient);
void print_patient(Patient* PatientAddress);
Patient* find_patient(Patient* head, u32 ID);

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------

// Functions

Patient* create_patient(char name[], u8 age, char gender[], u32 ID) {
    Patient *NewPatient = (Patient*)malloc(sizeof(Patient));
    if (NewPatient == NULL_PTR) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(NewPatient->name, name);
    NewPatient->age = age;
    strcpy(NewPatient->gender, gender);
    NewPatient->ID = ID;
    NewPatient->next = NULL_PTR;
    return NewPatient;
}
//--------------------------------------------------------------------------------------
Patient* add_patient(char name[], u8 age, char gender[], u32 ID, Patient* PrePatient) {
    Patient *NewPatient = (Patient*)malloc(sizeof(Patient));
    if (NewPatient == NULL_PTR) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(NewPatient->name, name);
    NewPatient->age = age;
    strcpy(NewPatient->gender, gender);
    NewPatient->ID = ID;
    NewPatient->next = NULL_PTR;
    PrePatient->next = NewPatient;
    return NewPatient;
}
//--------------------------------------------------------------------------------------
void Del_a_Patient_in_med(Patient* PrePatient) {
    if (PrePatient->next == NULL_PTR) {
        printf("There is no Patient to delete\n");
        return;
    }
    Patient* TempPatient = PrePatient->next;
    PrePatient->next = TempPatient->next;
    free(TempPatient);
}
//--------------------------------------------------------------------------------------
void print_patient(Patient* PatientAddress) {
    if (PatientAddress == NULL_PTR) {
        printf("Patient does not exist\n");
    } else {
        printf("The name of this Patient   = %s\n", PatientAddress->name);
        printf("The age of this Patient    = %u\n", PatientAddress->age);
        printf("The gender of this Patient = %s\n", PatientAddress->gender);
        printf("The ID of this Patient     = %u\n", PatientAddress->ID);
    }
}
//--------------------------------------------------------------------------------------
Patient* find_patient(Patient* head, u32 ID) {
    Patient* current = head;
    while (current != NULL_PTR) {
        if (current->ID == ID) {
            return current;
        }
        current = current->next;
    }
    return NULL_PTR;
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------

//Main Function

int main() 
{
    u32 default_Password = 1234, password, PatientID;
    u8 mode, adminModeFeature, userModeFeature, k, slot;
    char NAME[50];
    u8 AGE;
    char GENDER[10];
    u32 ID_ENTERED;

    Patient *Patient_1 = create_patient("Ahmed", 20, "male", 111111);
    Patient *Patient_2 = add_patient("Salwa", 25, "female", 222222, Patient_1);

    Patient *head = Patient_1;
    Patient *last = Patient_2;

    u32 Slots[5] = {Patient_1->ID, Patient_2->ID, 0, 0, 0};
	
	u8 continuee = 1;
	char c[10];
	
	while(continuee == 1)
	{
		printf("\n");
		
		printf("write ( 1 ) if you wanna enter the Admin mode  \n");
		printf("write ( 2 ) if you wanna enter the User mode  \n");
		printf("enter the number: ");
		scanf("%hhu", &mode);
		printf("\n");

		if (mode == 1) {
			printf("enter the password: ");
			scanf("%u", &password);
			printf("\n");

			int attempts = 2;
			while (attempts--) {
				if (password == default_Password) {
					
					//printf("\n");
					printf("write ( 1 ) if you wanna Add new patient record  \n");
					printf("write ( 2 ) if you wanna edit patient record  \n");
					printf("write ( 3 ) if you wanna reserve a slot with the doctor  \n");
					printf("write ( 4 ) if you wanna cancel reservation  \n");
					printf("write ( 5 ) if you wanna return  \n");
					
					printf("enter a number: ");
					scanf("%hhu", &adminModeFeature);
					printf("\n");

					if (adminModeFeature == 1) {
						printf("name: ");
						scanf("%s", NAME);
						printf("\n");

						printf("age: ");
						scanf("%hhu", &AGE);
						printf("\n");

						printf("gender: ");
						scanf("%s", GENDER);
						printf("\n");

						printf("enter the patient ID: ");
						scanf("%u", &ID_ENTERED);
						printf("\n");

						if (find_patient(head, ID_ENTERED) != NULL_PTR) {
							printf("This ID exists already.\n");
							continue;
						} else {
							last = add_patient(NAME, AGE, GENDER, ID_ENTERED, last);
							
						}

					} 
					//----------------------------------------------------------------------------------
					else if (adminModeFeature == 2) {
						printf("enter the patient ID: ");
						scanf("%u", &PatientID);
						printf("\n");

						Patient* patient = find_patient(head, PatientID);
						if (patient != NULL_PTR) {
							print_patient(patient);
							
							printf("\n");
							printf("write ( 1 ) for editing the name  \n");
							printf("write ( 2 ) for editing the age  \n");
							printf("write ( 3 ) for editing the gender  \n");
							printf("write ( 4 ) for editing the ID  \n");
							printf("write ( 5 ) for returning  \n");
							
							printf("enter a number: ");
							scanf("%hhu", &k);
							printf("\n");

							if (k == 1) {
								printf("name: ");
								scanf("%s", NAME);
								printf("\n");
								
								strcpy(patient->name, NAME);
							} else if (k == 2) {
								printf("age: ");
								scanf("%hhu", &AGE);
								printf("\n");
								
								patient->age = AGE;
							} else if (k == 3) {
								printf("gender: ");
								scanf("%s", GENDER);
								printf("\n");
								
								strcpy(patient->gender, GENDER);
							} else if (k == 4) {
								printf("enter the patient ID: ");
								scanf("%u", &ID_ENTERED);
								printf("\n");
								
								patient->ID = ID_ENTERED;
							} else {
								continue;
							}

							print_patient(patient);
						} else {
							printf("This ID does not exist.\n");
							continue;
						}

					} 
					//----------------------------------------------------------------------------------
					else if (adminModeFeature == 3) {
						for (u8 i = 0; i < 5; i++) {
							if (Slots[i] != 0) {
								printf("slot-%u: %u\n", i + 1, Slots[i]);
							} else {
								printf("slot-%u: Empty\n", i + 1);
							}
						}

						printf("enter the patient ID: ");
						scanf("%u", &PatientID);
						printf("\n");

						Patient* patient = find_patient(head, PatientID);
						if (patient != NULL_PTR) {
							printf("enter an empty slot: ");
							scanf("%hhu", &slot);
							printf("\n");
							if (slot >= 1 && slot <= 5 && Slots[slot - 1] == 0) {
								Slots[slot - 1] = PatientID;
							} else {
								printf("Not empty or invalid slot.\n");
								continue;
							}
						} else {
							printf("This ID does not exist.\n");
							continue;
						}

					} 
					//----------------------------------------------------------------------------------
					else if (adminModeFeature == 4) {
						for (u8 i = 0; i < 5; i++) {
							if (Slots[i] != 0) {
								printf("slot-%u: %u\n", i + 1, Slots[i]);
							} else {
								printf("slot-%u: Empty\n", i + 1);
							}
						}

						printf("enter the patient ID: ");
						scanf("%u", &PatientID);

						Patient* patient = find_patient(head, PatientID);
						if (patient != NULL_PTR) {
							printf("enter a non-empty slot: ");
							scanf("%hhu", &slot);
							if (slot >= 1 && slot <= 5 && Slots[slot - 1] == PatientID) {
								Slots[slot - 1] = 0;
							} else {
								printf("It's an empty slot or invalid slot.\n");
								continue;
							}
						} else {
							printf("This ID does not exist.\n");
							continue;
						}

					}
					//----------------------------------------------------------------------------------
					else if (adminModeFeature == 5) {
						
						break;
					}

					
					
				} else {
					printf("Wrong password. Try again.\n \
							enter the password: ");
					scanf("%u", &password);
				}
			}
			
			if(password != default_Password) printf("Too many wrong attempts. Exiting.\n");
		} 
		//----------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------
		else if (mode == 2) {
			printf("write ( 1 ) if you wanna view patient record 		 \n");
			printf("write ( 2 ) if you wanna view today's reservations   \n");
			printf("write ( 3 ) for returning  \n");
			printf("enter a number: ");
			scanf("%hhu", &userModeFeature);  
			printf("\n");

			if (userModeFeature == 1) {
				printf("enter the patient ID: ");
				scanf("%u", &PatientID); 

				Patient *PATIENT = find_patient(head, PatientID); 
				if (PATIENT != NULL_PTR) {
					print_patient(PATIENT);
				} else {
					printf("This ID does not exist in the list.\n");
					continue;
				}

			} else if (userModeFeature == 2) {
				for (u8 i = 0; i < 5; i++) {
					if (Slots[i] != 0) {
						printf("slot-%u: %u\n", i + 1, Slots[i]);  
					} else {
						printf("slot-%u: Empty\n", i + 1);
					}
				}

			} else if (adminModeFeature == 3) {
						
						break;
			}
		}
		//----------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------
		else {
			printf("Invalid mode selected. Exiting.\n");
		}
		
		printf("\n");
		printf("do you wanna continue?? Write (yes/no): ");
		scanf("%s", c);
		printf("\n");
		
		if(strcmp(c, "no") == 0) continuee=0;
		
	}
    return 0;
}
//.
//..
//...
//....
//end of the Project
