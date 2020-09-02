#include <stdio.h>
#include <hfcal.h>

void display_calories(float weight, float distance, float coeff) {
    printf("weight : %3.2f \n", weight);
    printf("distance : %3.2f \n", distance);
    printf("coeff : %3.2f \n", coeff * weight * distance);
}