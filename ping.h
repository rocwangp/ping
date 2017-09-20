#ifndef _PING_H__
#define _PING_H__

#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <signal.h>
#include <pthread.h>

#include <iostream>
#include <string>

#define PACKET_SIZE 4096
#define SEND_DATA_LEN 56
#define ERROR -1
#define SUCCESS 1
#define MAX_WAIT_TIME 3
#define MAX_NO_PACKETS 4
#define MAX_PACKET_NO 50

class CPing
{
    public:
        CPing();
        explicit CPing(const char *ip, const int timeout);
       // CPing(const CPing& orig);
        ~CPing();

        bool ping();

    private:
        bool CreateSocket();
        bool CloseSocket();
        
        void SetNonBlocking(const bool flag);

        void Send_Packet();
        void Receive_Packet();

        int Pack(int pack_no);
        int Unpack(int packSize);

        static void tv_sub(struct timeval *in, struct timeval *out);

        static void statistics(int sig);
        unsigned short Cal_ChkSum(unsigned short *addr, int len);
        
        void Init_PacketNoArray(); 

    private:
        std::string m_strIp;
        std::string m_copyIp;

        static int m_nSend;
        static int m_nRecv;
        int m_nCnt;

        static struct timeval m_begin_tvsend;
        static struct timeval m_end_tvrecv;
        struct timeval m_tvsend;

        char m_sendpack[PACKET_SIZE];
        char m_recvpack[PACKET_SIZE];

        struct sockaddr_in m_dest_addr;
        struct sockaddr_in m_from_addr;
        
        int m_nMaxTimeWait;
        static int m_nSocketfd;
        
        int m_nPacketNoLimit;
        bool m_bPacketNo[MAX_PACKET_NO]; 
};
#endif
