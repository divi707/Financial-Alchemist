#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

void displayExpenseDetails(const string& expenseName, const unordered_map<string, unordered_map<int, double>>& expenses, const double& expenseBudget, const int dayCount) {
    double totalCategoryExpenses = 0;
    double budgetAmount = expenseBudget; 


    for (int day = 1; day <= dayCount; day++) {
        if (expenses.find(expenseName) != expenses.end() && expenses.at(expenseName).find(day) != expenses.at(expenseName).end()) {
            double expense = expenses.at(expenseName).at(day);
            totalCategoryExpenses += expense;
        }
    }

    double budgetDifference = totalCategoryExpenses - budgetAmount;

    cout << endl << "Expense Details for " << expenseName << endl;
    cout << "Total expenses: " << totalCategoryExpenses << " rs." << endl;
    cout << "Budget: " << budgetAmount << " rs." << endl;

    if (budgetDifference > 0) {
        cout << "You have exceeded your budget by " << std::abs(budgetDifference) << " rs." << endl;
    } else if (budgetDifference < 0) {
        cout << "You have stayed under your budget by " << std::abs(budgetDifference) << " rs." << endl;
    } else {
        cout << "You have spent exactly the amount of your budget." << endl;
    }
}

int main() {

    cout << "Welcome to Financial Alchemist!" << endl;

    string name;
    cout << "Please enter your name: ";
    getline(cin, name);


    unordered_map<string, double> expenseBudgets;


    int dayCount = 4;


    string expenseNames[] = {"Health", "Food", "Education", "Leisure Activities", "Basic Utilities"};


    for (const string& expenseName : expenseNames) {
        double budget;
        do {
            cout << "Enter your budget for " << expenseName << ": ";
            string budgetString;
            getline(cin, budgetString);

            try {
                size_t pos;
                budget = stod(budgetString, &pos);
                if (pos == budgetString.size()) {
                    expenseBudgets[expenseName] = budget; // 
                    break;
                } else {
                    throw invalid_argument("Invalid input. Please enter a number.");
                }
            } catch (const invalid_argument&) {
                cout << "Invalid input. Please enter a number." << endl;
            }
        } while (true);
    }

    unordered_map<string, unordered_map<int, double>> expenses;

    for (int day = 1; day <= dayCount; day++) {
        cout << "--- Day " << day << " Expenses ---" << endl;

        for (const string& expenseName : expenseNames) {
            double expense;
            do {
                cout << "Enter your " << expenseName << " expense for day " << day << ": ";
                string expenseString;
                getline(cin, expenseString);

                try {
                    size_t pos;
                    expense = stod(expenseString, &pos);
                    if (pos == expenseString.size()) {
                        expenses[expenseName][day] = expense; 
                        break;
                    } else {
                        throw invalid_argument("Invalid input. Please enter a number.");
                    }
                } catch (const invalid_argument&) {
                    cout << "Invalid input. Please enter a number." << endl;
                }
            } while (true);
        }
    }


    bool continueMenu = true;
    while (continueMenu) {
        cout << endl << "Expense Category Selection" << endl;
        cout << "1. Health" << endl;
        cout << "2. Food" << endl;
        cout << "3. Education" << endl;
        cout << "4. Leisure Activities" << endl;
        cout << "5. Basic Utilities" << endl;
        cout << "6. Exit" << endl;

        int selection;
        do {
            cout << "Enter expense category for which you want to view details ";
            string selectionString;
            getline(cin, selectionString);

            try {
                selection = stoi(selectionString);
                if (selection >= 1 && selection <= 6) {
                    break;
                } else {
                    throw invalid_argument("Invalid selection. Please enter a number between 1 and 6.");
                }
            } catch (const invalid_argument&) {
                cout << "Invalid selection. Please enter a number between 1 and 6." << endl;
            }
        } while (true);

        switch (selection) {
            case 1:
                cout << endl << "Expense Details for Health" << endl;
                displayExpenseDetails("Health", expenses, expenseBudgets["Health"], dayCount);
                break;

            case 2:
                cout << endl << "Expense Details for Food" << endl;
                displayExpenseDetails("Food", expenses, expenseBudgets["Food"], dayCount);
                break;

                        case 3:
                cout << endl << "Expense Details for Education" << endl;
                displayExpenseDetails("Education", expenses, expenseBudgets["Education"], dayCount);
                break;

            case 4:
                cout << endl << "Expense Details for Leisure Activities" << endl;
                displayExpenseDetails("Leisure Activities", expenses, expenseBudgets["Leisure Activities"], dayCount);
                break;

            case 5:
                cout << endl << "Expense Details for Basic Utilities" << endl;
                displayExpenseDetails("Basic Utilities", expenses, expenseBudgets["Basic Utilities"], dayCount);
                break;

            case 6:
                cout << endl << "Exiting Expense Tracker..." << endl;
                continueMenu = false;
                break;

            default:
                cout << "Invalid selection. Please enter a number between 1 and 6." << endl;
        }
    }

    return 0;
}

