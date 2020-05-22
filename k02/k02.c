#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);
#define MU_A 170.8
#define MU_B 169.7
#define SIGMA_A 5.43
#define SIGMA_B 5.5

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;
    double mu_a= MU_A, sigma_a = SIGMA_A ;
    double mu_b=MU_B,sigma_b = SIGMA_B ;
    double y_a = 0 ,y_b = 0 ;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

    y_a = (val-mu_a) / sigma_a ;
    y_b = (val-mu_b) / sigma_b ;

    y_a = p_stdnorm(y_a);
    y_b = p_stdnorm(y_b);

    L1 = L1*y_a;
    L2 = L2*y_b;

    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L1);
    printf("L_B: %f\n",L2);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}
