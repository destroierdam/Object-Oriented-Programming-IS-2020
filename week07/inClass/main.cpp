#include <iostream>
#include <algorithm>
#include "User.h"
#include "SocialNetwork.h"

bool compare(const User & left, const User & right) {
	return left.getAge() < right.getAge();
}

int main() {
    User traicho, kircho, pencho;
	traicho.setAge(15);
	kircho.setAge(21);
	
    SocialNetwork twitter;
	
	twitter.addUser(traicho).addUser(kircho);
	
	traicho < kircho;
	
	// traicho << cout;
	
	std::cout << traicho << kircho;
	
	
	User arrUsers[] = {traicho, kircho, pencho};
	std::sort(arrUsers, arrUsers + 3, 
		[](const User & left, const User & right) -> bool {
			return left.getAge() < right.getAge();
		}
	);
	
	// {kircho, traicho, pencho} // kircho < traicho, traicho < pencho

}
