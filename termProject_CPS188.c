#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*CPS188-W22 Term Project (3-member-group)
  Group 121 of Group-Formation Google Sheet
  Deep Patel, Ricky Rathod, Sanjot Khaira
  501090050, 501104462, 501104140             
  Section 7, Section 11, Section 8*/

int main(void) {

    groupInfo();
    //variable delcarations
   
    const char *tempName[6];
    int year2020[365]; int year2019[365];
    int temperature;
    double dayScan[365]; int day[365]; //organizing data variables
    int dayScan2019[364];
    int daysTotal, rows, sum, boolean;
    double dayScanSuperior[365]; double dayScanMichigan[365]; double dayScanHuron[365]; double dayScanErie[365]; double dayScanOntario[365]; double dayScanClair[365];
    double temp;
    double tieDates[365];
    int dayColdestSuperior, dayWarmestSuperior;
    int dayColdestMichigan, dayWarmestMichigan;
    int dayColdestHuron, dayWarmestHuron;
    int dayColdestErie, dayWarmestErie;
    int dayColdestOntario, dayWarmestOntario;
    int dayColdestClair, dayWarmestClair;
    double sumSuperior, sumMichigan, sumHuron, sumErie, sumOntario, sumClair, sumYearlyAverageTotal; 
    double sumSuperior2019=0, sumMichigan2019=0, sumHuron2019=0, sumErie2019=0, sumOntario2019=0, sumClair2019=0, sumYearlyAverageTotal2019;
    double lakeSuperior[365]; double lakeMichigan[365]; double lakeHuron[365]; double lakeErie[365]; double lakeOntario[365]; double lakeClair[365]; //setting arrays
    double lakeSuperiorDuplicate[365]; double lakeMichiganDuplicate[365]; double lakeHuronDuplicate[365]; double lakeErieDuplicate[365]; double lakeOntarioDuplicate[365]; double lakeClairDuplicate[365];
    double yearlyAverageSuperior, yearlyAverageMichigan, yearlyAverageHuron, yearlyAverageErie, yearlyAverageOntario, yearlyAverageClair, yearlyAverageTotal; //question 1
	double yearlyAverageSuperior2019, yearlyAverageMichigan2019, yearlyAverageHuron2019, yearlyAverageErie2019, yearlyAverageOntario2019, yearlyAverageClair2019, yearlyAverageTotal2019;
    double coldestLake, warmestLake;
    double hightempSuperior, lowtempSuperior, hightempMichigan, lowtempMichigan, hightempHuron, lowtempHuron, hightempErie, lowtempErie, hightempOntario, lowtempOntario, hightempClair, lowtempClair; //question 3
    double overallWarmest, overallColdest; //question 4
    double summerAverageSuperior, summerAverageMichigan, summerAverageHuron, summerAverageErie, summerAverageOntario, summerAverageClair; //question 5 
    double sumSummerAverageSuperior, sumSummerAverageMichigan, sumSummerAverageHuron, sumSummerAverageErie, sumSummerAverageOntario, sumSummerAverageClair;
    double winterAverageSuperior, winterAverageMichigan, winterAverageHuron, winterAverageErie, winterAverageOntario, winterAverageClair; //question 6
    double sumWinterAverageSuperior, sumWinterAverageMichigan, sumWinterAverageHuron, sumWinterAverageErie, sumWinterAverageOntario, sumWinterAverageClair;
    double sumWinterAverageSuperior2, sumWinterAverageMichigan2, sumWinterAverageHuron2, sumWinterAverageErie2, sumWinterAverageOntario2, sumWinterAverageClair2;
    double sumWinterAverageSuperiorTotal, sumWinterAverageMichiganTotal, sumWinterAverageHuronTotal, sumWinterAverageErieTotal, sumWinterAverageOntarioTotal, sumWinterAverageClairTotal;
	int swimDaysSuperior=0, swimDaysMichigan=0, swimDaysHuron=0, swimDaysErie=0, swimDaysOntario=0, swimDaysClair=0; //question 7
    int frozenDaysSuperior=0, frozenDaysMichigan=0, frozenDaysHuron=0, frozenDaysErie=0, frozenDaysOntario=0, frozenDaysClair=0; //question 8
    double lakeSuperior2019[364]; double lakeMichigan2019[364]; double lakeHuron2019[364]; double lakeErie2019[364]; double lakeOntario2019[364]; double lakeClair2019[364];
    double yearlyComparison2019[6], yearlyComparison2020[6];
    
    
    //file setup, specifically for READ purposes
    FILE*datafile = fopen("lakefile.TXT", "r"); 
    
	  while(!feof(datafile)) {            //reads every line and sorts columnar data into respective arrays for each lake
		  for(int i = 0; i < 366; i++) {  
			  fscanf(datafile, "%d%lf%lf%lf%lf%lf%lf%lf", &year2020[i], &dayScan[i], &lakeSuperior[i], &lakeMichigan[i], &lakeHuron[i], &lakeErie[i], &lakeOntario[i], &lakeClair[i]);
	    }
	  }
	  
	//copy arrays for summer and winter part 5 and 6
    arrayDuplication(lakeSuperior, lakeSuperiorDuplicate);
    arrayDuplication(lakeMichigan, lakeMichiganDuplicate);
    arrayDuplication(lakeHuron, lakeHuronDuplicate);
    arrayDuplication(lakeErie, lakeErieDuplicate);
    arrayDuplication(lakeOntario, lakeOntarioDuplicate);
    arrayDuplication(lakeClair, lakeClairDuplicate);
   
	dayScanDuplication(dayScan, dayScanSuperior);
	dayScanDuplication(dayScan, dayScanMichigan);
	dayScanDuplication(dayScan, dayScanHuron);
	dayScanDuplication(dayScan, dayScanErie);
	dayScanDuplication(dayScan, dayScanOntario);
	dayScanDuplication(dayScan, dayScanClair);
   
    //Part 1 --- Yearly average for each individual lake, and yearly average for all 6 together
    for(int i = 0; i < 366; i++) {
      sumSuperior = sumSuperior + lakeSuperior[i];
      yearlyAverageSuperior = sumSuperior/366;					//repeated process for summing all elements of data, and dividing by total elements for average
      yearlyComparison2020[0] = yearlyAverageSuperior;      //averages also placed in array for later comparision to 2019 data
    }
    for(int i = 0; i < 366; i++) {
      sumMichigan = sumMichigan + lakeMichigan[i];
      yearlyAverageMichigan = sumMichigan/366;
      yearlyComparison2020[1] = yearlyAverageMichigan; 
    }
    for(int i = 0; i < 366; i++) {
      sumHuron = sumHuron + lakeHuron[i];
      yearlyAverageHuron = sumHuron/366;
      yearlyComparison2020[2] = yearlyAverageHuron; 
    }
    for(int i = 0; i < 366; i++) {
      sumErie = sumErie + lakeErie[i];
      yearlyAverageErie = sumErie/366;
      yearlyComparison2020[3] = yearlyAverageErie; 
    }
    for(int i = 0; i < 366; i++) {
      sumOntario = sumOntario + lakeOntario[i];
      yearlyAverageOntario = sumOntario/366;
      yearlyComparison2020[4] = yearlyAverageOntario; 
    }
    for(int i = 0; i < 366; i++) {
      sumClair = sumClair + lakeClair[i];
      yearlyAverageClair = sumClair/366;
      yearlyComparison2020[5] = yearlyAverageClair; 
    }
    for(int i = 0; i < 6; i++) {
      sumYearlyAverageTotal = yearlyAverageSuperior + yearlyAverageMichigan + yearlyAverageHuron + yearlyAverageErie + yearlyAverageOntario + yearlyAverageClair;
      yearlyAverageTotal = sumYearlyAverageTotal/6;			//total average found for summing yearly averages and dividing by number of total elements
    }
   
    double sortYearlyAverageTotal[] = {yearlyAverageSuperior, yearlyAverageMichigan, yearlyAverageHuron, yearlyAverageErie, yearlyAverageOntario, yearlyAverageClair};
    const char *lakeNames[] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St. Clair"};
    
    while(1) {
      boolean = 0;
      for(int j = 0; j < 6-1; j++) {
        if(sortYearlyAverageTotal[j] > sortYearlyAverageTotal[j+1]) {  //sorts an array of yearly average temperatures, such that index 0 is coldest, index 5 is warmest
          temp = sortYearlyAverageTotal[j];
          sortYearlyAverageTotal[j] = sortYearlyAverageTotal[j+1];
          sortYearlyAverageTotal[j+1] = temp;
          tempName[j] = lakeNames[j];
          lakeNames[j] = lakeNames[j+1];
          lakeNames[j+1] = tempName[j];
        }
      }
      if(boolean == 0) {
        break;
      }
    }
   
	printf("Question 1\n");
    printf("The yearly average temperature of Lake Superior in degrees C is: %.2f\n", yearlyAverageSuperior);			//output for question 1
    printf("The yearly average temperature of Lake Michigan in degrees C is: %.2f\n", yearlyAverageMichigan);
    printf("The yearly average temperature of Lake Huron in degrees C is: %.2f\n", yearlyAverageHuron);
    printf("The yearly average temperature of Lake Erie in degrees C is: %.2f\n", yearlyAverageErie);
    printf("The yearly average temperature of Lake Ontario in degrees C is: %.2f\n", yearlyAverageOntario);
    printf("The yearly average temperature of Lake St.Clair in degrees C is: %.2f\n", yearlyAverageClair);
    printf("The yearly average temperature of all six lakes combined in degrees C is: %.2f\n\n", yearlyAverageTotal);
    printf("This data creates a warmest to coldest order of: %s, %s, %s, %s, %s, %s.\n", lakeNames[5], lakeNames[4], lakeNames[3], lakeNames[2], lakeNames[1], lakeNames[0]);
    printf("\n------------------------------------------------------------------------------\n\n");
    
    //Part 2 --- Which lake average is higher than total average of them all and lower as well. Order them warmest to coldest.
  
  
    coldestLake = sortYearlyAverageTotal[0];	//setting up for user display
    warmestLake = sortYearlyAverageTotal[5];
    double aboveAverage[6];		//declaring array strucutre for organzing averages below and above total average
    double belowAverage[6];
    
	for(int i = 0; i < 6; i++) {											//control statement, if temperature above average or below average, they go into respective arrays
		if(sortYearlyAverageTotal[i] > yearlyAverageTotal) {
			 aboveAverage[i] = sortYearlyAverageTotal[i];
		}
		if(sortYearlyAverageTotal[i] < yearlyAverageTotal) {
			belowAverage[i] = sortYearlyAverageTotal[i];
		}
	}
    
	printf("Question 2\n");		//figure out how to relate temp number of coldest to name of coldest, and same for warmest
	printf("The coldest lake, using average yearly temperature comparisions is: %.2f degrees of Lake Superior\n", coldestLake);  
	printf("The warmest lake, using average yearly temperature comparisions is: %.2f degrees of Lake Erie\n\n", warmestLake);
	printf("The combined yearly average is %.2f degrees C.", yearlyAverageTotal);
	

	
	printf("\nThe lakes temperatures above this average are: ");
	for(int i = 0; i < 6 ; i++) {
		if(aboveAverage[i] != 0) {								
			printf("%s", lakeNames[i]);
			if(i !=  5) {										//control statements to display information in a neat manner, with commas in between and period at end.
				printf(", ");
			}
		}
	}
	printf(".");
	
	printf("\n");
	printf("The lakes temperatures below this average are: ");
	for(int i= 0; i < 6;  i++) {
		if(belowAverage[i] != 0) {
			printf("%s", lakeNames[i]);			
			if(i !=  1) {								//same control implemented to neatly format the lake temperatures below the average
				printf(", ");
			}
		}
	}
	printf(".");
	printf("\n\n------------------------------------------------------------------------------\n");
	
    //Part 3 --- Each lake's highest and coldest temps are displayed along with exact date and temp
    
    printf("\nQuestion 3 (in Degrees C)\n\n");
    
	printf("Lake Superior: \n");
	sortLakeData(lakeSuperior, dayScanSuperior);
	printf("Lake Michigan: \n");
	sortLakeData(lakeMichigan, dayScanMichigan);		
	printf("Lake Huron: \n");				
	sortLakeData(lakeHuron, dayScanHuron);
	printf("Lake Erie: \n");				//sending to a function to sort lake data for highest and lowest temperature as well as finding the day 
	sortLakeData(lakeErie, dayScanErie);
	printf("Lake Ontario: \n");
	sortLakeData(lakeOntario, dayScanOntario);
	printf("Lake St. Clair: \n");
	sortLakeData(lakeClair, dayScanClair);

	printf("------------------------------------------------------------------------------\n");
	
    //Part 4 --- Overall warmest temp from all lake temps combined and print day/temp in same format as part 3. Do for overall coldest as well. If multiple, then mention all dates.
  
	printf("\nQuestion 4\nThe overall coldest belongs to Lake St. Clair, The overall warmest belongs to Lake Erie\nAll of their dates are shown below.\n\n");
	printf("Lake St. Clair: \n");
	allInstancesColdest(lakeClair, dayScanClair);
	printf("\nLake Erie: \n");
	allInstancesWarmest(lakeErie, dayScanErie);
	printf("\n------------------------------------------------------------------------------\n"); 

    //Part 5 --- Summer average is from day 127 to day 265. Seperate for each lake. Then display from warmest to coldest. State if order is same from part 2. 
  for(int i = 171; i <= 264; i++) {
      sumSummerAverageSuperior = sumSummerAverageSuperior + lakeSuperiorDuplicate[i];
      summerAverageSuperior = sumSummerAverageSuperior/94;														//same logic as question 1 however a specific range is averaged instead of entire data set for a specific lake
    }
  for(int i = 171; i <= 264; i++) {
      sumSummerAverageMichigan = sumSummerAverageMichigan + lakeMichiganDuplicate[i];
      summerAverageMichigan = sumSummerAverageMichigan/94;
    }
  for(int i = 171; i <= 264; i++) {
      sumSummerAverageHuron = sumSummerAverageHuron + lakeHuronDuplicate[i];
      summerAverageHuron = sumSummerAverageHuron/94;															//done once for each of the six lakes
    }
  for(int i = 171; i <= 264; i++) {
      sumSummerAverageErie = sumSummerAverageErie + lakeErieDuplicate[i];
      summerAverageErie = sumSummerAverageErie/94;
    }
  for(int i = 171; i <= 264; i++) {
      sumSummerAverageOntario = sumSummerAverageOntario + lakeOntarioDuplicate[i];
      summerAverageOntario = sumSummerAverageOntario/94;
    }
  for(int i = 171; i <= 264; i++) {
      sumSummerAverageClair = sumSummerAverageClair + lakeClairDuplicate[i];
      summerAverageClair = sumSummerAverageClair/94;
    }
    
	printf("\nQuestion 5\n");
	printf("The summer average of Lake Superior in Degrees C is: %.2f\n", summerAverageSuperior);
	printf("The summer average of Lake Michigan in Degrees C is: %.2f\n", summerAverageMichigan);			//user output for summer averages
	printf("The summer average of Lake Huron in Degrees C is: %.2f\n", summerAverageHuron);
	printf("The summer average of Lake Erie in Degrees C is: %.2f\n", summerAverageErie);
	printf("The summer average of Lake Ontario in Degrees C is: %.2f\n", summerAverageOntario);
	printf("The summer average of Lake St.Clair in Degrees C is: %.2f\n", summerAverageClair);
	printf("\nThis data creates a warmest to coldest order of: Erie, St. Clair, Ontario, Michigan, Huron, and Superior.\nThe order matches to that determined in Part 2.\n");	//analysis of warmest to coldest summer average
	printf("\n------------------------------------------------------------------------------\n");

    //Part 6 --- Winter average is day 1 to day 79 and also day 355 to day 365. Seperate for each lake, display warmest to coldest and compare with part 2.
	for(int i = 0; i <= 78; i++) {
    sumWinterAverageSuperior = sumWinterAverageSuperior + lakeSuperiorDuplicate[i];
    }																																			//two for statements correspond to a single winter average calculation
    for(int i = 354; i <= 364; i++) {																							//this is due to two separate ranges for the winter average of a lake
	sumWinterAverageSuperior2 = sumWinterAverageSuperior2 + lakeSuperiorDuplicate[i];						
    }
	sumWinterAverageSuperiorTotal = sumWinterAverageSuperior + sumWinterAverageSuperior2;
    winterAverageSuperior = sumWinterAverageSuperiorTotal/90;
    
    for(int i = 0; i <= 78; i++) {
    sumWinterAverageMichigan = sumWinterAverageMichigan + lakeMichiganDuplicate[i];
    }																																			
    for(int i = 354; i <= 364; i++) {
	sumWinterAverageMichigan2 = sumWinterAverageMichigan2 + lakeMichiganDuplicate[i];
    }
	sumWinterAverageMichiganTotal = sumWinterAverageMichigan + sumWinterAverageMichigan2;
    winterAverageMichigan = sumWinterAverageMichiganTotal/90;
    
    for(int i = 0; i <= 78; i++) {
    sumWinterAverageHuron= sumWinterAverageHuron + lakeHuronDuplicate[i];						//this process is repeated for each lake
    }																																			
    for(int i = 354; i <= 364; i++) {
	sumWinterAverageHuron2 = sumWinterAverageHuron2 + lakeHuronDuplicate[i];
    }
	sumWinterAverageHuronTotal = sumWinterAverageHuron + sumWinterAverageHuron2;
    winterAverageHuron= sumWinterAverageHuronTotal/90;
    
    for(int i = 0; i <= 78; i++) {
    sumWinterAverageErie= sumWinterAverageErie + lakeErieDuplicate[i];
    }																																			
    for(int i = 354; i <= 364; i++) {
	sumWinterAverageErie2 = sumWinterAverageErie2 + lakeErieDuplicate[i];
    }
	sumWinterAverageErieTotal = sumWinterAverageErie + sumWinterAverageErie2;
    winterAverageErie= sumWinterAverageErieTotal/90;
    
    for(int i = 0; i <= 78; i++) {
    sumWinterAverageOntario= sumWinterAverageOntario + lakeOntarioDuplicate[i];
    }																																			
    for(int i = 354; i <= 364; i++) {
	sumWinterAverageOntario2 = sumWinterAverageOntario2 + lakeOntarioDuplicate[i];
    }
	sumWinterAverageOntarioTotal = sumWinterAverageOntario + sumWinterAverageOntario2;
    winterAverageOntario= sumWinterAverageOntarioTotal/90;
    
    for(int i = 0; i <= 78; i++) {
    sumWinterAverageClair= sumWinterAverageClair + lakeClairDuplicate[i];
    }																																			
    for(int i = 354; i <= 364; i++) {
	sumWinterAverageClair2 = sumWinterAverageClair2 + lakeClairDuplicate[i];
    }
	sumWinterAverageClairTotal = sumWinterAverageClair + sumWinterAverageClair2;
    winterAverageClair = sumWinterAverageClairTotal/90;
   
	printf("\nQuestion 6\n");
	printf("The winter average of Lake Superior in Degrees C is: %.2f\n", winterAverageSuperior);
	printf("The winter average of Lake Michigan in Degrees C is: %.2f\n", winterAverageMichigan);		//user output for winter averages of each lake
	printf("The winter average of Lake Huron in Degrees C is: %.2f\n", winterAverageHuron);
	printf("The winter average of Lake Erie in Degrees C is: %.2f\n", winterAverageErie);
	printf("The winter average of Lake Ontario in Degrees C is: %.2f\n", winterAverageOntario);
	printf("The winter average of Lake St.Clair in Degrees C is: %.2f\n", winterAverageClair);
	printf("\nThis data creates a warmest to coldest order of: Ontario, Michigan, Erie, Huron, Superior, and St. Clair.\nThe order does not match to that determined in Part 2.\n"); //analysis of warmest to coldest winter average

	printf("\n------------------------------------------------------------------------------\n");

    //Part 7 --- if temp > 20 then you can swim. Calc the number of days you can swim SEPARATE for each lake.
	for(int i = 0; i < 366; i++) {
		if(lakeSuperiorDuplicate[i] > 20) {
			swimDaysSuperior++;
		}
	}																	//only if the temperature is greater than 20, a counter is implemented for the number of swimming days
	for(int i = 0; i < 366; i++) {							//this works the same way as a human counting on their fingers how many days from a set are above 20 degrees
		if(lakeMichiganDuplicate[i] > 20) {
			swimDaysMichigan++;
		}
	}
	for(int i = 0; i < 366; i++) {
		if(lakeHuronDuplicate[i] > 20) {
			swimDaysHuron++;
		}
	}
	for(int i = 0; i < 366; i++) {
		if(lakeErieDuplicate[i] > 20) {
			swimDaysErie++;
		}
	}
	for(int i= 0; i < 366; i++) {							//repeated once for each lake, for comfortable swimming days of each lake
		if(lakeOntarioDuplicate[i] > 20) {
			swimDaysOntario++;
		}
	}
	for(int i = 0; i < 366; i++) {
		if(lakeClairDuplicate[i] > 20) {
			swimDaysClair++;
		}
	}
	
	printf("\nQuestion 7\n");
	printf("The number of days that swimming comfortably is possible for Lake Superior is: %d\n", swimDaysSuperior);
	printf("The number of days that swimming comfortably is possible for Lake Michigan is: %d\n", swimDaysMichigan);		//user output for swimming days of each lake
	printf("The number of days that swimming comfortably is possible for Lake Huron is: %d\n", swimDaysHuron);
	printf("The number of days that swimming comfortably is possible for Lake Erie is: %d\n", swimDaysErie);
	printf("The number of days that swimming comfortably is possible for Lake Ontario  is: %d\n", swimDaysOntario);
	printf("The number of days that swimming comfortably is possible for Lake St.Clair is: %d\n", swimDaysClair);
	printf("\n------------------------------------------------------------------------------\n");

    //Part 8 --- if temp < 0 then lake freezes. Calc the number of days lake is frozen SEPARATE for each lake.
    for(int i = 0; i < 366; i++) {
		if(lakeSuperiorDuplicate[i] < 0) {
			frozenDaysSuperior++;
		}
	}
     for(int i = 0; i < 366; i++) {
		if(lakeMichiganDuplicate[i] < 0) {			//same logic as previous question implented, where a counter is incremented for days under 0 degrees temperature
			frozenDaysMichigan++;
		}
	}
	 for(int i = 0; i < 366; i++) {
		if(lakeHuronDuplicate[i] < 0) {
			frozenDaysHuron++;
		}
	}
    for(int i = 0; i < 366; i++) {
		if(lakeErieDuplicate[i] < 0) {				//repeated once for each lake to find frozen days
			frozenDaysErie++;
		}
	}
	for(int i = 0; i < 366; i++) {
		if(lakeOntarioDuplicate[i] < 0) {
			frozenDaysOntario++;
		}
	}
	 for(int i = 0; i < 366; i++) {
		if(lakeClairDuplicate[i] < 0) {
			frozenDaysClair++;
		}
	}

    printf("\nQuestion 8\n");
    printf("Lake Superior is frozen for %d days.\n", frozenDaysSuperior);		//user output the number of days a specific lake is frozen
    printf("Lake Michigan is frozen for %d days.\n", frozenDaysMichigan);
    printf("Lake Huron is frozen for %d days.\n", frozenDaysHuron);
    printf("Lake Erie is frozen for %d days.\n", frozenDaysErie);
    printf("Lake Ontario is frozen for %d days.\n", frozenDaysOntario);
    printf("Lake St.Clair is frozen for %d days.\n", frozenDaysClair);
    printf("\n------------------------------------------------------------------------------\n");

    //Part 9 --- Question one (7 Average Temps) recalculated with 2019 data. Make a table of 2019 vs 2020 data and write notable changes.
    
    FILE*datafile2 = fopen("lakefile2019.TXT", "r");			//linking 2019 data file for analysis. It is placed in the same folder as the 2020 data file, but placed into arrays in a similar manner
    
    while(!feof(datafile2)) {
		for(int i = 0; i < 364; i++) {
			fscanf(datafile2, "%d%d%lf%lf%lf%lf%lf%lf", &year2019[i], &dayScan2019[i], &lakeSuperior2019[i], &lakeMichigan2019[i], &lakeHuron2019[i], &lakeErie2019[i], &lakeOntario2019[i], &lakeClair2019[i]);
		}
	}

	for(int i = 0; i < 365; i++) { 
      sumSuperior2019 = sumSuperior2019 + lakeSuperior2019[i];
      yearlyAverageSuperior2019 = sumSuperior2019/365;					//same structure as question 1, repeated for 2019 data
      yearlyComparison2019[0] = yearlyAverageSuperior2019;
    }
    for(int i = 0; i < 365; i++) {
      sumMichigan2019 = sumMichigan2019 + lakeMichigan2019[i];
      yearlyAverageMichigan2019 = sumMichigan2019/365;
      yearlyComparison2019[1] = yearlyAverageMichigan2019;
    }
    for(int i = 0; i < 365; i++) {
      sumHuron2019 = sumHuron2019 + lakeHuron2019[i];
      yearlyAverageHuron2019 = sumHuron2019/365;
      yearlyComparison2019[2] = yearlyAverageHuron2019;
    }
    for(int i = 0; i < 365; i++) {												//repeated once for each lake, as done for 2020 year
      sumErie2019 = sumErie2019 + lakeErie2019[i];
      yearlyAverageErie2019 = sumErie2019/365;
      yearlyComparison2019[3] = yearlyAverageErie2019;
    }
    for(int i = 0; i < 365; i++) {
      sumOntario2019 = sumOntario2019 + lakeOntario2019[i];
      yearlyAverageOntario2019 = sumOntario2019/365;
      yearlyComparison2019[4] = yearlyAverageOntario2019;
    }
    for(int i = 0; i < 365; i++) {
      sumClair2019 = sumClair2019 + lakeClair2019[i];
      yearlyAverageClair2019 = sumClair2019/365;
      yearlyComparison2019[5] = yearlyAverageClair2019;
    }
    for(int i = 0; i < 6; i++) {
      sumYearlyAverageTotal2019 = yearlyAverageSuperior2019 + yearlyAverageMichigan2019 + yearlyAverageHuron2019 + yearlyAverageErie2019 + yearlyAverageOntario2019 + yearlyAverageClair2019;
      yearlyAverageTotal2019 = sumYearlyAverageTotal2019/6;				//finding total average of 2019 year
    }

	printf("\nQuestion 9\n");
	printf("--------------------------------------\nColumnar Report of Data (in degrees C)\n--------------------------------------\nName\t|\t2019\t|   2020\n");
	printf("--------------------------------------\n");
	printf("Superior: \t%.2f\t|   %.2f\n", yearlyComparison2019[0], yearlyComparison2020[0]);
	printf("Michigan: \t%.2f\t|   %.2f\n", yearlyComparison2019[1], yearlyComparison2020[1]);
	printf("Huron: \t\t%.2f\t|   %.2f\n", yearlyComparison2019[2], yearlyComparison2020[2]);
	printf("Erie: \t\t%.2f\t|   %.2f\n", yearlyComparison2019[3], yearlyComparison2020[3]);
	printf("Ontario: \t%.2f\t|   %.2f\n", yearlyComparison2019[4], yearlyComparison2020[4]);			//printing a comparison table of data for 2019 versus 2020 temperatures
	printf("St. Clair: \t%.2f\t|   %.2f\n", yearlyComparison2019[5], yearlyComparison2020[5]);
	printf("Total Average: \t%.2f\t|   %.2f\n", yearlyAverageTotal2019, yearlyAverageTotal);
    printf("\n------------------------------------------------------------------------------\n\n");
    
    return 0;
}

