#include "Account.hpp"

int Account::_nbAccounts = 0, Account::_totalAmount = 0, Account::_totalNbDeposits = 0, Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created\n";
	_totalAmount += initial_deposit;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit(int Deposit) {
	_displayTimestamp();
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "index:" << _accountIndex
		  << ";p_amount:" << _amount
		  << ";deposit:" << Deposit
		  << ":amount:" << _amount + Deposit
		  << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += Deposit;
	_totalAmount += Deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > _amount) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";withdrawal:refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		  << ";p_amount:" << _amount
		  << ";withdrawal:" << withdrawal
		  << ":amount:" << _amount - withdrawal
		  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return true;
}

int	Account::checkAmount(void) const {
	return this->_amount;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
	char	buf[80];

	time_t	now = time(NULL);

	tm* localTime = localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", localTime);

	std::cout << buf;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

