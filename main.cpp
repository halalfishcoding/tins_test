#include <iostream>
#include <tins/tins.h>

using namespace Tins;
using namespace std;

bool callback(const PDU &pdu) {
    // Find the IP layer
    const IP &ip = pdu.rfind_pdu<IP>(); 

    // Find the TCP layer
    const TCP &tcp = pdu.rfind_pdu<TCP>(); 
    cout << ip.src_addr() << ':' << tcp.sport() << " -> " 
         << ip.dst_addr() << ':' << tcp.dport() << endl;
    return true;
}

int main() {
    Sniffer sniffer("eth0");
    sniffer.set_filter("p 80");
    sniffer.sniff_loop(callback);
}