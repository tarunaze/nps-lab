#include<stdio.h>

unsigned fields[10];

unsigned short checksum()
{
    int i;
    int sum=0;
    printf("Enter teh IP header information in 16 bit words\n");

    for(i=0;i<9;i++){
        printf("Field %d\n",i+1);
        scanf("%x",&fields[i]);

        sum=sum+(unsigned short)fields[i];

        while(sum>>16)
        sum=(sum&0xFFFF)+(sum>>16);

    }
    sum=~sum;
    return (unsigned short)sum;
}

int main(){
    unsigned short result1,result2;

    result1=checksum();
    printf("\n computed checksum at sender %x\n",result1);

    result2=checksum();
    printf("\n computed checksum at reciever %x\n",result2);

    if(result1==result2){
        printf("NO ERROR\n");
    }
    else{
        printf("Ohh NO !ERROR detected\n");
    }
}