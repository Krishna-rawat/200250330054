#include<stdio.h>
#include<pthread.h>
#include<sys/socket.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <arpa/inet.h>
#include<sys/shm.h>
#define PORT 8080



void *temp_cs(void *arg)
{
    int value;
    value=rand()%270+30;
    int sock = 0; 
    struct sockaddr_in serv_addr;  
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
         
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
         
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
         
    } 
    send(sock , value , sizeof(int) , 0 );
    printf("data sent");
}

void *temp_thruster(void *arg)
{int value;
    value=rand()%200-30;
    int sock = 0; 
    struct sockaddr_in serv_addr;  
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
         
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        
    } 
    send(sock , value , sizeof(int) , 0 );
    printf("data sent");

}

void *acceleration(void *arg)
{
    int value;
    value=rand()%18+2;
    int sock = 0; 
    struct sockaddr_in serv_addr;  
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 

    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 

    } 
    send(sock , value , sizeof(int) , 0 );
    printf("data sent");

}

void *gyro(void *arg)
{
    int value;
    value=rand()%360;
    int sock = 0; 
    struct sockaddr_in serv_addr;  
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        
    } 
    send(sock , value , sizeof(int) , 0 );
    printf("data sent");
}
int main(int argc, char const *argv[])
{
    pthread_t tid_i , tid_d;

    
    

    pthread_create(&tid_i,NULL,temp_cs,NULL);
    pthread_create(&tid_d,NULL,temp_thruster,NULL);
    pthread_create(&tid_i,NULL,acceleration,NULL);
    pthread_create(&tid_d,NULL,gyro,NULL);
    sleep(1);

    return 0;
}
