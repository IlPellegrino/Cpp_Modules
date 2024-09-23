#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do!\n";
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
	std::cout << " enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for";
	std::cout << " years whereas you started working here since last month.\n";
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level) {

	std::string	s[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[]) (void)  = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int	i = 0;
	for (; i < 4; i++) {
		if (s[i] == level)
			break;
	}
	if (i < 4) {
		(this->*(functions[i]))();
		return;
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}