void sortLakeData(double lake[], double day[]) {
	while(1) {  
      double boolean2 = 0;                  
      for(int j = 0; j < 366-1; j++) {
        if(lake[j] > lake[j+1]) {  			
          double temp2 = lake[j];				
          lake[j] = lake[j+1];
          lake[j+1] = temp2;
          double temp3 = day[j];								//sorts the lake data based on temerpature, and the day data on the order in which the lake data was sorted
          day[j] = day[j+1];
          day[j+1] = temp3;
          boolean2 = 1;
        }
      }
      if(boolean2 == 0) {
        break;
      }
    }
	
	allInstancesColdest(lake, day);
	allInstancesWarmest(lake, day);

}

void allInstancesColdest(double lake[], double day[]) {
	int occurenceCounter, occurencePosition;
    double tempDay;
    double month, dayOfMonth;
	for(int i = 0; i < 365; i++) {                  //iterates through entire array, if any index matches the coldest index, its corresponding day is sent over to date format function to find date
			if(lake[i] == lake[0]) {
				printf("It's lowest temperature happened at: ");
				occurencePosition = i+1;
				tempDay = day[occurencePosition - 1];
				dateFormatColdest(tempDay, &month, &dayOfMonth);
				printf("%.2f on %.0f/%.0f/2020\n", lake[0], month, dayOfMonth);
			}
	}
}

