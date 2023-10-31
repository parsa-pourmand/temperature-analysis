#include <stdio.h>
//Defining the function that gets the day number and one pointer for the month number as input and returning the day number in the month. 
int date(int day, int *month_number){
	int day_of_month;
	
	if(day<=31){
		*month_number = 0;
		day_of_month = day;
	}else if(day<=60){
		*month_number = 1;
		day_of_month = day-31;
	}else if(day<=91){
		*month_number = 2;
		day_of_month = day-60;
	}else if(day<=121){
		*month_number = 3;
		day_of_month = day-91;
	}else if(day<=152){
		*month_number = 4;
		day_of_month = day-121;
	}else if(day<=182){
		*month_number = 5;
		day_of_month = day-152;
	}else if(day<=213){
		*month_number = 6;
		day_of_month = day-182;
	}else if(day<=244){
		*month_number = 7;
		day_of_month = day-213;
	}else if(day<=274){
		*month_number = 8;
		day_of_month = day-244;
	}else if(day<=305){
		*month_number = 9;
		day_of_month = day-274;
	}else if(day<=335){
		*month_number = 10;
		day_of_month = day-305;
	}else if(day<=366){
		*month_number = 11;
		day_of_month = day-335;
	}
	return(day_of_month);
}
//Difining the function for the summer average of each lake.
//It takes the "lakes" array and the lake number(we have 6 lakes) as input and returns the summer average of that lake. 
double average_summer(double array[366][6], int k){
	double sum=0;
	double average;
	int i =0;
//The summer is from day 172 to 265.
	for(i=172;i<=265;i++){
		sum = sum + array[i][k];
		}
//There is a total of 93 days.
		average = sum/93;
		
	return(average);
}
//Defining the function for the yearly average of temperature for each lake. It is basically the same as the summer and winter function.
//It also takes the number of days we need as input.(366 or 365)
//The only difference is that it is for all j days.
double yearly_average(double array[366][6], int k, int j){
	double sum = 0;
	double average;
	int i = 0;
	for(i=0;i<j;i++){
		sum = sum + array[i][k];
	}
		average = sum/j;
		return(average);
}
//Defining the winter function and it is basically the same as the functions for summer and yearly average.
//The winter is fro days 1 to 79 and 355 to 366.	
double average_winter(double array[366][6], int k){
	double sum=0;
	double average;
	int i =0;
	for(i=1;i<=79;i++){
		sum = sum + array[i][k];
	}
	for(i=355;i<=366;i++){
		sum = sum + array[i][k];
	}
//The total of 90 days.
		average = sum/90;
		
	return(average);
	}
//Defining the swim function for part 7. The inputs are the same as the functions for averages. 
//It has a counter "j" and each time the temperature is greater than 20, it adds one to "j".
//Finally it returns "j".	
int swim(double array[366][6], int k){
	int i=0;
	int j=0;
	for(i=0;i<366;i++){
		if(array[i][k]>20){
			j = j+1;
		}
	}
	return(j);
}
//The frozen function for part 8. It is basically the same as the swim function and finally returns "j".
int frozen(double array[366][6], int k){
	int i=0;
	int j=0;
	for(i=0;i<366;i++){
		if(array[i][k]<0){
			j = j+1;
		}
	}
	return(j);
}

