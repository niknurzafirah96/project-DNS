#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
int main()
{

    
char ans='y';
printf("do you want to start now?y/n:");
scanf("%c",&ans);

 



  struct sockaddr_in server,client;
    int s,n;
    char fserver[100],toserver[100];
    s=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=8888;
    server.sin_addr.s_addr=inet_addr("192.168.80.136");
    n=sizeof(server);
int c;
while(ans!='n'){
printf("IP ADDRESS FOR \n 1.SOSIAL \n 2.OTHERS \n");
printf("what do you want to choice?");
scanf("%i",&c);
if(c==1){
    printf("\nEnter what address do you want form SOSIAL website?(full url): ");
    scanf("%s",toserver);


    sendto(s,toserver,sizeof(toserver),0,(struct sockaddr *)&server,n);
   recvfrom(s,fserver,sizeof(fserver),0,(struct sockaddr *)&server,&n);
    printf("ip address is: %s \n",fserver);
}else if(c==2){

printf("\nEnter what address do you want from OTHER website? (full url): ");
    scanf("%s",toserver);


    sendto(s,toserver,sizeof(toserver),0,(struct sockaddr *)&server,n);
   recvfrom(s,fserver,sizeof(fserver),0,(struct sockaddr *)&server,&n);
    printf("ip address is: %s \n",fserver);
}

printf("\n \n do you want to start again?y/n:");
scanf(" %c",&ans);

}


return 0;

}
