#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int 
ipToInt(char *ip_addr) {
    unsigned int ipInt = 0;

    // Split the Ip address into octets
    int octets[4];
    if (sscanf_s(ip_addr, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        // Handle invalid IP address format
        fprintf(stderr, "Invalid IP address format\n");
        exit(EXIT_FAILURE);
    }

    // Convert and combine octets into the 32-bit integer
    for (int i = 0; i < 4; ++i) {
        if (octets[i] < 0 || octets[i] > 255) {
            // Handle invalid octet values
            fprintf(stderr, "Invalid octed value: %d\n", octets[i]);
            exit(EXIT_FAILURE);
        }
        ipInt = (ipInt << 8) | (unsigned int)octets[i];
    }
    return ipInt;
}

void 
get_broadcast_address(char *ip_addr, int subnet_mask, char *output_buffer) {
    unsigned int ipInt = ipToInt(ip_addr);
    unsigned int mask = (~0) << (32 - subnet_mask);
    unsigned int broadcastAddr = (ipInt | ~mask);

    snprintf(output_buffer, 16, "%u.%u.%u.%u",
             (broadcastAddr >> 24) & 0xFF,
             (broadcastAddr >> 16) & 0xFF,
             (broadcastAddr >> 8) & 0xFF,
             broadcastAddr & 0xFF);
}

int main(void) {
    char output_buffer[16];
    get_broadcast_address("192.168.1.1", 24, output_buffer);

    printf("Broadcast Address: %s\n", output_buffer);

    return 0;
}