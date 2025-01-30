#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Captured a packet with length of [%d]\n", header->len);

    struct ip *iph = (struct ip*)(packet + 14);
    printf("   Source IP: %s\n", inet_ntoa(iph->ip_src));
    printf("   Destination IP: %s\n", inet_ntoa(iph->ip_dst));
    
    if (iph->ip_p == IPPROTO_TCP) {
        struct tcphdr *tcph = (struct tcphdr*)(packet + 14 + iph->ip_hl * 4);
        printf("   Protocol: TCP, Source Port: %d, Destination Port: %d\n", ntohs(tcph->source), ntohs(tcph->dest));
    } else if (iph->ip_p == IPPROTO_UDP) {
        struct udphdr *udph = (struct udphdr*)(packet + 14 + iph->ip_hl * 4);
        printf("   Protocol: UDP, Source Port: %d, Destination Port: %d\n", ntohs(udph->source), ntohs(udph->dest));
    } else {
        printf("   Protocol: Other (%d)\n", iph->ip_p);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    device = argv[1];
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return EXIT_FAILURE;
    }

    while (1) {
        pcap_loop(handle, 1, packet_handler, NULL);
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}
