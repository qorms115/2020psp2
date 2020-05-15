#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



double ave_online(double val,double ave,double count){
    ave = ((count-1)/count)*ave + (1/count)*val; 
    return ave;    
    }
    
double var_online(double ave,double ave2){
    double var = 0 ;
    var = ave2 - pow(ave,2);
    return var;
}

int main(void)
{
    double val,val2 = 0;
    double ave,ave2 = 0;
    double var,var2 = 0;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    
    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

     int count = 1;

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        ave = ave_online(val,ave,count);
        val2 = pow(val,2);
        ave2 = ave_online(val2,ave2,count);
        var = var_online(ave,ave2);
        count = count + 1 ;
    }
    
    var2 = var*(count-1)/(count-2);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    printf("Avrage is %5.2lf\n",ave);
    printf("Variance is %5.2lf\n",var);
    printf("Expeted Avrage is %5.2lf\n",ave);
    printf("Expeted variance is %5.2lf\n",var2);

    return 0;


}



