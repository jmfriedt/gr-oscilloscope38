// gcc -o tcp_server tcp_server.c -lm

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <arpa/inet.h>
#include <math.h>
#include <unistd.h>

#define MY_PORT         9999

int main()
{int sockfd;
 struct sockaddr_in self;
 float *buffer;
 struct sockaddr_in client_addr;
 int clientfd;
 socklen_t addrlen=sizeof(client_addr);
 int taille,k,c;
 long channels;

 sockfd = socket(AF_INET, SOCK_STREAM, 0);  // socket type (TCP blocking)

 bzero(&self, sizeof(self));
 self.sin_family = AF_INET;
 self.sin_port = htons(MY_PORT);
 self.sin_addr.s_addr = INADDR_ANY;

 bind(sockfd, (struct sockaddr*)&self, sizeof(self));
 listen(sockfd, 20);
 
 while (1) {
  clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);
  printf("%s:%d connected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
  recv(clientfd, &channels, sizeof(long), 0);channels=ntohl(channels);
  printf("%d channels\n",channels);
  while (taille!=-1)
    {recv(clientfd, &taille, sizeof(long), 0);
     taille=ntohl(taille);
     printf("request: %d values\n",taille);
     if (taille>0)
        {buffer=(float*)malloc(sizeof(float)*taille);
         for (c=0;c<channels;c++)
            {for (k=0;k<taille;k++) 
                 buffer[k]=sin(2*M_PI*(float)k/(float)taille*5*(float)(c+1));
             send(clientfd, buffer, taille*sizeof(float), 0);
            }
         free(buffer);
        }
    }
  close(clientfd);
  printf("Waiting for new connection\n");
  taille=0;    // when disconnect and reconnect
 }
 close(sockfd);return(0);  // Clean up (should never get here)
}
