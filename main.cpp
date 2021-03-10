#include <tins/tins.h>

using namespace Tins;

bool doo(PDU&) {
    return false;
}

struct foo {
    void bar() {
        SnifferConfiguration config;
        config.set_promisc_mode(true);
        config.set_filter("ip src 35.202.112.104");
        Sniffer sniffer("eth0", config);
        
        sniffer.sniff_loop(make_sniffer_handler(this, &foo::handle));
        // Also valid
        sniffer.sniff_loop(doo);
    }
    
    bool handle(PDU&) {
        // Don't process anything
        return false;
    }
};

int main() {
    foo f;
    f.bar();
}