#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;


//Function prototypes
void welcomeMessage();
void getIncome(double &income, string name);
void getSavings(double &totalSavings);
void getExpense(double &expense, string name);
void calculateMonthlyBudget(double income1, double income2, double income3,  double &budget);
void calculateMonthlyExpenses(double expense1, double expense2, double expense3, double expense4, double expense5, double &monthlyCost);
void outputTotals(double budget, double cost,  double savings);


int main() {
  welcomeMessage();
  cout << fixed << setprecision(2) << endl;
  
  double socialSecurityIncome = 0.00;
  double pensionIncome = 0.00;
  double retirementIncome = 0.00;
  double monthlyBudget = 0.00;
  double totalSavings = 0.00;

  getIncome(socialSecurityIncome, "social security");
  getIncome(pensionIncome, "pension");
  getIncome(retirementIncome, "retirement");

  getSavings(totalSavings);

  calculateMonthlyBudget(socialSecurityIncome, pensionIncome, retirementIncome, monthlyBudget);
  
  double foodExpense = 0.00;
  double housingExpense = 0.00;
  double vehicleExpense = 0.00;
  double medicalExpense = 0.00;
  double tvExpense = 0.00;
  double monthlyExpenses = 0.00;
  
  getExpense(foodExpense, "food");
  getExpense(housingExpense, "rent");
  getExpense(vehicleExpense, "vehicle");
  getExpense(medicalExpense, "medical");
  getExpense(tvExpense, "entertainment");
  
  calculateMonthlyExpenses(foodExpense, housingExpense, vehicleExpense, medicalExpense, tvExpense, monthlyExpenses);

  outputTotals(monthlyBudget, monthlyExpenses, totalSavings);
  
  return 0;
}


void welcomeMessage() {
  cout << "This program tracks your monthly income and expenses." << endl; 
}


void getIncome(double& income, string name) {
  
  double incomeData = 0.00;
  cout << "Please enter your monthly " << name << " income: $";
  cin  >> incomeData;
  while (!cin || incomeData < 0.00) {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter a valid " << name;
    cout << " income of $0.00 or greater: ";
    cin  >> incomeData;
  }
  income = incomeData;
}

 
void getSavings(double& totalSavings){
  
  double savings = 0.00;
  cout << "\nPlease enter your total savings: $"; 
  cin  >> savings; 
  
  while (!cin || savings < 0.00){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter a valid savings or $0.00 for no savings: ";
    cin  >> savings;
  }
  totalSavings = savings; 
}


void calculateMonthlyBudget(double income1, double income2, double income3, double& budget){    
  budget = income1 + income2 + income3;
}


void getExpense(double& expense, string name){
  
  double expenseData = 0.00;
  cout << "Please enter your monthly " << name << " expense: $";
  cin  >> expenseData;
  
  while (!cin || expenseData < 0.00){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter a valid " << name;
    cout << " expense of $0.00 or greater: ";
    cin  >> expenseData;
  }
  expense = expenseData;
}


void calculateMonthlyExpenses(double expense1, double expense2, double expense3, 
double expense4, double expense5, double& cost)
{
  cost = expense1 + expense2 + expense3 + expense4 + expense5; 
}


void outputTotals(double budget, double cost, double savings){
  
  cout << '\n' << "Your total monthly income is: $" << budget << endl;
  cout << "Your total monthly expenses are: $" << cost << endl;
  cout << '\n';
  
  if (budget > cost){
    cout << "You are under budget by: $" << (budget - cost) << endl;
  }
  else if (fabs(budget - cost) < 0.0001){
    cout << "You are at your monthly budget. Consider spending less!";
    cout << endl;
  } 
  else if (budget < cost){
    cout << "You are over budget by: $" << (cost - budget) << endl;
    int months = 0;
    months = savings/(cost - budget);
    months = static_cast<int>(months); 
    cout << "At this rate, your monthly savings of $" << savings 
    << " will last about " << months << " months." << endl;
  }
}