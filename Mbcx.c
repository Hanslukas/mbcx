#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void usage();

double get_number(char **);

int convert_byte(double);
int convert_kbyte(double);
int convert_mByte(double);
int convert_gByte(double);
int convert_tByte(double);
int convert_pByte(double);



const int CONVERSION_VALUE = 1024;


int main(int argc, char *argv[])
{
	int i = 0;
	int check;
	/* Variable for conversion*/
	double byte = 0;
	double kbyte = 0;
	double mByte = 0;
	double gByte = 0;
	double tByte = 0;
	double pByte = 0;

	if(argc >= 2)
	{
	while((i = getopt(argc, argv, "hp:B:K:M:G:T:P")) != -1)
		switch(i) {
			case 'h':
				usage();
				return -1;
			case 'B':
				byte = get_number(argv);
				check = convert_byte(byte);
				if(check == 1)
					fprintf(stderr, "Conversion error\n");
				break;

			case 'K': 
				kbyte = get_number(argv);
				check = convert_kbyte(kbyte);
				if(check == 1)
					fprintf(stderr, "Conversion error\n");
				break;
			case 'M':
				mByte = get_number(argv);
				check = convert_mByte(mByte);
				if(check == 1)
					fprintf(stderr, "Conversion error\n");
				
				break;
			case 'G': 
				gByte = get_number(argv);
				check = convert_gByte(gByte);
				if(check == 1)
					fprintf(stderr, "Conversion error\n");
				break;
			case 'T': 
				tByte = get_number(argv);
				check = convert_tByte(tByte);
				if(check == 1)
					fprintf(stderr, "Conversion error\n");
				break;
			case 'P': 
				pByte = get_number(argv);
				check = convert_pByte(pByte);
				if(check == 1)
					fprintf(stderr, "Conversion error\n");
				break;
			case '?':
				usage();
				exit(1);
				break;

			default: 
				usage();
				exit(1);
				break;
			}
	}
	else
	{
		usage();
		exit(1);
	}

	return 0;
}

void usage()
{
	printf("\n\nUso: mbcx [OPZIONE] numero \n");
	printf("mbcx -M 2\n");
	printf("Risultato: \n2097152 byte\n");
	printf("2048 KB\n");
	printf("0.00195 MB\n");
	printf("...\n");
	printf("Stabilisce il valore nella scala dei MegaByte\n\n");

	printf("  -B 		definisce il byte\n");
	printf("  -K 		definisce il kilobyte\n");
	printf("  -M 		definisce il megabyte\n");
	printf("  -G 		definisce il gigabyte\n");
	printf("  -T 		definisce il terabyte\n");
	printf("  -P 		definisce il petabyte\n\n");
}

double get_number(char *param[])
{
	double number = atof(param[2]);

	if (number == 0) {
		fprintf(stderr, "No matching characters\n");
    }
           		
				
	return number;
}

int convert_byte(double num) 
{
	double k, m, g, t, p;
	int flag = 0;

	k = num/CONVERSION_VALUE;
	m = k/CONVERSION_VALUE;
	g = m/CONVERSION_VALUE;
	t = g/CONVERSION_VALUE;
	p = t/CONVERSION_VALUE;

	flag = 1;

	if(flag == 1)
	  printf("\n %7.3lf KB \n %lf MB \n %lf GB \n %lf TB \n %lf PB\n\n", k,m,g,t,p);
	else
	  return 1;


	
}

int convert_kbyte(double num) 
{
	double b, m, g, t, p;
	int flag = 0;


	b = num*CONVERSION_VALUE;
	m = num/CONVERSION_VALUE;
	g = m/CONVERSION_VALUE;
	t = g/CONVERSION_VALUE;
	p = t/CONVERSION_VALUE;

	flag = 1;

	if(flag == 1)
		printf("\n %7.3lf B \n %lf MB \n %lf GB \n %lf TB \n %lf PB\n\n", b,m,g,t,p);
	else
		return 1;

}

int convert_mByte(double num) 
{
	double b, k, g, t, p;
	int flag = 0;

	k = num*CONVERSION_VALUE;
	b = k*CONVERSION_VALUE;
	g = num/CONVERSION_VALUE;
	t = g/CONVERSION_VALUE;
	p = t/CONVERSION_VALUE;

	flag = 1;

	if(flag == 1)
		printf("\n %7.3lf B \n %lf KB \n %lf GB \n %lf TB \n %lf PB\n\n", b,k,g,t,p);
	else
		return 1;

}

int convert_gByte(double num) 
{
	double b, k, m, t, p;
	int flag = 0;

	m = num*CONVERSION_VALUE;
	k = m*CONVERSION_VALUE;
	b = k*CONVERSION_VALUE;
	t = num/CONVERSION_VALUE;
	p = t/CONVERSION_VALUE;

	flag = 1;

	if(flag == 1)
		printf("\n %7.3lf B \n %lf KB \n %lf MB \n %lf TB \n %lf PB\n\n", b,k,m,t,p);
	else
		return 1;
}

int convert_tByte(double num) 
{
	double b, k, m, g, p;
	int flag = 0;

	g = num*CONVERSION_VALUE;
	m = g*CONVERSION_VALUE;
	k = m*CONVERSION_VALUE;
	b = k*CONVERSION_VALUE;
	p = num/CONVERSION_VALUE;

	flag = 1;

	if(flag == 1)
		printf("\n %7.3lf B \n %lf KB \n %lf MB \n %lf GB \n %lf PB\n\n", b,k,m,g,p);
	else
		return 1;

}

int convert_pByte(double num) 
{
	double b, k, m, g, t;
	int flag = 0;

	t = num*CONVERSION_VALUE;
	g = t*CONVERSION_VALUE;
	m = g*CONVERSION_VALUE;
	k = m*CONVERSION_VALUE;
	b = k*CONVERSION_VALUE;

	flag = 1;

	if(flag == 1)
		printf("\n %7.3lf B \n %lf KB \n %lf MB \n %lf GB \n %lf TB\n\n", b,k,m,g,t);
	else
		return 1;

}
