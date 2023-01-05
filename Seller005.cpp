#include <bits/stdc++.h>
#include "Seller.h"
#include "Seller005.h"
#include "Products.h"

Seller005::Seller005(string id) : Seller(id){};

void Seller005::add_platform(Platform *thePlatform)
{
    thePlatform->add_seller(this);
}

vector<Products *> Seller005::find_products(Globals::Category categoryName)
{
    vector<Products *> filterList;
    for (auto prod : product_list)
    {
        if (prod->get_category() == categoryName)
        {
            filterList.push_back(prod);
        }
    }
    return filterList;
}

bool Seller005::buy_product(string productId, int qty)
{
    int inventory = 0;
    for (auto prod : product_list)
    {
        if (prod->get_product_id() == productId)
        {
            inventory++;
        }
    }
    if (inventory < qty)
    {
        return false;
    }
    int remaining = qty - inventory;
    vector<Products *> updatedList;
    while (remaining)
    {
        for (auto prod : product_list)
        {
            if (prod->get_product_id() == productId)
            {
                updatedList.push_back(prod);
                remaining--;
            }
            else
            {
                updatedList.push_back(prod);
            }
        }
    }
    product_list = updatedList;
    return true;
}
