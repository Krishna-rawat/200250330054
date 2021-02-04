#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#define PORT 8080

void monitor(void);



struct packet
{
    int unique_id;
    long int p_no;
    int cs,th,acc,gy;
    time_t timer;
    struct packet *next;
};

int main(int argc, char const *argv[])
{
    struct packet *p1,*new,*head;
    int sock = 0,c,t,a,g;
    struct sockaddr_in serv_addr; 
    int arr[25];

      
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
     
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }

    new=(struct packet *)malloc(sizeof(struct packet));

    c=read(sock,arr,25);
    t=read(sock,arr,25);
    a=read(sock,arr,25);
    g=read(sock,arr,25);
    if(head==0)
    {
        head=p1;
    }
    else
    {
        struct packet* temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        p1->cs=c;
        p1->th=t;
        p1->acc=a;
        p1->gy=g;
        temp->next=p1;
        p1->next=NULL;

    }


    void monitor(void)
    {
        if(head==0)
        {
            printf("no data received\n");

        }
        else
        {
            struct packet *temp;
            temp=head;
            while(temp!=NULL)
            {
                printf("temp_control system= %d\ntemp_thruster= %d\nAcceleration= %d\nGyro= %d\n",temp->cs,temp->th,temp->acc,temp->gy);
                temp=temp->next;


            }
        }
        
    }

    return 0;
}
