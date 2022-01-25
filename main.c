// Program for triangulating strongholds in minecraft
// Jukka S
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// These functions are used to validate user input
int get_coordinate(){
    int valid = 1;
    int i;
    char input[8];
    do{
        if(valid == 0){
            printf("Invalid input, please try again:\n");
        }
        valid = 1;
        scanf("%s", input);
        // Check if input has non-numeric characters
        for(i=0; i<8 && input[i]!='\0'; i++){
            if((input[i] < '0' || input[i] > '9') && input[i]!='-'){
                valid = 0;
                break;
            }
        }
    }while(valid == 0 || i == 0);
    return atoi(input);
}

float get_angle(){
    int valid = 1;
    int i;
    char input[6];
    do{
        if(valid == 0){
            printf("Invalid input, please try again:\n");
        }
        valid = 1;
        scanf("%s", input);
        // Check if input has non-numeric characters
        for(i=0; i<8 && input[i]!='\0'; i++){
            if((input[i] < '0' || input[i] > '9') && input[i]!='.'
                && input[i]!='-'){
                valid = 0;
                break;
            }
        }
    }while(valid == 0 || i == 0);
    return atof(input);
}

int main(int argc, char* argv[]){
    int x1, x2, z1, z2;
    float angle1, angle2;

    // Get necessary user input
    printf("First throw X:\n");
    x1 = get_coordinate();
    printf("First throw Z:\n");
    z1 = get_coordinate();
    printf("First throw angle:\n");
    angle1 = get_angle();
    printf("Second throw X:\n");
    x2 = get_coordinate();
    printf("Second throw Z:\n");
    z2 = get_coordinate();
    printf("Second throw angle:\n");
    angle2 = get_angle();

    // Convert angles from minecraft coordinate system to normal
    // and calculate the slopes of the equations
    angle1 = angle1 * -1;
    angle2 = angle2 * -1;
    float a1rad = angle1*(3.1416/180);
    float a2rad = angle2*(3.1416/180);
    float k1 = sin(a1rad)/cos(a1rad);
    float k2 = sin(a2rad)/cos(a2rad);

    // Calculate the constants of the equations
    float b1 = x1-(k1*z1);
    float b2 = x2-(k2*z2);

    // Calculate the coordinates in which the equations intersect
    int portalz = (b2-b1)/(k1-k2);
    int portalx = k1*portalz+b1;

    printf("Portal is at:\n");
    printf("X: %i\n", portalx);
    printf("Z: %i\n", portalz);

    return 0;
}
