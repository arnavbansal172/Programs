from collections import defaultdict

def calculate_interest(principal, weeks):
    interest_rate = 0.12 / 52  
    interest = principal * (1 + interest_rate)**weeks - principal
    return round(interest, 2)

def settle_expenses(expenses, balances):
    total_expense = sum(expenses.values())
    share_per_person = total_expense / len(balances)

    for person, amount in balances.items():
        balances[person] -= share_per_person

def reconcile_loans(loans, balances):
    sorted_loans = sorted(loans, key=lambda x: (loans[x]['lender'], x))

    for borrower in sorted_loans:
        for lender, amount in loans[borrower]['amounts'].items():
            if balances[borrower] >= amount:
                balances[borrower] -= amount
                balances[lender] += amount
                loans[borrower]['amounts'][lender] = 0
            else:
                loans[borrower]['amounts'][lender] -= balances[borrower]
                balances[lender] += balances[borrower]
                balances[borrower] = 0
                break

def process_transaction(transaction, expenses, loans, balances, week):
    try:
        if transaction[0] == 'L':
            lender, borrower, amount = transaction[2:].split('/')
            amount = int(amount)
            
            if borrower not in loans:
                loans[borrower] = {'lender': lender, 'amounts': defaultdict(int)}
            
            loans[borrower]['amounts'][lender] += amount
            loans[borrower]['week'] = week
        else:
            payer, amounts = transaction.split('/', 1)
            amounts = amounts.split('/')
            paid_amount = int(amounts[0])
            recipients = amounts[1:]

            for recipient in recipients:
                expenses[payer] += paid_amount / len(recipients)
                balances[recipient] += paid_amount / len(recipients)

                if payer in loans and loans[payer]['week'] == week:
                    for lender, amount in loans[payer]['amounts'].items():
                        if balances[payer] >= amount:
                            balances[payer] -= amount
                            balances[lender] += amount
                            loans[payer]['amounts'][lender] = 0
                        else:
                            loans[payer]['amounts'][lender] -= balances[payer]
                            balances[lender] += balances[payer]
                            balances[payer] = 0
                            break
    except (ValueError, IndexError):
        raise ValueError("Invalid transaction format: " + transaction)

def main():
    try:
        n = int(input())
        transactions = [input().strip() for _ in range(n)]

        week = 1
        expenses = defaultdict(int)
        loans = {}
        balances = defaultdict(int)

        for transaction in transactions:
            process_transaction(transaction, expenses, loans, balances, week)
            week += 1

            for borrower in loans.copy():
                if week - loans[borrower]['week'] > 1:
                    for lender, amount in loans[borrower]['amounts'].items():
                        interest = calculate_interest(amount, week - loans[borrower]['week'])
                        loans[borrower]['amounts'][lender] += interest
                        loans[borrower]['week'] = week

        settle_expenses(expenses, balances)
        reconcile_loans(loans, balances)

        dues = [(payer, recipient, round(amount, 2)) for payer, recipient, amount in sorted([(payer, recipient, amount) for payer, recipient, amount in balances.items() if amount != 0])]

        if dues:
            for payer, recipient, amount in dues:
                print(f"{payer}/{recipient}/{amount}")
        else:
            print("NO DUES.")

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
