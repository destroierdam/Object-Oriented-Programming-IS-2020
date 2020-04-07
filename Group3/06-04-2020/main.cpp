#include <iostream>
#include "User.h"
#include "SocialNetwork.h"

int main()
{
    const User kircho("kirec", "password", "kircho@asd.com", 12);

    User traicho(kircho), pencho, stancho;

    SocialNetwork facebook;

    facebook.addUser(traicho);
    facebook.addUser(kircho);
    facebook.addUser(pencho);

    

}