#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

void packet_handler(u_char *dumpfile, const struct pcap_pkthdr *header, const u_char *packet) {
    pcap_dump(dumpfile, header, packet); // Write the packet to the file

    printf("\n+------------------------+\n");
    printf("| Packet Length: %-7d |\n", header->len);
    printf("+------------------------+\n");

    struct ip *iph = (struct ip*)(packet + 14);
    printf("| Source IP: %-15s |\n", inet_ntoa(iph->ip_src));
    printf("| Destination IP: %-9s |\n", inet_ntoa(iph->ip_dst));
    
    if (iph->ip_p == IPPROTO_TCP) {
        struct tcphdr *tcph = (struct tcphdr*)(packet + 14 + iph->ip_hl * 4);
        printf("| Protocol: TCP           |\n");
        printf("| Source Port: %-10d |\n", ntohs(tcph->source));
        printf("| Dest Port: %-12d |\n", ntohs(tcph->dest));
    } else if (iph->ip_p == IPPROTO_UDP) {
        struct udphdr *udph = (struct udphdr*)(packet + 14 + iph->ip_hl * 4);
        printf("| Protocol: UDP           |\n");
        printf("| Source Port: %-10d |\n", ntohs(udph->source));
        printf("| Dest Port: %-12d |\n", ntohs(udph->dest));
    } else {
        printf("| Protocol: Other (%-5d) |\n", iph->ip_p);
    }
    printf("+------------------------+\n");
}

int main(int argc, char *argv[]) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    pcap_dumper_t *dumpfile;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <output.pcap>\n", argv[0]);
        return EXIT_FAILURE;
    }

    device = argv[1];
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return EXIT_FAILURE;
    }

    // Open the output file
    dumpfile = pcap_dump_open(handle, argv[2]);
    if (dumpfile == NULL) {
        fprintf(stderr, "Could not open dump file: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    printf("Listening on %s...\n", device);
    
    pcap_loop(handle, 0, packet_handler, (u_char *)dumpfile);

    pcap_dump_close(dumpfile);
    pcap_close(handle);

    return EXIT_SUCCESS;
}
