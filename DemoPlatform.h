#ifndef DEMO_PLATFORM
#define DEMO_PLATFORM

#include "Platform.h"
#include <bits/stdc++.h>
#include "Seller.h"

using namespace std;

class DemoPlatform : public Platform {
private:
    string file_open_mode = "w";
public:
    bool add_seller (Seller* seller) override;
    void process_requests() override;
};

#endif