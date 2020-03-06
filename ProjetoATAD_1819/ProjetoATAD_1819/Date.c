#include "Date.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

Date createDate(unsigned int day, unsigned int month, unsigned int year) {
	Date newDate;

	newDate.day = day;

	newDate.month = month;

	newDate.year = year;

	return newDate;
}

void datePrint(PtDate _this) {
	printf("%02d/%02d/%02d \n", _this->day, _this->month, _this->year);
}










int calculateAge( Date birthdate,Date date)
{
	/*if (!valid_date(birthdate.day, birthdate.month, birthdate.year))
	{
		printf("First date is invalid.\n");
	}

	if (!valid_date(date.day, date.month, date.year))
	{
		printf("Second date is invalid.\n");
		exit(0);
	}*/

	if (date.day < birthdate.day)
	{
		// borrow days from february
		if (date.month == 3)
		{
			//  check whether year is a leap year
			if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
			{
				date.day += 29;
			}

			else
			{
				date.day += 28;
			}
		}

		// borrow days from April or June or September or November
		else if (date.month == 5 || date.month == 7 || date.month == 10 || date.month == 12)
		{
			date.day += 30;
		}

		// borrow days from Jan or Mar or May or July or Aug or Oct or Dec
		else
		{
			date.day += 31;
		}

		date.month = date.month - 1;
	}

	if (date.month < birthdate.month)
	{
		date.month += 12;
		date.year -= 1;
	}

	int day_diff = date.day - birthdate.day;
	int mon_diff = date.month - birthdate.month;
	int year_diff = date.year - birthdate.year;

	//printf("Difference: %d years %02d months and %02d days.", year_diff, mon_diff, day_diff);

	return year_diff-1900; // return 0 to operating system


}

int valid_date(int day, int mon, int year)
{
	int is_valid = 1, is_leap = 0;

	if (year >= 1800 && year <= 9999)
	{

		//  check whether year is a leap year
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			is_leap = 1;
		}

		// check whether mon is between 1 and 12
		if (mon >= 1 && mon <= 12)
		{
			// check for days in feb
			if (mon == 2)
			{
				if (is_leap && day == 29)
				{
					is_valid = 1;
				}
				else if (day > 28)
				{
					is_valid = 0;
				}
			}

			// check for days in April, June, September and November
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			{
				if (day > 30)
				{
					is_valid = 0;
				}
			}

			// check for days in rest of the months 
			// i.e Jan, Mar, May, July, Aug, Oct, Dec
			else if (day > 31)
			{
				is_valid = 0;
			}
		}

		else
		{
			is_valid = 0;
		}

	}
	else
	{
		is_valid = 0;
	}

	return is_valid;

}