#include <iostream>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

class Loan {
public:
    std::string lender;
    std::unordered_map<std::string, int> amounts{};
    int week;
};

double calculateInterest(int principal, int weeks) {
    double interestRate = 0.12 / 52;
    double interest = principal * (std::pow((1 + interestRate), weeks) - 1);
    return std::round(interest * 100) / 100;
}

void settleExpenses(std::unordered_map<std::string, int>& expenses, std::unordered_map<std::string, double>& balances) {
    double totalExpense = 0;
    for (const auto& person : balances) {
        totalExpense += person.second;
    }

    double sharePerPerson = totalExpense / balances.size();

    for (auto& person : balances) {
        person.second -= sharePerPerson;
    }
}

void reconcileLoans(std::vector<std::tuple<std::string, std::string, double>>& dues,
                    std::unordered_map<std::string, Loan>& loans,
                    std::unordered_map<std::string, double>& balances) {
    for (const auto& due : dues) {
        std::string borrower = std::get<0>(due);
        std::string lender = std::get<1>(due);
        double amount = std::get<2>(due);

        if (loans.find(borrower) != loans.end()) {
            for (const auto& loanAmount : loans[borrower].amounts) {
                if (balances[borrower] >= loanAmount.second) {
                    balances[borrower] -= loanAmount.second;
                    balances[loanAmount.first] += loanAmount.second;
                    loans[borrower].amounts[loanAmount.first] = 0;
                } else {
                    loans[borrower].amounts[loanAmount.first] -= balances[borrower];
                    balances[loanAmount.first] += balances[borrower];
                    balances[borrower] = 0;
                    break;
                }
            }
        } else if (!lender.empty()) {
            balances[borrower] -= amount;
            balances[lender] += amount;
        }
    }
}

void processTransaction(const std::string& transaction, std::unordered_map<std::string, int>& expenses,
                        std::vector<std::tuple<std::string, std::string, double>>& dues,
                        std::unordered_map<std::string, Loan>& loans, std::unordered_map<std::string, double>& balances, int week) {
    try {
        if (transaction[0] == 'L') {
            std::istringstream iss(transaction.substr(2));
            std::string lender, borrower;
            int amount;
            char delimiter;
            iss >> lender >> delimiter >> borrower >> delimiter >> amount;

            if (loans.find(borrower) == loans.end()) {
                loans[borrower] = Loan{.lender = lender, .week = week};
            }

            loans[borrower].amounts[lender] += amount;
        } else {
            std::istringstream iss(transaction.substr(2));
            std::string payer, recipients;
            int paidAmount;
            char delimiter;
            iss >> payer >> delimiter >> paidAmount >> recipients;

            std::istringstream recipientsStream(recipients);
            std::string recipient;
            while (getline(recipientsStream, recipient, '/')) {
                expenses[payer] += paidAmount / recipients.size();
                balances[recipient] += paidAmount / recipients.size();

                if (loans.find(payer) != loans.end() && loans[payer].week == week) {
                    for (const auto& amount : loans[payer].amounts) {
                        if (balances[payer] >= amount.second) {
                            balances[payer] -= amount.second;
                            balances[amount.first] += amount.second;
                            loans[payer].amounts[amount.first] = 0;
                        } else {
                            loans[payer].amounts[amount.first] -= balances[payer];
                            balances[amount.first] += balances[payer];
                            balances[payer] = 0;
                            break;
                        }
                    }
                }
            }
        }
    } catch (const std::exception& e) {
        throw std::invalid_argument("Invalid transaction format: " + transaction);
    }
}

int main() {
    try {
        int n;
        std::cin >> n;
        std::cin.ignore();

        std::vector<std::string> transactions;
        for (int i = 0; i < n; ++i) {
            std::string transaction;
            std::getline(std::cin, transaction);
            transactions.push_back(transaction);
        }

        int week = 1;
        std::unordered_map<std::string, int> expenses;
        std::unordered_map<std::string, Loan> loans;
        std::unordered_map<std::string, double> balances;
        std::vector<std::tuple<std::string, std::string, double>> dues;

        for (const auto& transaction : transactions) {
            processTransaction(transaction, expenses, dues, loans, balances, week);
            ++week;
        }

        settleExpenses(expenses, balances);
        reconcileLoans(dues, loans, balances);

        std::sort(dues.begin(), dues.end(), [](const auto& a, const auto& b) {
            return std::get<0>(a) < std::get<0>(b);
        });

        bool hasDues = false;
        for (const auto& due : dues) {
            if (std::get<2>(due) != 0) {
                std::cout << std::get<0>(due) << "/" << std::get<1>(due) << "/" << std::get<2>(due) << std::endl;
                hasDues = true;
            }
        }

        if (!hasDues) {
            std::cout << "NO DUES." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
