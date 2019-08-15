// compute the square of the number

#include <stdio.h>
#include <stdlib.h>
#include "TutorialConfig.h"
// #include <math.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stdout, "%s Version %d.%d\n",
                argv[0],
                Tutorial_VERSION_MAJOR,
                Tutorial_VERSION_MINOR);
        fprintf(stdout, "usage: %s number\n", argv[0]);
        return 1;
    }

    double input_value = atof(argv[1]);
    double output_value = input_value * input_value;
    fprintf(stdout, "The square of %g is %g\n", input_value, output_value);

    return 0;
}