int main(void){
//All the values of temperatures for each lake is storing in this array from the file. It contains 366 rows for each day and 6 coloumns for each lake.	
	double lakes[366][6];
	double lakes_2019[365][6];
//counters i and j for the loops.
	int i=0; int m = 0;
	int j=0; int l = 0;
//two variables temp1 and temp2 that are used as temporarily for sorting the arrays.
	double temp1, temp2;
//The year number and day number, reading from the file, is storing in these two variables.
	int year;
	int day;
//This array is for part 3 and the values of daily temperatures for each lake stores in this array.
//the first coloumn contains temperatures and second one contains the day number.
	double warmest_temp[366][2];
//These two variables are for part 4 and the values for warmest and coldest average for all lakes combined stores in these variables.
	double warmest_average, coldest_average;
	double sum =0;
//these varibles are for part 1&9 and the value of the overall yearly average for all lakes stores in these variables for 2020 and 2019.
	double overall_average;
	double overall_average_2019;
//These two variables are for parts 5 and 6 and store the number of the lake each time so we can find the name of the lake in lake_name array.
	int lake_number_summer, lake_number_winter;
//These arrays contains the yearly average of all 6 lakes for 2020 and 2019.
	double average_of_year[6];
	double average_of_2019[6];
//These two arrays are for parts 5 and 6. They are used for sorting and they containg the lake number and the summer or winter average for that lake.
	double average_summer_temp[6][2];
	double average_winter_temp[6][2];
//Temprarily variables
	double _temp1;
	int  _temp2, _temp3;
//These two variables are for part 4.
//The date_day_warmest stores the day number(result of day function) and the date_month_number stores the month number(one of the arguments of date function as pointer).
	int date_day_warmest, date_month_warmest;
	int lake_index;
//array for name of the lakes.
	char lake_name[6][20] = {"Superior","Michigan","Huron","Erie","Ontario","St. Clair" };
//array for name of the monthes.
	char months [12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//Reading from the file for 2020 datas.	
	FILE *data;
	data = fopen("data.txt", "r");
	for(j=0;j<366;j++){
		fscanf(data, "%d", &year);
		fscanf(data, "%d", &day);
		for(i=0;i<6;i++){
			fscanf(data, " %lf", &lakes[j][i]);
		}
	}
	fclose(data);
//Reading from the file for 2019 datas.	
	FILE *data_2019;
	data_2019 = fopen("data2019.txt", "r");
	for(j=0;j<365;j++){
		fscanf(data_2019, "%d", &year);
		fscanf(data_2019, "%d", &day);
		for(i=0;i<6;i++){
			fscanf(data_2019, " %lf", &lakes_2019[j][i]);
		}
	}
	fclose(data_2019);
//***********Part 1*************
	printf("\n");
	printf("Name of the Lake                     Average Yearly Temperature\n");
	sum = 0;
//storing the results of the yearly average function for all 6 lakes(since it is inside the loop) into an array.
	for(i=0;i<6;i++){
	    average_of_year[i] = yearly_average(lakes, i, 366);
		printf("  %-20s\t%30.3lf\n", lake_name[i], average_of_year[i]);
		sum = sum + average_of_year[i];
	}
//finding the overall yearly average of all 6 years.
	overall_average = sum/6;
	printf("\n");
	printf("The overall average of the temperature of all lakes is: %.3lf\n", overall_average);
	
//***********Part 2*************
	printf("\n");
	printf("Name of the lakes with average temperature above the overall average: \n");
for(i=0;i<6;i++){
	if(average_of_year[i]>overall_average){
		printf("      %s\n", lake_name[i]);
	}
}
	printf("Name of the lakes with average temperature below the overall average: \n");
for(i=0;i<6;i++){
	if(average_of_year[i]<overall_average){
		printf("      %s\n", lake_name[i]);
	}
}
	
	warmest_average = average_of_year[0];
	lake_index = 0;
for(i=0;i<6;i++){
	if(average_of_year[i] > warmest_average){
		warmest_average = average_of_year[i];
		lake_index = i;	
	}
}
	printf("\n");
	printf("The warmest lake based on yearly average temperature is: %s\n", lake_name[lake_index]);
	
	coldest_average = average_of_year[0];
	lake_index = 0;
for(i=0;i<6;i++){
	if(average_of_year[i] < coldest_average){
		coldest_average = average_of_year[i];	
		lake_index = i;
	}
}
	printf("The coldest lake based on yearly average temperature is: %s\n", lake_name[lake_index]);
	
//*********Part 3************
//in this part, we store the temperature for all days, each time for one lake, in warmest_temp array.
//The first coloumn contains the day number and the second one contains the temperature.
	printf("\n");
	for(i=0;i<6;i++){
		for(j=0;j<366;j++){
			warmest_temp[j][1] = lakes[j][i];
			warmest_temp[j][0] = j+1;
		}
//In these two for-loops we sort the temperatures from warmest two coldest.
	for(m=0;m<366;m++){
		for(l=0;l<366;l++){
			if(warmest_temp[l][1]<warmest_temp[m][1]){
				temp1 = warmest_temp[m][1];
				temp2 = warmest_temp[m][0];
				warmest_temp[m][1] = warmest_temp[l][1];
				warmest_temp[m][0] = warmest_temp[l][0];
				warmest_temp[l][1] = temp1;
				warmest_temp[l][0] = temp2;
			}
		}
	}
//After sorting, the first one is the warmest so we store the value of the first element in _temp1 variable.
		m=0;
		_temp1 = warmest_temp[0][1];
//In this do-while loop, we go down from top and each time the value is equal to the top value(warmest one), we print the value.
		do {
			date_day_warmest = date(warmest_temp[m][0], &date_month_warmest);
			printf("The warmest temperature for the lake %s is %.3lf on %s %dth\n", lake_name[i], _temp1, months[date_month_warmest], date_day_warmest);
			m++;
		}
		while (warmest_temp[m][1]==_temp1);
		printf("\n");
//Here we initilize the value of _temp1 variable angain to the lowest element, which is the coldest one after sorting.
		m=365;
		_temp1 = warmest_temp[365][1];
//In this loop, we go up from down and each time the temperature is equal to the lowest one(coldest temperature) we print the value.
		do{
			date_day_warmest = date(warmest_temp[m][0], &date_month_warmest);
			printf("The coldest temperature for the lake %s is %.3lf on %s %dth\n", lake_name[i], _temp1, months[date_month_warmest], date_day_warmest);
			m--; 
		}
		while (warmest_temp[m][1]==_temp1);	
		printf("\n");
	
	}
	
//************part 4*************
//This part is basically the same as part 3, except it is for all lakes combined.
//Since it is for all lakes combined, we store the temperatures in larger array: 366x6 = 2196
//The first coloumn contains the day number, the second one contains the lake number and the third one contains the temperatures.
	double sorted_lakes[2196][3];
	for(i=0;i<6;i++){
		for(j=0;j<366;j++){
			sorted_lakes[j+i*366][0]=j;
			sorted_lakes[j+i*366][1]=i;
			sorted_lakes[j+i*366][2]=lakes[j][i];
		}
	}
	
//Here we sort the temperature of all lakes combined from warmest to coldest.
	for(j=0;j<2196;j++){
		for(i=0;i<2196;i++){
			if(sorted_lakes[i][2]<sorted_lakes[j][2]){
				_temp1 = sorted_lakes[j][2];
				_temp2 = sorted_lakes[j][1];
				_temp3 = sorted_lakes[j][0];
				sorted_lakes[j][2] = sorted_lakes[i][2];
				sorted_lakes[j][1] = sorted_lakes[i][1];
				sorted_lakes[j][0] = sorted_lakes[i][0];
				sorted_lakes[i][2] = _temp1;
				sorted_lakes[i][1] = _temp2;
				sorted_lakes[i][0] = _temp3;
			}
		}
	}
//Here we basically do the same thing as explained in step 3.
	i=0;
	_temp1 = sorted_lakes[0][2];
	do {
		date_day_warmest = date(sorted_lakes[i][0]+1, &date_month_warmest);
		lake_index = sorted_lakes[i][1];
		printf("The overall warmest water temperature (all lakes combined) is: %.3lf, on %s %dth and it temperature belongs to the lake %s\n", sorted_lakes[i][2], months[date_month_warmest], date_day_warmest, lake_name[lake_index]);
		i++;
	}
	while (sorted_lakes[i][2]==_temp1);
	i=2195;
	_temp1 = sorted_lakes[2195][2];
	do {
		date_day_warmest = date(sorted_lakes[i][0]+1, &date_month_warmest);
		lake_index = sorted_lakes[i][1];
		printf("The overall coldest water temperature (all lakes combined) is: %.3lf, on %s %dth and it temperature belongs to the lake %s\n", sorted_lakes[i][2], months[date_month_warmest], date_day_warmest, lake_name[lake_index]);
		i--;
	}
	while (sorted_lakes[i][2]==_temp1);

	printf("\n");
	//************Part 5*************
	
	for(i=0;i<6;i++){
		average_summer_temp[i][0] = i;
		average_summer_temp[i][1] = average_summer(lakes, i);
	}
	for(j=0;j<6;j++){
		for(i=0;i<6;i++){
			if(average_summer_temp[i][1]<average_summer_temp[j][1]){
				temp1 = average_summer_temp[j][1];
				temp2 = average_summer_temp[j][0];
				average_summer_temp[j][1] = average_summer_temp[i][1];
				average_summer_temp[j][0] = average_summer_temp[i][0];
				average_summer_temp[i][1] = temp1;
				average_summer_temp[i][0] = temp2;
			}
		}
	}

	printf("Name of the Lake                  Average Temperature for Summer\n");
	for(i=0;i<6;i++){
		lake_number_summer = average_summer_temp[i][0];
		printf("  %-20s\t%30.3lf\n", lake_name[lake_number_summer], average_summer_temp[i][1]);
	}
	
	printf("\n");
	//**********part 6**********
	for(i=0;i<6;i++){
		average_winter_temp[i][0] = i;
		average_winter_temp[i][1] = average_winter(lakes, i);
	}
	
	for(j=0;j<6;j++){
		for(i=0;i<6;i++){
			if(average_winter_temp[i][1]<average_winter_temp[j][1]){
				temp1 = average_winter_temp[j][1];
				temp2 = average_winter_temp[j][0];
				average_winter_temp[j][1] = average_winter_temp[i][1];
				average_winter_temp[j][0] = average_winter_temp[i][0];
				average_winter_temp[i][1] = temp1;
				average_winter_temp[i][0] = temp2;
			}
		}
	}
	
	printf("Name of the Lake                  Average Temperature for Winter\n");
	for(i=0;i<6;i++){
		lake_number_winter = average_winter_temp[i][0];
		printf("  %-20s\t%30.3lf\n", lake_name[lake_number_winter], average_winter_temp[i][1]);
	}
	
//********Part 7*********
	printf("\n");
	printf("Name of the lake                    The Number of day we can swim\n");
	for(i=0;i<6;i++){
		printf("   %-20s\t%30d\n", lake_name[i], swim(lakes, i));
	}
//**********Part 8**********
	printf("\n");
	printf("Name of the lake                    The Number of day the lake is frozen\n");
	for(i=0;i<6;i++){
		printf("   %-20s\t%30d\n", lake_name[i], frozen(lakes, i));
	}
//********Part 9*********

printf("\n");
	printf("Name of the Lake                  Average Yearly Temperature(2020)                    Average Yearly Temperature(2019)\n");
	sum = 0;
	for(i=0;i<6;i++){
	    average_of_2019[i] = yearly_average(lakes, i, 365);
		printf("  %-20s\t%30.3lf%50.3lf\n", lake_name[i], average_of_year[i], average_of_2019[i]);
		sum = sum + average_of_2019[i];
	}
	overall_average_2019 = sum/6;
	printf("\n");
	printf("  Overall average       %30.3lf%50.3lf\n", overall_average, overall_average_2019);
	
	return(0);
}
