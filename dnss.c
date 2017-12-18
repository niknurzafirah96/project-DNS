#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char *argv[])
{

   
    FILE *fp;
   FILE *fp1;
    struct sockaddr_in server,client;
    int s,n;
    char b1[100],b2[100],a[100]; //ans[100];
    s=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=8888;
    server.sin_addr.s_addr=inet_addr("192.168.80.136");
    bind(s,(struct sockaddr *)&server,sizeof(server));
    n=sizeof(client);
    puts("socket have been connected...");


 while(1){
        strcpy(b2,"");
        fp=fopen("dnst.txt","r");
       fp1=fopen("news.txt","r"); 
        recvfrom(s,b1,sizeof b1, 0,(struct sockaddr *)&client,&n);
         puts("have been send request to client...");
	while(!feof(fp))
       {
	   
           fscanf(fp,"%s",a);
           if(strcmp(a,b1)==0)
          {
                fscanf(fp,"%s",b2);
                break;
          }
      }
while(!feof(fp1))
       {
	   
           fscanf(fp1,"%s",a);
           if(strcmp(a,b1)==0)
          {
                fscanf(fp1,"%s",b2);
                break;
          }
      }

      if(strcmp(b2,"")==0)
     {
           strcpy(b2,"Your IP for Your Url Not found In FILE...");
      }
    
   fclose(fp);
   sendto(s,b2,sizeof b2,0,(struct sockaddr *)&client,n); 
 
   }
}
