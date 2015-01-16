#include <stdlib.h>
#include <stdio.h>
#define NUM_POINTS 5
#define NUM_COMMANDS 2

int main(){
	double xvals[NUM_POINTS] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double yvals[NUM_POINTS] = { 5.0, 3.0, 1.0, 3.0, 5.0 };
	/*Opens an interface that one can use to send commands as if they were typing into the
	*     gnuplot command line.  "The -persistent" keeps the plot open even after your
	*     C program terminates. 
	*/
	FILE * gnuplotPipe = _popen("gnuplot -persistent", "w");
	fprintf(gnuplotPipe, "set title \"Lol\" \n");
	fprintf(gnuplotPipe, "set xtics offset character 0,0,0 norangelimit (\"Add\" 1, \"Remove\" 2, \"Display\" 3, \"Binary Search\" 4, \"Sequential Search\" 5) \n");
	fprintf(gnuplotPipe, "plot '-' t \"Hi\" w linesp \n");
	int i;
	for (i = 0; i < NUM_POINTS; i++)
	{
		fprintf(gnuplotPipe, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file
	}
	fprintf(gnuplotPipe, "e");
	

	/*
	for (i = 0; i < NUM_COMMANDS; i++)
	{
		fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
	}*/
	fflush(gnuplotPipe);
	
	return 0;
}