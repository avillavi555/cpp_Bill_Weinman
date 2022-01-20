// union.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <cstdint>

union ipv4 {
    uint32_t i32;
    struct {
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
    } octets;
};

int main()
{
    union ipv4 addr;
    addr.octets = { 192, 168, 73, 42 };
    printf("addr is %d.%d.%d.%d is %08x\n",
           addr.octets.a, addr.octets.b, addr.octets.c, addr.octets.d, addr.i32 );

    union ipv4 addr1;
    addr1.octets.a = 110;
    addr1.octets.b = 120;
    addr1.octets.c = 130;
    addr1.octets.d = 140;
    printf("addr is %d.%d.%d.%d is %08x\n",
        addr1.octets.a, addr1.octets.b, addr1.octets.c, addr1.octets.d, addr1.i32);
    printf("sizeof bool: %zd bits\n", sizeof(ipv4) * 8);


    return 0;
}