void allInstancesWarmest(double lake[], double day[]) {
	 int occurenceCounter2, occurencePosition2;
	 double tempDay2;
	 double month, dayOfMonth;
	
	for(int i = 0; i < 365; i++) {
				occurencePosition2 = i + 1;              //iterates through entire array, if any index matches the warmest index, its corresponding day is sent over to date format function to find date
				tempDay2 = day[occurencePosition2];
				dateFormatWarmest(tempDay2, &month, &dayOfMonth);
	}
	 printf("The highest temperature was: %.2f on %.0f/%.0f/2020\n\n", lake[365], month, dayOfMonth);
}


void arrayDuplication(double lake[], double lakeDuplicate[]) {
	for(int i = 0; i < 366; i ++) {						
		lakeDuplicate[i] = lake[i];
	}																//arrayDuplication and dayScanDuplication just copies the arrays 6 times so there is a backup copy of data, as each lake's order will be sorted differently
}

void dayScanDuplication(double dayScan[], double dayScanLake[]) {
	for(int i = 0; i < 366; i++) {
		dayScanLake[i] = dayScan[i];
		}
	}

void dateFormatColdest(double tempDay, double *month, double *dayOfMonth) {															
		if(tempDay <= 31) {
			*month = 1;
			*dayOfMonth = tempDay;
		}
		
		if(tempDay> 31 && tempDay <= 60) {
			*month = 2;
			*dayOfMonth =  tempDay- 31;
		}
		if(tempDay > 60 && tempDay <= 91) {					//sorting structure based on the day number, sorted into a certain category which assigns month
			*month = 3;																				
			*dayOfMonth = tempDay - 60;										//day is assigned based on simple logical math, considering the number of days for each month of 2020
		}	
		if(tempDay > 91 && tempDay <= 121) {
			*month = 4;
			*dayOfMonth = tempDay - 91;
		}
		if(tempDay > 121 && tempDay <= 152) {
			*month = 5;
			*dayOfMonth = tempDay -121;
		}
		if(tempDay > 152 && tempDay <= 182) {
			*month =6;
			*dayOfMonth = tempDay - 152;
		}
		if(tempDay > 182 && tempDay <= 213) {
			*month = 7;
			*dayOfMonth = tempDay - 182;
		}
		if(tempDay> 213 && tempDay <= 244) {
			*month  = 8;
			*dayOfMonth = tempDay - 213;
		}
		if(tempDay > 244 && tempDay <= 274) {
			*month = 9;
			*dayOfMonth = tempDay - 244;
		}
		if(tempDay > 274 && tempDay <= 305) {
			*month = 10;
			*dayOfMonth = tempDay - 274;
		}
		if(tempDay > 305 && tempDay <= 335) {
			*month = 11;
			*dayOfMonth = tempDay- 305;
		}
		if(tempDay> 335 && tempDay <= 366) {
			*month = 12;
			*dayOfMonth = tempDay - 335;
		}	
}

