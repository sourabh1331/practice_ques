/*
Temperature Monitoring and Conversion System 
A temperature monitoring device logs temperature readings in the format:
"TimeStamp-TemperatureUnit, TimeStamp-TemperatureUnit"
For example:
"08:30-22.5F, 12:15-25.0C, 15:45-24.8F"
Extracts the timestamp and temperature along with its unit (Celsius or Fahrenheit).
Converts the temperature:
If the input temperature is in Celsius (C), convert it to Fahrenheit (F) using the formula:
F=(C×9/5)+32
If the input temperature is in Fahrenheit (F), convert it to Celsius (C) using the formula:
C=(F−32)×5/9
INPUT : 
"08:30-22.5F, 12:15-25.0C, 15:45-24.8F"
OUTPUT : 
08:30 - Original: 22.5°F, Converted: -5.3°C
12:15 - Original: 25.0°C, Converted: 77.0°F
15:45 - Original: 24.8°F, Converted: -4.0°C
 
*/


#include<stdio.h>
#include<string.h>
#include<stdio.h>

void converttemp(char*temperature){
    int hour,min;
    float temp;
    char ch[2];
    float converted;
    sscanf(temperature,"%d:%d-%f %s",&hour,&min,&temp,&ch);

    if(strcmp(ch,"C")==0){
        converted=(temp * 9.0 / 5.0) + 32;
    }
    else if (strcmp(ch, "F") == 0){
        converted=(temp - 32) * 5.0 / 9.0;
    }
    printf("%d:%d-Original: %.1f,converted:-%.1f\n",hour,min,temp,converted);

}

int main() {
    char input[]="08:30-22.5F, 12:15-25.0C, 15:45-24.8F";
    
    //scanf("%[^\n]",input);
    char *token = strtok(input, ",");

    while (token != NULL) {
        converttemp(token);
        token = strtok(NULL, ",");
    }

    return 0;
}