// *******************  Future programmers  تم تطوير هذا النظام بواسطة   *******************
#include <iostream>
#include <string>
#incluMde <cstdlib>  // لاستخدام system("cls")
using namespace std;

// تعريف المتغيرات الأساسية لتخزين بيانات الحساب
long option_Number;          // لمعرفة رقم الاختيار من المستخدم
int answer;
string account_Name;         // اسم الحساب
long long account_ID = 0;    // رقم الحساب
long long entered_ID = 0;    // رقم الحساب الذي يدخله المستخدم للتحقق
double balance = 0;          // رصيد الحساب
double deposit_Amount = 0;   // المبلغ المراد إيداعه
double withdraw_Amount = 0;  // المبلغ المراد سحبه

// ** عمرو فتحي ليثي **: إدارة العرض والتفاعل الأساسي مع المستخدم
void clearScreen()
{
    system("cls");  // مسح الشاشة على Windows لتحسين التجربة البصرية
}

void menu()
{
    cout << "  **************************  Menu  **************************  \n";
    cout << " 1 . Create an account  \n";
    cout << " 2 . Account information  \n";
    cout << " 3 . Check Balance  \n";
    cout << " 4 . Withdraw  \n";
    cout << " 5 . Deposit   \n";
    cout << " 6 . Exit  \n";
}

// ** مينا سمعان **: إنشاء الحساب
void createAccount() {
    cout << " Enter your account Name: \n";
    cin.ignore();
    getline(cin, account_Name);
    cout << " Enter Your account ID: \n";
    cin >> account_ID;
    cout << " Enter your initial balance: \n";
    cin >> balance;
    if (balance < 0) {
        cout << " Balance cannot be negative! \n";
        balance = 0;
    }
    cout << " ** Your account has been created successfully ** \n";
}

// ** اأحمد عزت علي **: عرض معلومات الحساب
void showAccountInfo() {
    cout << "Account Name : " << account_Name << "\n";
    cout << "Account ID : " << account_ID << "\n";
}

// ** عمر أحمد حمدي **: التحقق من الرصيد والإيداع
void checkBalance() {
    cout << " Enter your ID: \n";
    cin >> entered_ID;
    if (entered_ID == account_ID) {
        cout << " Your balance is: " << balance << "\n";
    } else {
        cout << " Your ID is not valid \n";
    }
}

void deposit() {
    cout << " Enter your ID: \n";
    cin >> entered_ID;
    if (entered_ID == account_ID) {
        cout << " Enter the amount to deposit: \n";
        cin >> deposit_Amount;
        if (deposit_Amount <= 0) {
            cout << " Deposit amount not valid \n";
            return;
        }
        balance += deposit_Amount;
        cout << " Deposit completed successfully \n";
        cout << " Now your balance is: " << balance << "\n";
    } else {
        cout << " Your ID is not valid \n";
    }
}

// ** محمد اسامه  **: إدارة عمليات السحب والخروج
void withdraw() {
    cout << " Enter your ID: \n";
    cin >> entered_ID;
    if (entered_ID == account_ID) {
        cout << " Enter the amount to withdraw: \n";
        cin >> withdraw_Amount;
        if (withdraw_Amount <= 0) {
            cout << " Withdraw amount cannot be negative! \n";
            return;
        }
        if (balance >= withdraw_Amount) {
            balance -= withdraw_Amount;
            cout << " Withdraw completed successfully \n";
            cout << " Now your balance is: " << balance << "\n";
        } else {
            cout << " Your balance is less than the amount to be withdrawn \n";
        }
    } else {
        cout << " Your ID is not valid \n";
    }
}

// الوظيفة الرئيسية لمعالجة إدخال المستخدم وتوجيهه إلى العمليات المناسبة
void process() {
    do {
        menu();
        cout << " Enter Option Number between 1 to 6 : \n";
        cin >> option_Number;
        switch (option_Number) {
            case 1: createAccount(); 
            break;
            case 2: showAccountInfo(); 
            break;
            case 3: checkBalance();
            break;
            case 4: withdraw(); 
            break;
            case 5: deposit(); 
            break;
            case 6: cout << " Exiting... \n"; 
            return;
            default: cout << " Invalid option! Please choose a number between 1 and 6. \n"; 
            break;
        }
        cout << " Do you want another transaction? \n";
        cout << " 1. Yes                    2. No \n";
        cin >> answer;
        if (answer != 1) 
        return;
        cout << "\n Press Enter to continue...";
        cin.ignore();
        cin.get();
        clearScreen();
    } while (true);
}

// تشغيل البرنامج
int main() {
    process();
    return 0;
}

/*
       تم انشاء هذا المشروع بواسطة 
       1. Omar Ahmed Hamdy Tawfiq
       2. Amr Fathy Leithy Leithy
       3. Mohammed Osama Mofaddal Fangari
       4. Mina Semaan Nashed Makary
       5. Ahmed Ezzat Ali Khalaf
 */
