#pragma once

typedef struct date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
} Date;

typedef Date* PtDate;

Date createDate(unsigned int day, unsigned int month, unsigned int year);
void datePrint(PtDate _this);

int valid_date(int day, int mon, int year);
int calculateAge(Date birthdate, Date date);
