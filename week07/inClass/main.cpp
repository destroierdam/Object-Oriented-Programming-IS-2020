#include <iostream>
#include <algorithm>
#include "User.h"
#include "SocialNetwork.h"
using namespace std;

bool compare(const User & left, const User & right) {
	return left.getAge() < right.getAge();
}

int main() {
    User traicho, kircho;
	traicho.setAge(15);
	kircho.setAge(21);
	
    SocialNetwork twitter;
	
	twitter.addUser(traicho).addUser(kircho);
	
	traicho < kircho;
	
	traicho << cout;
	
	cout << traicho << kircho;
	
	
	User arrUsers[] = {traicho, kircho, pencho};
	sort(arrUsers, arrUsers + 2, 
		[](const User & left, const User & right) -> bool {
			return left.getAge() < right.getAge();
		}
	);
	
	{kircho, traicho, pencho} // kircho < traicho, traicho < pencho
	
	
}
