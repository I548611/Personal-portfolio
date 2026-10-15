#include "doseAdmin.h"
#define MEASUREMENTS_SIZE		10
#define HASH_TABLE_SIZE 		256
#define PATIENT_AMOUNT			100
#define MAX_PATIENT_CHARACTERS	3

typedef struct 
{
    char patientName[MAX_PATIENTNAME_SIZE];
    float dose [MEASUREMENTS_SIZE];
    Date examDate;
    int measurementCount[MEASUREMENTS_SIZE];
} Patient;

static Patient * hashTable[HASH_TABLE_SIZE][PATIENT_AMOUNT];

static uint8_t hashFunction(char patientName[MAX_PATIENTNAME_SIZE])
{
	uint32_t hash = 0;
	for (int i = 0; i < MAX_PATIENT_CHARACTERS && patientName[i] != '\0'; i++) 
	{
		hash = hash * 31 + patientName[i]; 
	}
	return (uint8_t)(hash % HASH_TABLE_SIZE);
}

void CreateHashTable()
{
	for (int i = 0; i < HASH_TABLE_SIZE; i++) 
    {
        for (int p = 0; p < PATIENT_AMOUNT; p++) 
        {
            hashTable[i][p] = NULL;
        }
    }
}
 
void RemoveAllDataFromHashTable()
{
	for (int i = 0; i < HASH_TABLE_SIZE; i++) 
    {
        for (int p = 0; p < PATIENT_AMOUNT; p++)
        {
            if (hashTable[i][p] != NULL) 
            {
                free(hashTable[i][p]);
                hashTable[i][p] = NULL;
            }
        }
    }
}
 
int8_t AddPatient(char patientName[MAX_PATIENTNAME_SIZE])
{
	// Checking string length
    size_t length = 0;
    while (patientName[length] != '\0' && length < MAX_PATIENTNAME_SIZE) length++;
    if (length >= MAX_PATIENTNAME_SIZE && patientName[length] != '\0') 
    {
        return -3; // Name too long
    }

    uint8_t hash = hashFunction(patientName);

    // Checking if patient already exists
    for (int i = 0; i < PATIENT_AMOUNT; i++) 
    {
        if (hashTable[hash][i] != NULL &&
            strncmp(hashTable[hash][i]->patientName, patientName, MAX_PATIENTNAME_SIZE) == 0) 
        {
            return -1; // Already present
        }
    }

    // Find empty slot in hash table
    for (int i = 0; i < PATIENT_AMOUNT; i++) 
    {
        if (hashTable[hash][i] == NULL) 
        {
            Patient* newPatient = (Patient*)malloc(sizeof(Patient));
            if (!newPatient) 
            {
                return -2; // no empty space found
            }
            memset(newPatient, 0, sizeof(Patient));
            strncpy(newPatient->patientName, patientName, MAX_PATIENTNAME_SIZE - 1);
            newPatient->patientName[MAX_PATIENTNAME_SIZE - 1] = '\0';
            hashTable[hash][i] = newPatient;
            return 0; // Success
        }
    }

	//no space left in hash table
    return -2;
}
 
int8_t AddPatientDose(char patientName[MAX_PATIENTNAME_SIZE], 
			          Date* date, uint16_t dose)
{
	 return -1;
}
 
int8_t PatientDoseInPeriod(char patientName[MAX_PATIENTNAME_SIZE], 
                           Date* startDate, Date* endDate, uint32_t* totalDose)
{
	 return -1;
}
 
// Brice:
// coding conventions:
//   -- split the code in functional functional blocks (for clarity)
//   -- explicitly use braces for all if, for, while statements (to avoid errors when modifying the code later on)
// You can take advantage of the C standard library (string.h) for string operations (strlen, strcmp, strncpy, ...)
// Explicitly use braces to indicate the order of operations
int8_t RemovePatient(char patientName[MAX_PATIENTNAME_SIZE])
{
	// Check string length
    size_t length = 0;
    while (patientName[length] != '\0' && length < MAX_PATIENTNAME_SIZE) 
    {
        length++;
    }

    if (length >= MAX_PATIENTNAME_SIZE && patientName[length] != '\0') 
    {
        return -2; // Name too long
    }

    uint8_t hash = hashFunction(patientName);
    for (int i = 0; i < PATIENT_AMOUNT; i++) 
    {
        if (hashTable[hash][i] != NULL && 
            strncmp(hashTable[hash][i]->patientName, patientName, MAX_PATIENTNAME_SIZE) == 0) 
        {
            free(hashTable[hash][i]);
            hashTable[hash][i] = NULL;
            return 0; // Success
        }
    }
    return -1; // Patient not found
}
 
int8_t IsPatientPresent(char patientName[MAX_PATIENTNAME_SIZE])
{
	// Check string length
    size_t length = 0;
    while (patientName[length] != '\0' && length < MAX_PATIENTNAME_SIZE) length++;
    if (length >= MAX_PATIENTNAME_SIZE && patientName[length] != '\0') 
    {
        return -2; // Name too long
    }

    uint8_t hash = hashFunction(patientName);
    for (int i = 0; i < PATIENT_AMOUNT; i++) 
    {
        if (hashTable[hash][i] != NULL && 
            strncmp(hashTable[hash][i]->patientName, patientName, MAX_PATIENTNAME_SIZE) == 0) 
        {
            return 0; // Patient present
        }
    }
    return -1; // Patient not present
}

int8_t GetNumberOfMeasurements(char patientName[MAX_PATIENTNAME_SIZE], 
                               size_t * nrOfMeasurements)
{
	 return -1;
}

void GetHashPerformance(size_t *totalNumberOfPatients, double *averageNumberOfPatients,
                        double *standardDeviation)
{
	 return;
}
				
int8_t WriteToFile(char filePath[MAX_FILEPATH_LEGTH])
{
	 return -1;
}

int8_t ReadFromFile(char filePath[MAX_FILEPATH_LEGTH])
{
	 return -1;
}
