#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout << "[DEBUG]\n\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do!\n\n";
}

void	Harl::info(void) {
	std::cout << "[INFO]\n\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put";
	std::cout << " enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void	Harl::warning(void) {
	std::cout << "[WARNING]\n\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for";
	std::cout << " years whereas you started working here since last month.\n\n";
}

void	Harl::error(void) {
	std::cout << "[ERROR]\n\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level) {

	std::string	s[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	t_void functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int	i = 0;
	for (; i < 4; i++) {
		if (s[i] == level)
			break;
	}
	switch (i) {
		case 0:
			while (i < 4) {
				(this->*functions[i])();
				i++;
			}
			break;
		case 1:
			while (i < 4) {
				(this->*functions[i])();
				i++;
			}
			break;
		case 2:
			while (i < 4) {
				(this->*functions[i])();
				i++;
			}
			break;
		case 3:
			while (i < 4) {
				(this->*functions[i])();
				i++;
			}
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}