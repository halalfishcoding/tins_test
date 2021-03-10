#include <tins/tins.h>
#include <iostream>

using namespace Tins;
using namespace std;

bool doo(PDU&) {
    return false;
}

struct foo {
    void bar() {
        SnifferConfiguration config;
        config.set_promisc_mode(true);
        config.set_filter("ip src 35.202.112.104");
        Sniffer sniffer("eth0", config);
        
        // Also valid
        sniffer.sniff_loop(foo::handle);
    }
    
    bool handle(const PDU &pdu) {
        // Find the IP layer
        const IP &ip = pdu.rfind_pdu<IP>();
        // Find the TCP layer
        const TCP &tcp = pdu.rfind_pdu<TCP>();
        cout << ip.src_addr() << ':' << tcp.sport() << " -> " << ip.dst_addr() << ':' << tcp.dport() << endl;
        return true;
    }
};

int main() {
    foo f;
    f.bar();
}