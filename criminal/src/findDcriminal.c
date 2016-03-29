#include <stdio.h>
#include <stdbool.h>

#define TRUE  1
#define FALSE 0

#define PERSON_NAME_LEN 50

typedef struct person {
	char name[PERSON_NAME_LEN];	
	bool isCriminal;		
} person_t;

int main()
{
	person_t person[4] = {{"A",FALSE}, {"B",FALSE}, {"C",FALSE}, {"D",FALSE}};

	int i = 0, j = 0;

	for (i = 0; i< 4; i++)
	{
		person[i].isCriminal = TRUE;

		bool conditions[4] = {	person[1].isCriminal || person[2].isCriminal || person[3].isCriminal,
					!person[1].isCriminal && person[2].isCriminal,
					person[0].isCriminal || person[3].isCriminal,
					!person[1].isCriminal && person[2].isCriminal	};

		int counter = 0;

		for (j = 0; j < 4; j++)
		{
			if (conditions[j])
			{
				counter ++;	
			}
		}

		if (counter == 2)
		{
			printf("%s is criminal.\n", person[i].name);
			break;
		}

		person[i].isCriminal = FALSE;
	}
	
	return 0;
}
