#include <iostream>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h> 

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header;
    eth_header = (struct ether_header *) packet;

    std::cout << "\n=================================================" << std::endl;
    std::cout << "Packet captured! Length: " << header->len << " bytes" << std::endl;

    printf("Source MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth_header->ether_shost[0], eth_header->ether_shost[1], eth_header->ether_shost[2],
           eth_header->ether_shost[3], eth_header->ether_shost[4], eth_header->ether_shost[5]);

    printf("Dest MAC:   %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth_header->ether_dhost[0], eth_header->ether_dhost[1], eth_header->ether_dhost[2],
           eth_header->ether_dhost[3], eth_header->ether_dhost[4], eth_header->ether_dhost[5]);

    printf("Protocol:   0x%04x\n", ntohs(eth_header->ether_type));
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    
    const char *device = "eth0"; 

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    
    if (handle == nullptr) {
        std::cerr << "Couldn't open device " << device << ": " << errbuf << std::endl;
        return 1;
    }

    std::cout << "Listening on " << device << "..." << std::endl;

    pcap_loop(handle, 10, packet_handler, nullptr);

    pcap_close(handle);
    return 0;
}