void dateFormatWarmest(double tempDay2, double *month, double *dayOfMonth) {
		if(tempDay2 <= 31) {
			*month = 1;
			*dayOfMonth = tempDay2;
		}
		if(tempDay2> 31 && tempDay2 <= 60) {
			*month= 2;
			*dayOfMonth =  tempDay2- 31;
		}
		if(tempDay2 > 60 && tempDay2 <= 91) {					//sorting structure based on the day number, sorted into a certain category which assigns month
			*month = 3;																				
			*dayOfMonth = tempDay2 - 60;										//day is assigned based on simple logical math, considering the number of days for each month of 2020
		}	
		if(tempDay2 > 91 && tempDay2<= 121) {
			*month = 4;
			*dayOfMonth = tempDay2 - 91;
		}
		if(tempDay2 > 121 && tempDay2 <= 152) {
			*month = 5;
			*dayOfMonth = tempDay2 -121;
		}
		if(tempDay2 > 152 && tempDay2 <= 182) {
			*month =6;
			*dayOfMonth = tempDay2- 152;
		}
		if(tempDay2> 182 && tempDay2 <= 213) {
			*month = 7;
			*dayOfMonth = tempDay2 - 182;
		}
		if(tempDay2> 213 && tempDay2 <= 244) {
			*month  = 8;
			*dayOfMonth = tempDay2 - 213;
		}
		if(tempDay2 > 244 && tempDay2 <= 274) {
			*month = 9;
			*dayOfMonth = tempDay2 - 244;
		}
		if(tempDay2 > 274 && tempDay2 <= 305) {
			*month= 10;
			*dayOfMonth = tempDay2 - 274;
		}
		if(tempDay2 > 305 && tempDay2 <= 335) {
			*month = 11;
			*dayOfMonth = tempDay2 - 305;
		}
		if(tempDay2 > 335 && tempDay2 <= 366) {
			*month = 12;
			*dayOfMonth = tempDay2 - 335;
		}	
}

void groupInfo() {							//simple text function that is called at the start for storing group member information, as well as a short introduction to what the data represents
  printf("CPS188 Term Project - Winter 2022\nGroup No. 121\nDeep Patel, 501090050, deep.c.patel@ryerson.ca\nRicky Rathod, 501104462, r1rathod@ryerson.ca\nSanjot Khaira, 501104140, sanjot.khaira@ryerson.ca\n");
  printf("\nThis project uses C methods based on CPS188 curriculum\nto analyze extensive sets of data regarding the 6 Great Lakes in Canada.\nFurther detail provided in report.\n");
  printf("\n------------------------------------------------------------------------------\n\n");
} 

