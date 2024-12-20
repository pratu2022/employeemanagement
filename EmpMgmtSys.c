#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h> 
#include <stdbool.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define EMPLOYEES_PER_PAGE 2
#define MAX_EMPLOYEES 100

#define DEPARTMENTS_PER_PAGE 2
#define MAX_DEPARTMENTS 100

#define PROJECTS_PER_PAGE 2
#define MAX_PROJECTS 100


void displayIntroduction();
void displayWelcomeMessage();
void Admin_login();
void Employee_login();
void HR_login();
void ChangeEmployeePassword(int empId);
void requestLeave(int emp_id);
void markAttendance(int emp_id, char *emp_name);
void viewAssignedProjects(char *empName);
void calculatePayroll(int emp_id);
void viewSalarySlip(int emp_id);
void display_Department();
void display_Employee();
void Add_Dept();
void Manage_Department();
void Manage_Employee();
void Manage_Project();
void AttendanceList();
void approveLeave(int emp_id);
void viewLeaveBalance(int emp_id);
void sort_Employee();
void sort_Department();
void sort_Project();
void removeDept();
void removeEmp();
void removeProject();
void searchDept();
void searchEmp();
void searchProject();
void searchDeptName();
void searchEmpName();
void SalaryWiseDisplay();
void CostWiseDisplay();
void displayLeaveRequests();
void displayAttendanceList();
void displayPayroll();
void viewEmployeeList();
void viewLeaveBalances();
void DepartmentModify();
void Add_Emp();
void EmployeeModify();
void Add_Project();
void DisplayProject();
void ProjectModify();

//Department Structure
struct Department
{
	int  Dept_id;
	char Dept_name[50];
	char Location[50]; 
	char Regitered_date[12];
};
struct Department d; 

//Employee Structure
struct Employee
{
	int Emp_id;
	char Emp_name[50];
	char Emp_Gender[30];
	int  Emp_Age;
	char  Emp_Contact[12];
	float  Base_Salary;
	int hoursWorked;  
	char Emp_Role[50];
	char Emp_Email[50];
	char Emp_Password[50]; 
	int  annualLeave;
	int  sickLeave;
	int  casualLeave;
	char Regitered_date[12];
};
struct Employee e; 

//Project Structure
struct Project
{
	int Pro_id;
	char Pro_Name[30];
	float Project_cost;
	char Emp_Name[30];
	char Regitered_date[12];
};
struct Project p; 


// Attendance Structure
struct Attendance{
	int Emp_id;
	char Emp_name[50];
	char date[12];
	char status[10];
};


// Payroll Structure
struct Payroll {
    int Emp_id;
    float baseSalary;
    int hoursWorked;
    float allowances;
    float deductions;
    float grossPay;
    float netPay;
};

typedef struct {
    int Emp_id;
    char type[20];       // Leave type: "Annual", "Sick", "Casual"
    char startDate[12];
    char endDate[12];
    char status[10];     // Status: "Pending", "Approved", "Rejected"
} LeaveRequest;

FILE *fp;

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

void displayIntroduction() {
    system("cls"); // For Windows, use "clear" on Linux

    // Draw a border
    printf(ANSI_COLOR_CYAN "\n\n\n\t\t\t+--------------------------------------------------------------------------------+\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "" ANSI_COLOR_RESET "                           " ANSI_COLOR_YELLOW "\t\t\t Welcome to the" ANSI_COLOR_RESET "                             " ANSI_COLOR_CYAN "\n");
    printf(ANSI_COLOR_CYAN "" ANSI_COLOR_RESET "                        " ANSI_COLOR_GREEN "\t\t\t Employee Management System" ANSI_COLOR_RESET "                       " ANSI_COLOR_CYAN "\n");
    printf(ANSI_COLOR_CYAN "\t\t\t+--------------------------------------------------------------------------------+\n\n" ANSI_COLOR_RESET);

	 printf(ANSI_COLOR_CYAN "\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\t\t\t                                    SCET MCA									    " ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n" ANSI_COLOR_RESET);

    // Animated intro
    delay(500);
    printf(ANSI_COLOR_MAGENTA "\t\t\t                     *************************************\n" ANSI_COLOR_RESET);
    delay(500);
    printf(ANSI_COLOR_MAGENTA "\t\t\t                     *           Presented By:           *\n" ANSI_COLOR_RESET);
    delay(500);
    printf(ANSI_COLOR_MAGENTA "\t\t\t                     *           Bendre Pratiksha        *\n" ANSI_COLOR_RESET);
    delay(500);
    printf(ANSI_COLOR_MAGENTA "\t\t\t                     *           Gurav Smital            *\n" ANSI_COLOR_RESET);
    delay(500);
    printf(ANSI_COLOR_MAGENTA "\t\t\t                     *           Patel Twincy            *\n" ANSI_COLOR_RESET);
    delay(500);
    printf(ANSI_COLOR_MAGENTA "\t\t\t                     *           Sachan Siya             *\n" ANSI_COLOR_RESET);
    delay(500);
    printf(ANSI_COLOR_MAGENTA "\t\t\t                     *************************************\n" ANSI_COLOR_RESET);

    delay(1000); // Delay before showing the main text
    printf("\n");
    // Footer Message
    printf(ANSI_COLOR_CYAN "\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\t\t\t                              Press Any Key to Continue... " ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n" ANSI_COLOR_RESET);

    getch(); // Wait for a key press
}


void displayWelcomeMessage() {
    system("cls");  // Clear the screen

    printf("\n\n\n");
    printf(ANSI_COLOR_CYAN"\t\t\t#####################################################################\n");
    printf("\t\t\t#                                                                   #\n");
    printf("\t\t\t#      :::::::::::: Employee Management System (EMS) ::::::::::::   #\n");
    printf("\t\t\t#                                                                   #\n");
    printf("\t\t\t#####################################################################\n" ANSI_COLOR_RESET);
    printf("\n\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t**************************************************\n");
    printf("\t\t\t\t*                                                *\n");
    printf("\t\t\t\t*            System Loading, Please Wait...      *\n");
    printf("\t\t\t\t*                                                *\n");
    printf("\t\t\t\t**************************************************\n"ANSI_COLOR_RESET);

}

void main()
{
	displayIntroduction();
	displayWelcomeMessage();
	Sleep(5000); 
	
	int choice;
	while(1)
	{
		system("cls");
		printf(ANSI_COLOR_CYAN"\t\t\t=====================================================================");
		printf("\n\n\n");
		printf("\t\t\t>>>>>>>>>>>>>>>>>>>>> Employee Management System >>>>>>>>>>>>>>>>>>>>>");
		printf("\n\n\n");
		printf("\t\t\t======================================================================\n"ANSI_COLOR_RESET);
		
		printf("\n\t\t\t======================================================================\n");
		printf("\n\t\t\t\t\t\t 1.Login as Admin\n");
		printf("\t\t\t\t\t\t 2.Login as Employee\n");
		printf("\t\t\t\t\t\t 3.Login as HR\n");
		printf("\n\t\t\t======================================================================");
		printf("\n\t\t\t Enter Your Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0:
				exit(0);
			case 1:
				Admin_login();
				break;
			case 2:
				Employee_login();
				break;
			case 3:
				HR_login();
				break;
			default:
				printf("Invalid Choice");
		}
		
		printf(ANSI_COLOR_GREEN"\n\n Press Any Key to continue....... "ANSI_COLOR_RESET);
		getch();
	
		
	}
		
	}
	
//*********************************************** Start Of Admin Login ***************************************************	

void getPassword(char *password, int maxLength) {
    int index = 0;
    char ch;

    while (1) {
        ch = getch(); // Read a character without displaying it

        if (ch == 13) { // Enter key is pressed
            password[index] = '\0'; // Null terminate the string
            break;
        } else if (ch == 8) { // Backspace key is pressed
            if (index > 0) {
                index--;
                printf("\b \b"); // Move cursor back, print space, move back again
            }
        } else {
            if (index < maxLength - 1) { // Ensure not to exceed buffer size
                password[index++] = ch; // Store the character in the password array
                printf("*"); // Print asterisk for each character
            }
        }
    }
    printf("\n"); // Move to the next line after entering the password
}

void Admin_login()
{
		char email[20];
		char password[20];
		int isLogin = 1;
		char ch;
		
		while(1)
		{
			printf("\t\t\t Enter Email :: ");
			scanf("%s",&email);
			printf("\t\t\t Enter  Password:: ");
			fflush(stdin);
			getPassword(password, sizeof(password));
			
		
			if(strcmp("admin@gmail.com",email) == 0 && strcmp("admin", password)== 0)
			{
			
			system("cls");
			

			int choice;
			while(1)
			{
				printf(ANSI_COLOR_CYAN"\t\t\t=====================================================================");
				printf("\n\n");
				printf("\t\t\t>>>>>>>>>>>>>>>>>>>>> Employee Management System >>>>>>>>>>>>>>>>>>>>>");
				printf("\n\n");
				printf("\t\t\t======================================================================\n"ANSI_COLOR_RESET);
				printf("\n\t\t\t:::::::::::::::::::::::::: Admin Panel ::::::::::::::::::::::::::::::\n");
				printf("\t\t\t======================================================================\n");
				printf("\n\n\n\t\t\t\t\t 1.Manage Department\n");
				printf("\t\t\t\t\t 2.Manage Employee\n");
				printf("\t\t\t\t\t 3.Manage Project\n");
				printf("\t\t\t\t\t 4.Logout\n");
				printf("\t\t\t\t\t 0.Exit\n");
				printf("\n\t\t\t Enter Your Choice: ");
				scanf("%d",&choice);
				
				switch(choice)
				{
					case 0:
						exit(0);
					case 1:
						system("cls");
						Manage_Department();
						break;
					case 2:
						system("cls");
						Manage_Employee();
						break;
					case 3:
						system("cls");
						Manage_Project();
						break;
					case 4:
						isLogin = 0;
						system("cls");
						printf("Logging out...\n"); 
						return;
					default:
						printf("Invalid Choice\n");	
				}
			}
			}
			else
			{
			printf(ANSI_COLOR_RED"\n\t\t\t INCORRECT USERNAME & PASSWORD!!\n"ANSI_COLOR_RESET);
			return;
			}
		}
		
}

//*********************************************** End Of Admin Login ******************************************************	
	
//*********************************************** Start Of Employee Login ***************************************************	

void Employee_login()
{
		char email[20];
		char password[20];
		int isLogin = 1;
		int isAuthentication = 1;
		int eid = 0;
		
		while(isLogin)
		{	
		printf("\t\t\t Enter Email :: ");
		scanf("%s",&email);
		printf("\t\t\t Enter  Password:: ");
		getPassword(password, sizeof(password));

		
		fp = fopen("Employee.txt","rb");
		while(fread(&e, sizeof(e), 1, fp) == 1)
		{
			
		if(strcmp(email,e.Emp_Email) == 0 && strcmp(password,e.Emp_Password)== 0 && strcmp("employee",e.Emp_Role) == 0 )
		{
			
			system("cls");
			printf(ANSI_COLOR_CYAN"\t\t\t=====================================================================");
			printf("\n\n");
			printf("\t\t\t>>>>>>>>>>>>>>>>>>>>> Employee Management System >>>>>>>>>>>>>>>>>>>>>");
			printf("\n\n");
			printf("\t\t\t======================================================================\n"ANSI_COLOR_RESET);
			printf("\n\t\t\t:::::::::::::::::::::::::: Employee Panel :::::::::::::::::::::::::::\n");
			printf("\t\t\t======================================================================\n");

			int choice;
			while(1)
			{
				printf("\n\n\n\t\t\t\t\t 1.View Assign Project\n");
				printf("\t\t\t\t\t 2.Mark Attendance\n");
				printf("\t\t\t\t\t 3.Request Leave\n");
				printf("\t\t\t\t\t 4.View Leave Balance\n");
				printf("\t\t\t\t\t 5.Salary Slip\n");
				printf("\t\t\t\t\t 6.Profile\n");
				printf("\t\t\t\t\t 7.Change Password\n");
				printf("\t\t\t\t\t 8.Logout\n");
				printf("\t\t\t\t\t 0.Exit\n");
				printf("\n\t\t\t Enter Your Choice: ");
				scanf("%d",&choice);
				
				
				switch(choice)
				{
					case 0:
						exit(0);
					case 1:
						system("cls");
						viewAssignedProjects(e.Emp_name);
						break;
					case 2:
						system("cls");
						markAttendance(e.Emp_id, e.Emp_name);
						break;
					case 3:
						system("cls");
						requestLeave(e.Emp_id);
						break;
					case 4:
						system("cls");
						viewLeaveBalance(e.Emp_id);
						break;
					case 5:
						system("cls");
						viewSalarySlip(e.Emp_id);
						break;
					case 6:
							system("cls");
							printf("\n\t\t\t======================= Employee ID : %d =========================\n\n",e.Emp_id);
							printf("\t\t\t\tEmployee ID         -   %d\n",e.Emp_id);
							printf("\t\t\t\tEmployee Name       -   %s\n",e.Emp_name);
							printf("\t\t\t\tEmployee Gender     -   %s\n",e.Emp_Gender);
							printf("\t\t\t\tEmployee Age        -   %d\n",e.Emp_Age);
							printf("\t\t\t\tEmployee Contact    -   %d\n",e.Emp_Contact);
							printf("\t\t\t\tEmployee Email      -   %s\n",e.Emp_Email);
							printf("\t\t\t\tDate of Registration-   %s\n",e.Regitered_date);
							printf("\n\t\t\t==================================================================\n");
						break;
					case 7:
						system("cls");
						ChangeEmployeePassword(e.Emp_id);
						break;
					case 8:
							isLogin = 0;
							system("cls");
							printf("Logging out...\n"); 
							return;
					default:
						printf("Invalid Choice\n");	
				}
			}
		}
		else
		{
			isAuthentication = 0;
		}
		
	}
	
	fclose(fp);
	
	if(isAuthentication == 0)
	{
		printf(ANSI_COLOR_RED"\n\t\t\t INCORRECT LOGIN !!\n"ANSI_COLOR_RESET);
		return;
	}
}
	
}

void ChangeEmployeePassword(int empId) {
    FILE *fp = fopen("Employee.txt", "r+b"); // Open in read-write binary mode
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    int found = 0;
    char currentPassword[20], newPassword[20], confirmPassword[20];
    
    // Find the employee with the specified ID
    while (fread(&e, sizeof(e), 1, fp) == 1) {
        if (e.Emp_id == empId) {
            found = 1;

            // Prompt for current password to verify identity
            printf("Enter current password: ");
            scanf("%s", currentPassword);

            // Verify current password
            if (strcmp(currentPassword, e.Emp_Password) == 0) {
                // Prompt for new password and confirmation
                printf("Enter new password: ");
                scanf("%s", newPassword);
                printf("Confirm new password: ");
                scanf("%s", confirmPassword);

                // Check if the new password and confirmation match
                if (strcmp(newPassword, confirmPassword) == 0) {
                    // Update the password in the struct
                    strcpy(e.Emp_Password, newPassword);
                    // Move file pointer back to the start of the current record
                    fseek(fp, -sizeof(e), SEEK_CUR);

                    // Write the updated employee record to the file
                    fwrite(&e, sizeof(e), 1, fp);

                    printf(ANSI_COLOR_GREEN"Password changed successfully.\n"ANSI_COLOR_RESET);
                } else {
                    printf(ANSI_COLOR_RED"New password and confirmation do not match. Please try again.\n"ANSI_COLOR_RESET);
                }
            } else {
                printf(ANSI_COLOR_RED"Incorrect current password.\n"ANSI_COLOR_RESET);
            }
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }

    fclose(fp);
}

void requestLeave(int emp_id) {
    LeaveRequest leave;
    FILE *fp;

    leave.Emp_id = emp_id;
    printf("\n\t\t\t\t Enter Leave Type (Annual/Sick/Casual): ");
    scanf("%s", leave.type);
    printf("\t\t\t\t Enter Start Date (dd-mm-yyyy): ");
    scanf("%s", leave.startDate);
    printf("\t\t\t\t Enter End Date (dd-mm-yyyy): ");
    scanf("%s", leave.endDate);
    strcpy(leave.status, "Pending");

    fp = fopen("LeaveRequests.txt", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&leave, sizeof(leave), 1, fp);
    fclose(fp);

    printf(ANSI_COLOR_YELLOW"\t\t\t\t Leave request submitted successfully and is pending approval.\n"ANSI_COLOR_RESET);
}



void markAttendance(int emp_id , char *emp_name)
{
	FILE *fa;
	struct Attendance attendance;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	//get the current date
	sprintf(attendance.date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	
	attendance.Emp_id = emp_id;
	strcpy(attendance.Emp_name,emp_name);
	strcpy(attendance.status,"Present");
	
	fa = fopen("Attendance.txt","ab");
	if(fa == NULL)
	{
		printf(ANSI_COLOR_RED"Error opening Attendance file!"ANSI_COLOR_RESET);
		return;
	}
	
	fwrite(&attendance,sizeof(attendance),1,fa);
	fclose(fa);
	
	printf(ANSI_COLOR_GREEN"\n\t\t\t Attendance marked for %s on %s as Present.\n"ANSI_COLOR_RESET, emp_name, attendance.date);

}

void viewAssignedProjects(char *empName) {
    FILE *fp = fopen("Project.txt", "rb");
    if (fp == NULL) {
        printf(ANSI_COLOR_RED"Error opening Project file!"ANSI_COLOR_RESET);
        return;
    }

    int found = 0;
    printf("\n\t\t\t======================= Assigned Projects =========================\n\n");
    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (strcmp(empName, p.Emp_Name) == 0) {
            found = 1;
            printf("\t\t\t Project ID       - %d\n", p.Pro_id);
            printf("\t\t\t Project Name     - %s\n", p.Pro_Name);
            printf("\t\t\t Project Cost     - %.2f\n", p.Project_cost);
            printf("\t\t\t Registered Date  - %d\n", p.Regitered_date);
            printf("\n\t\t\t---------------------------------------------------------------\n");
        }
    }

    if (!found) {
        printf(ANSI_COLOR_RED"\t\t\tNo projects assigned to you.\n"ANSI_COLOR_RESET);
    }

    fclose(fp);
}

//*********************************************** End Of Employee Login ******************************************************	

//*********************************************** Start Of HR Login ***************************************************	

void HR_login()
{
		char email[20];
		char password[20];
		int isLogin = 1;
		int isAuthentication = 1;
		int eid = 0;
		
		while(isLogin)
		{

		printf("\t\t\t Enter Email :: ");
		scanf("%s",&email);
		printf("\t\t\t Enter  Password:: ");
		getPassword(password, sizeof(password));

		
		fp = fopen("Employee.txt","rb");
		while(fread(&e, sizeof(e), 1, fp) == 1)
		{
			
		if(strcmp(email,e.Emp_Email) == 0 && strcmp(password,e.Emp_Password)== 0 && strcmp("HR",e.Emp_Role) == 0 )
		{
			
			system("cls");
			printf(ANSI_COLOR_CYAN"\t\t\t=====================================================================");
			printf("\n\n");
			printf("\t\t\t>>>>>>>>>>>>>>>>>>>>> Employee Management System >>>>>>>>>>>>>>>>>>>>>");
			printf("\n\n");
			printf("\t\t\t======================================================================\n"ANSI_COLOR_RESET);
			printf("\n\t\t\t:::::::::::::::::::::::::: HR Panel ::::::::::::::::::::::::::::::::\n");
			printf("\t\t\t======================================================================\n");

			int choice;
			int emp_id;
			while(1)
			{
				printf("\n\n\n\t\t\t\t\t 1.Calculate Payroll \n");
				printf("\t\t\t\t\t 2.View Salary Slip\n");
				printf("\t\t\t\t\t 3.View Employee List\n");
				printf("\t\t\t\t\t 4.Make Attendance\n");
				printf("\t\t\t\t\t 5.View All Attendance\n");
				printf("\t\t\t\t\t 6.View Employee Leave (Approve / Reject)\n");
				printf("\t\t\t\t\t 7.View Leave Balance\n");
				printf("\t\t\t\t\t 8.Change Password\n");
				printf("\t\t\t\t\t 9.Profile\n");
				printf("\t\t\t\t\t 10.Logout\n");
				printf("\t\t\t\t\t 0.Exit\n");
				printf("\n\t\t\t Enter Your Choice: ");
				scanf("%d",&choice);
				
				
				switch(choice)
				{
					case 0:
						exit(0);
					case 1:
						system("cls");
						printf("\t\t\t Enter Employee ID for Payroll Calculation: ");
		                scanf("%d", &emp_id);
		                calculatePayroll(emp_id);
						break;
					case 2:
						system("cls");
						printf("\t\t\t Enter Employee ID to View Salary Slip: ");
		                scanf("%d", &emp_id);
		                viewSalarySlip(emp_id);
						break;
					case 3:
						system("cls");
						display_Employee();
						break;
					case 4:
						system("cls");
						markAttendance(e.Emp_id, e.Emp_name);
						break;
						case 5:
						system("cls");
						AttendanceList();
						break;
						case 6:
							system("cls");
							printf("Enter Employee ID to Approve/Reject Leave: ");
			                scanf("%d", &emp_id);
			                approveLeave(emp_id);
							break;
						case 7:
							system("cls");
							printf("Enter Employee ID to View Leave Balance: ");
				            scanf("%d", &emp_id);
				            viewLeaveBalance(emp_id);
				            break;
				        case 8:
				        	system("cls");
				        	ChangeEmployeePassword(e.Emp_id);
				        	break;
						case 9:
							system("cls");
							printf("\n\t\t\t======================= Employee ID : %d =========================\n\n",e.Emp_id);
							printf("\t\t\t\tEmployee ID         -   %d\n",e.Emp_id);
							printf("\t\t\t\tEmployee Name       -   %s\n",e.Emp_name);
							printf("\t\t\t\tEmployee Gender     -   %s\n",e.Emp_Gender);
							printf("\t\t\t\tEmployee Age        -   %d\n",e.Emp_Age);
							printf("\t\t\t\tEmployee Contact    -   %d\n",e.Emp_Contact);
							printf("\t\t\t\tEmployee Email      -   %s\n",e.Emp_Email);
							printf("\t\t\t\tDate of Registration-   %s\n",e.Regitered_date);
							printf("\n\t\t\t==================================================================\n");
							break;
						case 10:
							isLogin = 0;
							system("cls");
							printf("Logging out...\n"); 
							return;
					default:
						printf("Invalid Choice");	
				}
			}
		}
		else
		{
			isAuthentication = 0;
		}
	}	
		fclose(fp);
		if(isAuthentication == 0)
		{
			printf(ANSI_COLOR_RED"\n\t\t\t INCORRECT LOGIN !!\n"ANSI_COLOR_RESET);
			return;
		}
}
}


void viewLeaveBalance(int emp_id) {
    FILE *fp_balance;
    int id, balance;
    char name[50], leaveType[20];
    int found = 0;

    fp_balance = fopen("LeaveBalances.txt", "r");
    if (fp_balance == NULL) {
        printf("Error: Could not open LeaveBalances.txt.\n");
        return;
    }

    printf("\n\t\t\t=================== Leave Balance for Employee ID: %d ===================\n", emp_id);

    // Read each line in LeaveBalances.txt and check if it matches the employee ID
    while (fscanf(fp_balance, "Emp ID: %d, Name: %49[^,], Leave Type: %19[^,], %*[^:]: %d\n", 
                  &id, name, leaveType, &balance) != EOF) {
        if (id == emp_id) {
            found = 1;
            printf("\t\t\tEmployee Name       :   %s\n", name);
            printf("\t\t\tLeave Type          :   %s\n", leaveType);
            printf("\t\t\tRemaining Balance   :   %d days\n", balance);
            printf("\n\t\t\t-------------------------------------------------------------------\n");
        }
    }

    if (!found) {
        printf("No leave balance record found for Employee ID %d.\n", emp_id);
    }

    fclose(fp_balance);
}


// Function to calculate the number of days between two dates
int calculateDaysBetweenDates(const char *startDate, const char *endDate) {
    struct tm start = {0}, end = {0};
    int start_day, start_month, start_year;
    int end_day, end_month, end_year;

    // Parse start date
    sscanf(startDate, "%d-%d-%d", &start_day, &start_month, &start_year);
    start.tm_mday = start_day;
    start.tm_mon = start_month - 1;  // tm_mon is 0-based
    start.tm_year = start_year - 1900;

    // Parse end date
    sscanf(endDate, "%d-%d-%d", &end_day, &end_month, &end_year);
    end.tm_mday = end_day;
    end.tm_mon = end_month - 1;
    end.tm_year = end_year - 1900;

    // Calculate difference in seconds and convert to days
    time_t start_time = mktime(&start);
    time_t end_time = mktime(&end);
    int days = (int)difftime(end_time, start_time) / (60 * 60 * 24);

    return days + 1;  // Include both start and end dates
}


void approveLeave(int emp_id) {
    FILE *fp_leave, *fp_emp, *temp_leave, *temp_emp, *fp_balance;
    LeaveRequest leave;
    //Employee emp;
    int found = 0, leave_days;
    char decision;

    fp_leave = fopen("LeaveRequests.txt", "rb");
    temp_leave = fopen("TempLeave.txt", "wb");
    fp_balance = fopen("LeaveBalances.txt", "a"); // Append mode to log remaining balances

    if (fp_leave == NULL || temp_leave == NULL || fp_balance == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&leave, sizeof(leave), 1, fp_leave) == 1) {
        if (leave.Emp_id == emp_id && strcmp(leave.status, "Pending") == 0) {
            found = 1;
            printf("Leave Request for %s: %s to %s\n", leave.type, leave.startDate, leave.endDate);
            printf("Approve (A) or Reject (R) the request? ");
            scanf(" %c", &decision);

            if (decision == 'A' || decision == 'a') {
                leave_days = calculateDaysBetweenDates(leave.startDate, leave.endDate);

                // Open employee file to update leave balance
                fp_emp = fopen("Employee.txt", "rb");
                temp_emp = fopen("TempEmp.txt", "wb");
                
                while (fread(&e, sizeof(e), 1, fp_emp) == 1) {
                    if (e.Emp_id == emp_id) {
                        if (strcmp(leave.type, "Annual") == 0 && e.annualLeave >= leave_days) {
                            e.annualLeave -= leave_days;
                            strcpy(leave.status, "Approved");  
                            printf("Annual leave approved. Remaining balance: %d days.\n", e.annualLeave);
                             fprintf(fp_balance, "Emp ID: %d, Name: %s,Leave Type: Annual, Annual: %d\n", 
                                e.Emp_id, e.Emp_name, e.annualLeave);
                        } else if (strcmp(leave.type, "Sick") == 0 && e.sickLeave >= leave_days) {
                            e.sickLeave -= leave_days;
                            strcpy(leave.status, "Approved");
                            printf("Sick leave approved. Remaining balance: %d days.\n", e.sickLeave);
                             fprintf(fp_balance, "Emp ID: %d, Name: %s,Leave Type: Sick, Sick: %d\n", 
                                e.Emp_id, e.Emp_name, e.sickLeave);
                                
                        } else if (strcmp(leave.type, "Casual") == 0 && e.casualLeave >= leave_days) {
                            e.casualLeave -= leave_days;
                            strcpy(leave.status, "Approved");
                            printf("Casual leave approved. Remaining balance: %d days.\n", e.casualLeave);
                            fprintf(fp_balance, "Emp ID: %d, Name: %s,Leave Type: Sick, Casual: %d\n", 
                                e.Emp_id, e.Emp_name, e.casualLeave);
                        } else {
                            strcpy(leave.status, "Rejected");
                            printf("Insufficient leave balance. Leave request rejected.\n");
                        }

                        // Log updated balance to LeaveBalances.txt
                    }
                    fwrite(&e, sizeof(e), 1, temp_emp);
                }
                fclose(fp_emp);
                fclose(temp_emp);
                remove("Employee.txt");
                rename("TempEmp.txt", "Employee.txt");
            } else {
                strcpy(leave.status, "Rejected");
                printf("Leave request rejected.\n");
            }
        }
        fwrite(&leave, sizeof(leave), 1, temp_leave);
    }

    fclose(fp_leave);
    fclose(temp_leave);
    fclose(fp_balance);
    remove("LeaveRequests.txt");
    rename("TempLeave.txt", "LeaveRequests.txt");

    if (!found) {
        printf("No pending leave requests found for Employee ID %d.\n", emp_id);
    }
}


void AttendanceList()
{
	system("cls");
	struct Attendance attendance;
	printf("\n\t\t::::::::::::::::::::::::::::: List of Attendance :::::::::::::::::::::::::::::::::::::\n");
	
	fp = fopen("Attendance.txt","rb");
	
	while(fread(&attendance,sizeof(attendance),1,fp) == 1)
	{		
			printf("\n\t\t\t======================= Employee ID : %d =========================\n\n",attendance.Emp_id);
			printf("\t\t\t\tEmployee ID         -   %s\n",attendance.date);
			printf("\t\t\t\tEmployee Name       -   %s\n",attendance.Emp_name);
			printf("\t\t\t\tEmployee Gender     -   %s\n",attendance.status);
			printf("\n\t\t\t==================================================================\n");
		
	}
	fclose(fp);	
	
}


void calculatePayroll(int emp_id) {
    FILE *fp;
    struct Employee emp;
    struct Payroll payroll;
    int found = 0;

    fp = fopen("Employee.txt", "rb");
    if (fp == NULL) {
        printf("Error opening Employee file!\n");
        return;
    }

    // Search for the employee in the file
    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (emp.Emp_id == emp_id) {
            found = 1;
            payroll.Emp_id = emp.Emp_id;
            payroll.baseSalary = emp.Base_Salary;
            payroll.hoursWorked = emp.hoursWorked;

            // Calculations
            payroll.grossPay = payroll.baseSalary * payroll.hoursWorked;

            printf("Enter Allowances: ");
            scanf("%f", &payroll.allowances);
            printf("Enter Deductions: ");
            scanf("%f", &payroll.deductions);

            payroll.netPay = payroll.grossPay + payroll.allowances - payroll.deductions;

            // Save payroll data
            FILE *fp_payroll = fopen("Payroll.txt", "ab");
            fwrite(&payroll, sizeof(payroll), 1, fp_payroll);
            fclose(fp_payroll);

            printf("Payroll calculated and saved successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }

    fclose(fp);
}

void viewSalarySlip(int emp_id) {
    FILE *fp;
    struct Payroll payroll;
    int found = 0;

    fp = fopen("Payroll.txt", "rb");
    if (fp == NULL) {
        printf("Error opening Payroll file!\n");
        return;
    }

    // Search for payroll record
    while (fread(&payroll, sizeof(payroll), 1, fp) == 1) {
        if (payroll.Emp_id == emp_id) {
            found = 1;
            printf("\n\t\t==================== Salary Slip ====================\n");
            printf("\t\tEmployee ID      : %d\n", payroll.Emp_id);
            printf("\t\tBase Salary      : %.2f\n", payroll.baseSalary);
            printf("\t\tHours Worked     : %d\n", payroll.hoursWorked);
            printf("\t\tGross Pay        : %.2f\n", payroll.grossPay);
            printf("\t\tAllowances       : %.2f\n", payroll.allowances);
            printf("\t\tDeductions       : %.2f\n", payroll.deductions);
            printf("\t\tNet Pay          : %.2f\n", payroll.netPay);
            printf("\t\t=====================================================\n");
            break;
        }
    }

    if (!found) {
        printf("Salary slip not found for Employee ID %d\n", emp_id);
    }

    fclose(fp);
}




//*********************************************** End Of HR Login ******************************************************	

	
//*********************************************** Start Of Manage - Department,Employee,Project **********************************	
	
 void Manage_Department()
{
			int choice;
			while(1)
			{
				printf("\n\t\t\t\t\t 1.Add Department\n");
				printf("\t\t\t\t\t 2.Display Department\n");
				printf("\t\t\t\t\t 3.Update Department\n");
				printf("\t\t\t\t\t 4.Remove Department\n");
				printf("\t\t\t\t\t 5.Search Department(By - Id)\n");
				printf("\t\t\t\t\t 6.Search Department(By - Name)\n");
				printf("\t\t\t\t\t 7.Sort Department\n");
				printf("\t\t\t\t\t 8.Back\n");
				printf("\t\t\t\t\t 0.Exit\n");
				printf("\n\t\t\t Enter Your Choice: ");
				scanf("%d",&choice);
				
				switch(choice)
				{
					case 0:
						exit(0);
					case 1:
						system("cls");
						Add_Dept();
						break;
					case 2:
						system("cls");
						display_Department();
						break;
					case 3:
						system("cls");
						DepartmentModify();
						break;
					case 4:
						system("cls");
						removeDept();
						break;
					case 5:
						system("cls");
						searchDept();
						break;
					case 6:
						system("cls");
						searchDeptName();
						break;
					case 7:
						system("cls");
						sort_Department();
						break;
					case 8:
						system("cls");
						return;
						break;
					default:
						printf("Invalid Choice");	
				}
			}
}
		
void Manage_Employee()
{
		//printf("manage employee..");
		int choice;
		int eid;
			while(1)
			{
				printf("\n\t\t\t\t\t 1.Add Employee\n");
				printf("\t\t\t\t\t 2.Display Employee\n");
				printf("\t\t\t\t\t 3.Update Employee\n");
				printf("\t\t\t\t\t 4.Remove Employee\n");
				printf("\t\t\t\t\t 5.Search Employee(By - Id)\n");
				printf("\t\t\t\t\t 6.Search Employee(By - Name)\n");
				printf("\t\t\t\t\t 7.Display Employee (Salary wise)\n");
				printf("\t\t\t\t\t 8.Sort Employee\n");
				printf("\t\t\t\t\t 9.Back\n");
				printf("\t\t\t\t\t 0.Exit\n");
				printf("\n\t\t\t Enter Your Choice: ");
				scanf("%d",&choice);
				
				switch(choice)
				{
					case 0:
						exit(0);
					case 1:
						system("cls");
						Add_Emp();
						break;
					case 2:
						system("cls");
						display_Employee();
						break;
					case 3:
						system("cls");
						EmployeeModify();
						break;
					case 4:
						system("cls");
						removeEmp();
						break;
					case 5:
						system("cls");
						searchEmp();
						break;
					case 6:
						system("cls");
						searchEmpName();
						break;
					case 7:
						system("cls");
						SalaryWiseDisplay();
						break;
					case 8:
						system("cls");
						sort_Employee();
						break;
					case 9:
						system("cls");
						return;
						break;
					default:
						printf("Invalid Choice");	
				}
			}
	}
	

void Manage_Project()
{
		int choice;
			while(1)
			{
				printf("\n\t\t\t\t\t 1.Add Project\n");
				printf("\t\t\t\t\t 2.Display Display\n");
				printf("\t\t\t\t\t 3.Update Project\n");
				printf("\t\t\t\t\t 4.Remove Project\n");
				printf("\t\t\t\t\t 5.Search Project(By - Id)\n");
				printf("\t\t\t\t\t 6.Display Project (Cost wise)\n");
				printf("\t\t\t\t\t 7.Sort Project\n");
				printf("\t\t\t\t\t 8.Back\n");
				printf("\t\t\t\t\t 0.Exit\n");
				printf("\n\t\t\t Enter Your Choice: ");
				scanf("%d",&choice);
				
				switch(choice)
				{
					case 0:
						exit(0);
					case 1:
						system("cls");
						Add_Project();
						break;
					case 2:
						system("cls");
						DisplayProject();
						break;
					case 3:
						system("cls");
						ProjectModify();
						break;
					case 4:
						system("cls");
						removeProject();
						break;
					case 5:
						system("cls");
						searchProject();
						break;
					case 6:
						system("cls");
						CostWiseDisplay();
						break;
					case 7:
						system("cls");
						sort_Project();
						break;
					case 8:
						system("cls");
						return;
					default:
						printf("Invalid Choice\n");	
				}
			}
	}
	
//*********************************************** End Of Manage - Department,Employee,Project ****************************************************************	

//********************************************** Start Of Department Functions ***************************************************************************************	

bool isDeptIdExist(int deptId) {
	FILE *fpCheck = fopen("Department.txt", "rb");
	if (fpCheck == NULL) {
		printf("Error opening file.\n");
		return false;
	}

	//Department temp;
	while (fread(&d, sizeof(d), 1, fpCheck) == 1) {
		if (d.Dept_id == deptId) {
			fclose(fpCheck);
			return true;
		}
	}
	fclose(fpCheck);
	return false;
}

int isDeptNameExists(const char *deptName) {
    FILE *fp = fopen("Department.txt", "rb");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    // Read each department from the file and check if the name matches
    while (fread(&d, sizeof(d), 1, fp) == 1) {
        if (strcmp(d.Dept_name, deptName) == 0) {
            fclose(fp);
            return 1; // Department name exists
        }
    }

    fclose(fp);
    return 0; // Department name does not exist
}

//Add Department
void Add_Dept()
{
		system("cls");
		char again = 'y';
		while(again == 'y')
		{
		printf("\n\t\t\t :::::::::::::::: Adding new Department ::::::::::::::::\n\n");
		fp = fopen("Department.txt","ab");
		
			char myDate[12];
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			sprintf(myDate,"%02d/%02d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year + 1900);
			strcpy(d.Regitered_date,myDate);
	
			// Validate Department ID
			
			do {
			printf("\t\t\t Enter Dept-id :: ");
			scanf("%d", &d.Dept_id);
			if (d.Dept_id <= 0) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Department ID! Please enter a positive number.\n" ANSI_COLOR_RESET);
				return;
			} else if (isDeptIdExist(d.Dept_id)) {
				printf(ANSI_COLOR_RED "\t\t\t Department ID already exists! Please enter a different ID.\n" ANSI_COLOR_RESET);
				return;
			}
		} while (d.Dept_id <= 0 || isDeptIdExist(d.Dept_id));

		// Validate Department Name
		
		do {
        printf("\t\t\t Enter Department Name :: ");
        fflush(stdin);
        gets(d.Dept_name);

        if (isDeptNameExists(d.Dept_name)) {
            printf(ANSI_COLOR_RED "\t\t\t Department Name already exists! Please enter a different name.\n"ANSI_COLOR_RESET);
            return;
        }
    } while (isDeptNameExists(d.Dept_name));
		
		// Validate Department Location

		do {
			printf("\t\t\t Enter Department Location :: ");
			fflush(stdin);
			gets(d.Location);
			if (strlen(d.Location) == 0) {
				printf(ANSI_COLOR_RED"\t\t\t Department Location cannot be empty! Please enter a valid location.\n"ANSI_COLOR_RESET);
			}
		} while (strlen(d.Location) == 0);
		
		
		printf("\n\t\t\t :::::::::::::::::::::::::::::::::::::::::::::::::::::: \n\n");
		
		printf(ANSI_COLOR_YELLOW"\n\t\t\t Want to enter another record (y/n)? : "ANSI_COLOR_RESET);
		fflush(stdin); 
		scanf("%c", &again); 
		
		printf(ANSI_COLOR_GREEN"\n\t\t\t Department Added Successfully! "ANSI_COLOR_RESET);
		printf(ANSI_COLOR_GREEN "\n\nPress Any Key to continue....... "ANSI_COLOR_RESET);
		getch();
		
		fwrite(&d,sizeof(d),1,fp);
		fclose(fp);	
	}
	}

// Display Department

void display_Department() {
    system("cls");
    printf("\n\t\t::::::::::::::::::::::::::::: List of Department :::::::::::::::::::::::::::::::::::::\n");

    FILE *fp = fopen("Department.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    int count = 0;
    int currentPage = 1;
    int departmentDisplayed = 0;
    char choice;

    while (fread(&d, sizeof(d), 1, fp) == 1) {
        if (departmentDisplayed == DEPARTMENTS_PER_PAGE) { // When page limit reached
            printf("\n\t\t\t================= Page %d =================\n", currentPage);
            printf("\n\t\t\tPress 'n' for Next Page, 'q' to Quit\n");
            choice = getch();
            
            if (choice == 'q' || choice == 'Q') {
                break; // Exit pagination
            } else if (choice == 'n' || choice == 'N') {
                system("cls");
                printf("\n\t\t::::::::::::::::::::::::::::: List of Department :::::::::::::::::::::::::::::::::::::\n");
                departmentDisplayed = 0;
                currentPage++;
            }
        }

        count++;
        departmentDisplayed++; // Track number of employees on the current page

        printf("\n\t\t\t================================================\n\n");
        	printf("\t\t\t\t Department ID           -   %d\n",d.Dept_id);
		printf("\t\t\t\t Department Name         -   %s\n",d.Dept_name);
		printf("\t\t\t\t Department Location     -   %s\n",d.Location);
		printf("\t\t\t\t Registered Date         -   %s\n",d.Regitered_date);
        printf("\n\t\t\t================================================\n");
    }

    if (departmentDisplayed > 0) { // For the last page if it has fewer than EMPLOYEES_PER_PAGE employees
        printf("\n\t\t\t==================== Page %d =================\n", currentPage);
    }
    
    fclose(fp);

    if (count == 0) {
        printf("\n\t\t\tNo department found.\n");
    } else {
        printf("\n\t\t\tTotal Department : %d\n", count);
    }
}


//Remove Department
void removeDept() {
    int did, f = 0;
    FILE *fp, *ft;

    system("cls");
    printf("\n\t\t\t :::::::::::::::: Remove Department ::::::::::::::::\n\n");
    printf(" Enter Department Id : ");
    scanf("%d", &did);

    fp = fopen("Department.txt", "rb");
    if (fp == NULL) {
        printf(ANSI_COLOR_RED"Error opening file!"ANSI_COLOR_RESET);
        return;
    }

    ft = fopen("temp.txt", "wb");
    if (ft == NULL) {
        printf(ANSI_COLOR_RED"Error opening temporary file!"ANSI_COLOR_RESET);
        fclose(fp);
        return;
    }

    while (fread(&d, sizeof(d), 1, fp) == 1) {
        if (did == d.Dept_id) {
            f = 1; // Mark as found and skip writing to temp file
        } else {
            fwrite(&d, sizeof(d), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);

    if (f == 1) {
        remove("Department.txt");
        rename("temp.txt", "Department.txt");
        printf(ANSI_COLOR_GREEN"\t\t\tDepartment Removed!!"ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED"Incorrect Department Id"ANSI_COLOR_RESET);
        remove("temp.txt"); // Clean up temporary file if not used
    }
}

//Department Modify
 void DepartmentModify()
 {
 	char deptname[20];
 	system("cls");
 	printf("\n\t\t\t :::::::::::::::: Modify Department ::::::::::::::::\n\n");
	printf("\t\t\t Enter Department Name : ");
 	fflush(stdin);
 	gets(deptname);
 	printf("\n\t\t\t ::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
 	fp = fopen("Department.txt","rb+");
 	while(fread(&d,sizeof(d),1,fp) == 1)
 	{
 		if(strcmp(deptname,d.Dept_name) == 0)
 		{
 			printf("\t\t\t Modify Department name : ");
            gets(d.Dept_name);
            printf("\t\t\t Modify Location : ");
            gets(d.Location);
            fseek(fp ,-sizeof(d),SEEK_CUR);
            fwrite(&d,sizeof(d),1,fp);
            break;
		}
	}
	fclose(fp);
 }

//Search Department (By Id)
void searchDept() {
    int did;
    int found = 0; // To check if the department ID exists
    system("cls");
    printf("\n\t\t\t :::::::::::::::: Search Department(Id) ::::::::::::::::\n\n");
    printf(" Enter Department Id : ");
    scanf("%d", &did);
    printf("\n\t\t\t ::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    fp = fopen("Department.txt", "rb");
    if (fp == NULL) {
        printf("Error opening Department file!\n");
        return;
    }

    while (fread(&d, sizeof(d), 1, fp) == 1) {
        if (did == d.Dept_id) {
            found = 1;
            printf("\n\t\t\t======================= Department ID : %d =========================\n\n", d.Dept_id);
            printf("\t\t\t\t Department ID         -   %d\n", d.Dept_id);
            printf("\t\t\t\t Department Name       -   %s\n", d.Dept_name);
            printf("\t\t\t\t Location              -   %s\n", d.Location);
            printf("\t\t\t\t Date of Registration  -   %s\n", d.Regitered_date);
            printf("\n\t\t\t===================================================================\n");
            break; // Stop searching once the department is found
        }
    }

    if (!found) {
        printf("\n\t\t\t No record found for Department ID: %d\n", did);
    }

    fclose(fp); // Close file after reading all records
}

 
 //Sorting Department
 void sort_Department() {
    FILE *fp = fopen("Department.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    struct Department departments[MAX_DEPARTMENTS];
    int count = 0;

    // Read departments from file into array
    while (fread(&departments[count], sizeof(struct Department), 1, fp) == 1 && count < MAX_DEPARTMENTS) {
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No departments found to sort.\n");
        return;
    }

    // Sort departments by Dept_id
    int i,j;
    for ( i = 0; i < count - 1; i++) {
        for ( j = i + 1; j < count; j++) {
            if (departments[i].Dept_id > departments[j].Dept_id) {
                struct Department temp = departments[i];
                departments[i] = departments[j];
                departments[j] = temp;
            }
        }
    }

    // Display sorted departments
    printf("\n\t\t::::::::::::::::::::::::::::: Sorted List of Departments by ID :::::::::::::::::::::::::::::::::::::\n");
    for (i = 0; i < count; i++) {
        printf("\n\t\t\t================================================\n\n");
        printf("\t\t\t\tDepartment ID      -   %d\n", departments[i].Dept_id);
        printf("\t\t\t\tDepartment Name    -   %s\n", departments[i].Dept_name);
        printf("\t\t\t\tLocation           -   %s\n", departments[i].Location);
        printf("\t\t\t\tRegistered Date    -   %s\n", departments[i].Regitered_date);
        printf("\n\t\t\t================================================\n");
    }
    printf("\n\t\tTotal Departments: %d\n", count);
}

//Search Department (By Name)
void searchDeptName() {
    char dname[20];
    int found = 0; // To check if the department name exists
    system("cls");
    printf("\n\t\t\t :::::::::::::::: Search Department(Name) ::::::::::::::::\n\n");
    printf("\t\t\t Enter Department Name : ");
    fflush(stdin);
    gets(dname);
    printf("\n\t\t\t :::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    fp = fopen("Department.txt", "rb");
    if (fp == NULL) {
        printf("Error opening Department file!\n");
        return;
    }

    while (fread(&d, sizeof(d), 1, fp) == 1) {
        if (strcmp(dname, d.Dept_name) == 0) {
            found = 1;
            printf("\n\t\t\t================================================\n\n");
            printf("\t\t\t\t Department ID         -   %d\n", d.Dept_id);
            printf("\t\t\t\t Department Name       -   %s\n", d.Dept_name);
            printf("\t\t\t\t Location              -   %s\n", d.Location);
            printf("\t\t\t\t Date of Registration  -   %s\n", d.Regitered_date);
            printf("\n\t\t\t=================================================\n");
            break; // Stop searching once the department is found
        }
    }

    if (!found) {
        printf("\n\t\t\t No record found for Department Name: %s\n", dname);
    }

    fclose(fp); // Close file after reading all records
}

//********************************************** End Of Department Functions **************************************************
	
//********************************************** Start of Employee Functions ***********************************************************	
//Add Employee

bool isEmpIdExist(int empId) {
	FILE *fpCheck = fopen("Employee.txt", "rb");
	if (fpCheck == NULL) {
		printf("Error opening file.\n");
		return false;
	}

	//Employee temp;
	while (fread(&e, sizeof(e), 1, fpCheck) == 1) {
		if (e.Emp_id == empId) {
			fclose(fpCheck);
			return true;
		}
	}
	fclose(fpCheck);
	return false;
}
bool isEmailExist(const char *email) {
	FILE *fpCheck = fopen("Employee.txt", "rb");
	if (fpCheck == NULL) {
		printf("Error opening file.\n");
		return false;
	}

	 struct Employee temp;
	while (fread(&temp, sizeof(temp), 1, fpCheck) == 1) {
		if (strcmp(temp.Emp_Email, email) == 0) {
			fclose(fpCheck);
			return true;
		}
	}
	fclose(fpCheck);
	return false;
}


void Add_Emp() {
	system("cls");
	char again = 'y';
	while (again == 'y') {
		struct Employee ep;
		printf("\n\t\t\t :::::::::::::::: Adding new Employee ::::::::::::::::\n\n");
		fp = fopen("Employee.txt", "ab");
		if (fp == NULL) {
			printf("Error opening file.\n");
			return;
		}
		
		char myDate[12];
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		strcpy(ep.Regitered_date, myDate);

		// Validate Employee ID (must be positive)
	do {
			printf("\t\t\t Enter Emp-id :: ");
			scanf("%d", &ep.Emp_id);
			if (ep.Emp_id <= 0) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Employee ID! Please enter a positive number.\n" ANSI_COLOR_RESET);
				return;
			} else if (isEmpIdExist(ep.Emp_id)) {
				printf(ANSI_COLOR_RED "\t\t\t Employee ID already exists! Please enter a different ID.\n"ANSI_COLOR_RESET);
				return;
			}
			
		} while (ep.Emp_id <= 0 && isEmpIdExist(ep.Emp_id));
		
		// Validate Employee Name (non-empty)
		do {
			printf("\t\t\t Enter Employee Name :: ");
			fflush(stdin);
			gets(ep.Emp_name);
			if (strlen(ep.Emp_name) == 0) {
				printf(ANSI_COLOR_RED"\t\t\t Invalid Name! Please enter a non-empty name.\n" ANSI_COLOR_RESET);
			}
		} while (strlen(ep.Emp_name) == 0);

		// Validate Gender (M/F/O)
		do {
			printf("\t\t\t Enter Employee Gender (M/F/O) :: ");
			fflush(stdin);
			scanf("%s", ep.Emp_Gender);
			if (strcmp(ep.Emp_Gender, "M") != 0 && strcmp(ep.Emp_Gender, "F") != 0 && strcmp(ep.Emp_Gender, "O") != 0) {
				printf(ANSI_COLOR_RED"\t\t\t Invalid Gender! Please enter M, F, or O.\n" ANSI_COLOR_RESET);
			}
		} while (strcmp(ep.Emp_Gender, "M") != 0 && strcmp(ep.Emp_Gender, "F") != 0 && strcmp(ep.Emp_Gender, "O") != 0);

		// Validate Age (must be between 18 and 65)
		do {
			printf("\t\t\t Enter Employee Age :: ");
			fflush(stdin);
			scanf("%d", &ep.Emp_Age);
			if (ep.Emp_Age < 18 || ep.Emp_Age > 65) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Age! Please enter a valid age between 18 and 65.\n" ANSI_COLOR_RESET);
			}
		} while (ep.Emp_Age < 18 || ep.Emp_Age > 65);

		// Validate Contact (only digits, 10 characters)
		do {
			printf("\t\t\t Enter Employee Contact (10 digits) :: ");
			fflush(stdin);
			scanf("%s", ep.Emp_Contact);
			if (strlen(ep.Emp_Contact) != 10 || strspn(ep.Emp_Contact, "0123456789") != 10) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Contact! Please enter a 10-digit number.\n" ANSI_COLOR_RESET);
			}
		} while (strlen(ep.Emp_Contact) != 10 || strspn(ep.Emp_Contact, "0123456789") != 10);

		// Validate Base Salary (must be positive)
		do {
			printf("\t\t\t Enter Employee Base Salary (Hourly) :: ");
			fflush(stdin);
			scanf("%f", &ep.Base_Salary);
			if (ep.Base_Salary <= 0) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Salary! Please enter a positive value.\n"ANSI_COLOR_RESET );
			}
		} while (ep.Base_Salary <= 0);

		// Validate Hours Worked (must be non-negative)
		do {
			printf("\t\t\t Enter Employee Hours Worked :: ");
			scanf("%d", &ep.hoursWorked);
			if (ep.hoursWorked <= 0) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Hours! Please enter a non-negative number.\n"ANSI_COLOR_RESET);
			}
		} while (ep.hoursWorked <= 0);

		// Validate Employee Role (non-empty)
		do {
			printf("\t\t\t Enter Employee Role :: ");
			fflush(stdin);
			scanf("%s", ep.Emp_Role);
			if (strlen(ep.Emp_Role) == 0) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Role! Please enter a non-empty role.\n" ANSI_COLOR_RESET);
			}
		} while (strlen(ep.Emp_Role) == 0);

		// Validate Email (simple check for '@' and '.')
	do {
			printf("\t\t\t Enter Employee Email :: ");
			fflush(stdin);
			gets(ep.Emp_Email);
			if (strchr(ep.Emp_Email, '@') == NULL || strchr(ep.Emp_Email, '.') == NULL) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Email! Please enter a valid email address.\n"ANSI_COLOR_RESET);
			} else if (isEmailExist(ep.Emp_Email)) {
				printf(ANSI_COLOR_RED "\t\t\t Email already exists! Please enter a different email.\n"ANSI_COLOR_RESET);
				return;
			}
		} while (strchr(ep.Emp_Email, '@') == NULL || strchr(ep.Emp_Email, '.') == NULL || isEmailExist(ep.Emp_Email));

		// Validate Password (minimum length)
		do {
			printf("\t\t\t Enter Employee Password (minimum 6 characters) :: ");
			gets(ep.Emp_Password);
			if (strlen(ep.Emp_Password) < 6) {
				printf(ANSI_COLOR_RED "\t\t\t Invalid Password! Please enter at least 6 characters.\n" ANSI_COLOR_RESET);
			}
		} while (strlen(ep.Emp_Password) < 6);

		ep.annualLeave = 20;
		ep.sickLeave = 10;
		ep.casualLeave = 8;

		printf("\n\t\t\t :::::::::::::::::::::::::::::::::::::::::::::::::::::: \n\n");
		printf(ANSI_COLOR_YELLOW"\n\t\t\t Want to enter another record (y/n)? : " ANSI_COLOR_RESET);
		fflush(stdin);
		scanf("%c", &again);
		printf(ANSI_COLOR_GREEN"\n\t\t\t Employee Added Successfully! ");
		printf("\n\nPress Any Key to continue....... " ANSI_COLOR_RESET);
		getch();
		fwrite(&ep, sizeof(ep), 1, fp);
		fclose(fp);
		system("cls");
	}
}


void sort_Employee() {
    FILE *fp = fopen("Employee.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;

    // Read employees from file into array
    while (fread(&employees[count], sizeof(struct Employee), 1, fp) == 1 && count < MAX_EMPLOYEES) {
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No employees found to sort.\n");
        return;
    }
    int i,j;

    // Sort employees by Employee ID
    for ( i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (employees[i].Emp_id > employees[j].Emp_id) {
                struct Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }

    // Display sorted employees
    printf("\n\t\t::::::::::::::::::::::::::::: Sorted List of Employees by ID :::::::::::::::::::::::::::::::::::::\n");
    for (i = 0; i < count; i++) {
        printf("\n\t\t\t================================================\n\n");
        printf("\t\t\t\tEmployee ID         -   %d\n", employees[i].Emp_id);
        printf("\t\t\t\tEmployee Name       -   %s\n", employees[i].Emp_name);
        printf("\t\t\t\tEmployee Gender     -   %s\n", employees[i].Emp_Gender);
        printf("\t\t\t\tEmployee Age        -   %d\n", employees[i].Emp_Age);
        printf("\t\t\t\tEmployee Contact    -   %s\n", employees[i].Emp_Contact);
        printf("\t\t\t\tEmployee Base Salary-   %.2f\n", employees[i].Base_Salary);
        printf("\t\t\t\tEmployee Hourly-work-   %d\n", employees[i].hoursWorked);
        printf("\t\t\t\tEmployee Role       -   %s\n", employees[i].Emp_Role);
        printf("\t\t\t\tEmployee Email      -   %s\n", employees[i].Emp_Email);
        printf("\t\t\t\tDate of Registration-   %s\n", employees[i].Regitered_date);
        printf("\n\t\t\t================================================\n");
    }
    printf("\n\t\tTotal Employees: %d\n", count);
}


//diplay_employee
void display_Employee() {
    system("cls");
    printf("\n\t\t::::::::::::::::::::::::::::: List of Employees :::::::::::::::::::::::::::::::::::::\n");

    FILE *fp = fopen("Employee.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    int count = 0;
    int currentPage = 1;
    int employeesDisplayed = 0;
    char choice;

    while (fread(&e, sizeof(e), 1, fp) == 1) {
        if (employeesDisplayed == EMPLOYEES_PER_PAGE) { // When page limit reached
            printf("\n\t\t\t================= Page %d =================\n", currentPage);
            printf("\n\t\t\tPress 'n' for Next Page, 'q' to Quit\n");
            choice = getch();
            
            if (choice == 'q' || choice == 'Q') {
                break; // Exit pagination
            } else if (choice == 'n' || choice == 'N') {
                system("cls");
                printf("\n\t\t::::::::::::::::::::::::::::: List of Employees :::::::::::::::::::::::::::::::::::::\n");
                employeesDisplayed = 0;
                currentPage++;
            }
        }

        count++;
        employeesDisplayed++; // Track number of employees on the current page

        printf("\n\t\t\t================================================\n\n");
        printf("\t\t\t\tEmployee ID         -   %d\n", e.Emp_id);
        printf("\t\t\t\tEmployee Name       -   %s\n", e.Emp_name);
        printf("\t\t\t\tEmployee Gender     -   %s\n", e.Emp_Gender);
        printf("\t\t\t\tEmployee Age        -   %d\n", e.Emp_Age);
        printf("\t\t\t\tEmployee Contact    -   %s\n", e.Emp_Contact);
        printf("\t\t\t\tEmployee Base Salary-   %.2f\n", e.Base_Salary);
        printf("\t\t\t\tEmployee Hourly-work-   %d\n", e.hoursWorked);
        printf("\t\t\t\tEmployee Role       -   %s\n", e.Emp_Role);
        printf("\t\t\t\tEmployee Email      -   %s\n", e.Emp_Email);
        printf("\t\t\t\tDate of Registration-   %s\n", e.Regitered_date);
        printf("\n\t\t\t================================================\n");
    }

    if (employeesDisplayed > 0) { // For the last page if it has fewer than EMPLOYEES_PER_PAGE employees
        printf("\n\t\t\t==================== Page %d =================\n", currentPage);
    }
    
    fclose(fp);

    if (count == 0) {
        printf("\n\t\t\tNo employees found.\n");
    } else {
        printf("\n\t\t\tTotal Employees: %d\n", count);
    }
}


//Remove Employee
void removeEmp() {
    int eid, f = 0;
    FILE *fp, *ft;

    system("cls");
    printf("\n\t\t\t :::::::::::::::: Remove Employee ::::::::::::::::\n\n");
    printf(" Enter Employee Id : ");
    scanf("%d", &eid);

    fp = fopen("Employee.txt", "rb");
    if (fp == NULL) {
        printf(ANSI_COLOR_RED"Error opening file!"ANSI_COLOR_RESET);
        return;
    }

    ft = fopen("temp.txt", "wb");
    if (ft == NULL) {
        printf(ANSI_COLOR_RED"Error opening temporary file!"ANSI_COLOR_RESET);
        fclose(fp);
        return;
    }

    while (fread(&e, sizeof(e), 1, fp) == 1) {
        if (eid == e.Emp_id) {
            f = 1; // Mark as found and skip writing to temp file
        } else {
            fwrite(&e, sizeof(e), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);

    if (f == 1) {
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        printf(ANSI_COLOR_GREEN"\t\t\tEmployee Removed!!"ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED"Incorrect Employee Id"ANSI_COLOR_RESET);
        remove("temp.txt"); // Clean up temporary file if not used
    }
}

//Employee Modify
 void EmployeeModify()
 {
 	
 	char empname[20];
 	system("cls");
 	printf("\n\t\t\t :::::::::::::::: Modify Employee ::::::::::::::::\n\n");
	printf("\t\t\t Enter Employee Name : ");
 	fflush(stdin);
 	gets(empname);
 	printf("\n\t\t\t ::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
 	fp = fopen("Employee.txt","rb+");
 	while(fread(&e,sizeof(e),1,fp) == 1)
 	{
 		if(strcmp(empname,e.Emp_name) == 0)
 		{
 			printf("\t\t\t Modify Employee name: ");
            gets(e.Emp_name);
            printf("\t\t\t Modify Employee Gender : ");
            gets(e.Emp_Gender);
            printf("\t\t\t Modify Employee Age : ");
            scanf("%d",&e.Emp_Age);
            printf("\t\t\t Modify Employee Contact : ");
            scanf("%d",&e.Emp_Contact);
            printf("\t\t\t Enter Employee Salary : ");
        	scanf("%f",&e.Base_Salary);
        	printf("\t\t\t Enter Employee Role :: ");
			scanf("%s",&e.Emp_Role);
            printf("\t\t\t Modify Email : ");
            fflush(stdin);
            gets(e.Emp_Email);
            fseek(fp ,-sizeof(e),SEEK_CUR);
            fwrite(&e,sizeof(e),1,fp);
            printf(ANSI_COLOR_GREEN"Record Modified SuccessFully"ANSI_COLOR_RESET);
            break;
		}
	}
	fclose(fp);
 }
 
//Employee Search By Id
void searchEmp() {
    int eid, found = 0;
    system("cls");
    printf("\n\t\t\t :::::::::::::::: Search Employee (by ID) ::::::::::::::::\n\n");
    printf(" Enter Employee ID: ");
    scanf("%d", &eid);

    fp = fopen("Employee.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fread(&e, sizeof(e), 1, fp) == 1) {
        if (eid == e.Emp_id) {
            printf("\n\t\t\t\t======================= Employee ID: %d =========================\n\n", e.Emp_id);
            printf("\t\t\t\tEmployee ID         -   %d\n", e.Emp_id);
            printf("\t\t\t\tEmployee Name       -   %s\n", e.Emp_name);
            printf("\t\t\t\tEmployee Gender     -   %s\n", e.Emp_Gender);
            printf("\t\t\t\tEmployee Age        -   %d\n", e.Emp_Age);
            printf("\t\t\t\tEmployee Contact    -   %d\n", e.Emp_Contact);
            printf("\t\t\t\tEmployee Email      -   %s\n", e.Emp_Email);
            printf("\t\t\t\tDate of Registration-   %s\n", e.Regitered_date);
            printf("\n\t\t\t\t===============================================================\n");
            found = 1;
            break;  // Stop searching as the employee is found
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n\t\t\tNo employee found with ID: %d\n", eid);
    }
}



//Employee Search By Name
void searchEmpName() {
    char ename[20];
    int found = 0;
    system("cls");
    printf("\n\t\t\t :::::::::::::::: Search Employee (by Name) ::::::::::::::::\n\n");
    printf(" Enter Employee Name: ");
    getchar(); // To handle any leftover newline character in the buffer
    fgets(ename, sizeof(ename), stdin);
    ename[strcspn(ename, "\n")] = 0;  // Remove the newline character from fgets input

    fp = fopen("Employee.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fread(&e, sizeof(e), 1, fp) == 1) {
        if (strcmp(ename, e.Emp_name) == 0) {
            printf("\n\t\t\t================================================\n\n");
            printf("\t\t\t\tEmployee ID         -   %d\n", e.Emp_id);
            printf("\t\t\t\tEmployee Name       -   %s\n", e.Emp_name);
            printf("\t\t\t\tEmployee Gender     -   %s\n", e.Emp_Gender);
            printf("\t\t\t\tEmployee Age        -   %d\n", e.Emp_Age);
            printf("\t\t\t\tEmployee Contact    -   %d\n", e.Emp_Contact);
            printf("\t\t\t\tEmployee Email      -   %s\n", e.Emp_Email);
            printf("\t\t\t\tDate of Registration-   %s\n", e.Regitered_date);
            printf("\n\t\t\t================================================\n");
            found = 1;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n\t\t\tNo employee found with the name: %s\n", ename);
    }
}

//Salary wise (Employee)
void SalaryWiseDisplay() {
    float From, To;
    int found = 0;
    system("cls");
    printf("\n\t\t\t :::::::::::::::: Salary Wise (Employees) ::::::::::::::::\n\n");
    printf("From: ");
    scanf("%f", &From);
    printf("To: ");
    scanf("%f", &To);

    fp = fopen("Employee.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fread(&e, sizeof(e), 1, fp) == 1) {
        if (e.Base_Salary >= From && e.Base_Salary <= To) {  // Corrected condition
            printf("\n\t\t\t================================================\n\n");
            printf("\t\t\t\tEmployee ID         -   %d\n", e.Emp_id);
            printf("\t\t\t\tEmployee Name       -   %s\n", e.Emp_name);
            printf("\t\t\t\tEmployee Gender     -   %s\n", e.Emp_Gender);
            printf("\t\t\t\tEmployee Age        -   %d\n", e.Emp_Age);
            printf("\t\t\t\tEmployee Contact    -   %d\n", e.Emp_Contact);
            printf("\t\t\t\tEmployee Base Salary-   %.2f\n", e.Base_Salary);
            printf("\t\t\t\tEmployee Role       -   %s\n", e.Emp_Role);
            printf("\t\t\t\tEmployee Email      -   %s\n", e.Emp_Email);
            printf("\t\t\t\tDate of Registration-   %s\n", e.Regitered_date);
            printf("\n\t\t\t================================================\n");
            found = 1;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n\t\t\tNo employees found with a salary between %.2f and %.2f.\n", From, To);
    }
}

//********************************************** End Of Employee Functions ***********************************************************	
 
//************************************************ Start Of Project (Functions) *************************************************


int validate_project_id(int id) {
    return id > 0; // Ensure Pro_id is positive
}

int validate_project_cost(float cost) {
    return cost >= 0; // Ensure Project_cost is non-negative
}

int validate_name(const char *name) {
    return strlen(name) > 0; // Ensure name is not empty
}
void Add_Project()
{
    system("cls");
    char again = 'y';
    while (again == 'y')
    {
        printf("\n\t\t\t :::::::::::::::: Adding new Project ::::::::::::::::\n\n");
        fp = fopen("Project.txt", "ab");

        if (fp == NULL) {
            printf("Error opening file.\n");
            return;  // Exit if file cannot be opened
        }

        char myDate[12];
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        strcpy(p.Regitered_date, myDate);

        // Validate Project ID
        do {
            printf("\t\t\t Enter Project-id (positive integer): ");
            scanf("%d", &p.Pro_id);
            if (!validate_project_id(p.Pro_id)) {
                printf(ANSI_COLOR_RED "\t\t\t Invalid Project ID. Please enter a positive integer.\n"ANSI_COLOR_RESET);
            }
        } while (!validate_project_id(p.Pro_id));

        // Validate Project Name
        do {
            printf("\t\t\t Enter Project Name: ");
            fflush(stdin);
            gets(p.Pro_Name);
            if (!validate_name(p.Pro_Name)) {
                printf(ANSI_COLOR_RED "\t\t\t Invalid input. Project name cannot be empty.\n" ANSI_COLOR_RESET);
            }
        } while (!validate_name(p.Pro_Name));

        // Validate Employee Name
        do {
            printf("\t\t\t Enter Employee Name: ");
            fflush(stdin);
            gets(p.Emp_Name);
            if (!validate_name(p.Emp_Name)) {
                printf(ANSI_COLOR_RED "\t\t\t Invalid input. Employee name cannot be empty.\n"ANSI_COLOR_RESET);
            }
        } while (!validate_name(p.Emp_Name));

        // Validate Project Cost
        do {
            printf("\t\t\t Project Cost (non-negative): ");
            scanf("%f", &p.Project_cost);
            if (!validate_project_cost(p.Project_cost)) {
                printf(ANSI_COLOR_RED "\t\t\t Invalid cost. Please enter a non-negative value.\n" ANSI_COLOR_RESET);
            }
        } while (!validate_project_cost(p.Project_cost));

        printf("\n\t\t\t :::::::::::::::::::::::::::::::::::::::::::::::::::::: \n\n");

        printf(ANSI_COLOR_YELLOW "\n\t\t\t Want to enter another record (y/n)? : " ANSI_COLOR_RESET);
        fflush(stdin);
        scanf("%c", &again);

        if (again == 'y' || again == 'Y') {
            printf(ANSI_COLOR_GREEN "\n\t\t\t Project Added Successfully! " ANSI_COLOR_RESET);
            printf(ANSI_COLOR_GREEN "\n\nPress Any Key to continue....... " ANSI_COLOR_RESET);
            getch();
        }

        fwrite(&p, sizeof(p), 1, fp);
        fclose(fp);
    }
}

void DisplayProject() {
    system("cls");
    printf("\n\t\t::::::::::::::::::::::::::::: List of Project :::::::::::::::::::::::::::::::::::::\n");

    FILE *fp = fopen("Project.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    int count = 0;
    int currentPage = 1;
    int projectDisplayed = 0;
    char choice;

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (projectDisplayed == PROJECTS_PER_PAGE) { // When page limit reached
            printf("\n\t\t\t================= Page %d =================\n", currentPage);
            printf("\n\t\t\tPress 'n' for Next Page, 'q' to Quit\n");
            choice = getch();
            
            if (choice == 'q' || choice == 'Q') {
                break; // Exit pagination
            } else if (choice == 'n' || choice == 'N') {
                system("cls");
                printf("\n\t\t::::::::::::::::::::::::::::: List of Projects :::::::::::::::::::::::::::::::::::::\n");
                projectDisplayed = 0;
                currentPage++;
            }
        }

        count++;
        projectDisplayed++; // Track number of project on the current page

        printf("\n\t\t\t================================================\n\n");
        printf("\t\t\t\t Project ID           -   %d\n",p.Pro_id);
		printf("\t\t\t\t Project Name         -   %s\n",p.Pro_Name);
		printf("\t\t\t\t Project Cost         -   %f\n",p.Project_cost);
		printf("\t\t\t\t Allocated Employee   -   %s\n",p.Emp_Name);
		printf("\t\t\t\t Registered Date      -   %s\n",p.Regitered_date);
        printf("\n\t\t\t================================================\n");
    }

    if (projectDisplayed > 0) { // For the last page if it has fewer than EMPLOYEES_PER_PAGE employees
        printf("\n\t\t\t==================== Page %d =================\n", currentPage);
    }
    
    fclose(fp);

    if (count == 0) {
        printf("\n\t\t\tNo Project found.\n");
    } else {
        printf("\n\t\t\tTotal Projects : %d\n", count);
    }
}

 void removeProject() {
    int pid, f = 0;
    FILE *fp, *ft;

    system("cls");
    printf("\n\t\t\t :::::::::::::::: Remove Project ::::::::::::::::\n\n");
    printf(" Enter Project Id : ");
    scanf("%d", &pid);

    fp = fopen("Project.txt", "rb");
    if (fp == NULL) {
        printf(ANSI_COLOR_RED"Error opening file!"ANSI_COLOR_RESET);
        return;
    }

    ft = fopen("temp.txt", "wb");
    if (ft == NULL) {
        printf(ANSI_COLOR_RED"Error opening temporary file!"ANSI_COLOR_RESET);
        fclose(fp);
        return;
    }

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (pid == p.Pro_id) {
            f = 1; // Mark as found and skip writing to temp file
        } else {
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);

    if (f == 1) {
        remove("Project.txt");
        rename("temp.txt", "Project.txt");
        printf(ANSI_COLOR_GREEN"\t\t\tProject Removed!!"ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED"Incorrect Project Id"ANSI_COLOR_RESET);
        remove("temp.txt"); // Clean up temporary file if not used
    }
}

 
 void ProjectModify()
 {
 	char proname[20];
 	system("cls");
 	printf("\n\t\t\t :::::::::::::::: Modify Project ::::::::::::::::\n\n");
	printf("\t\t\t Enter Project Name : ");
 	fflush(stdin);
 	gets(proname);
 	printf("\n\t\t\t ::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
 	fp = fopen("Project.txt","rb+");
 	while(fread(&p,sizeof(p),1,fp) == 1)
 	{
 		if(strcmp(proname,p.Pro_Name) == 0)
 		{
 			printf("\t\t\t Modify Project name : ");
            gets(p.Pro_Name);
            printf("\t\t\t Modify Project Cost : ");
            scanf("%s",&p.Project_cost);
            printf("\t\t\t Modify Employee name : ");
            gets(p.Emp_Name);
//            fseek(fp ,-sizeof(d),SEEK_CUR);
//            fwrite(&d,sizeof(d),1,fp);
            fseek(fp, -sizeof(p), SEEK_CUR);
			fwrite(&p, sizeof(p), 1, fp);

            break;
		}
	}
	fclose(fp);
 }
 
void searchProject() {
    int pid;
    int found = 0;  // Flag to check if project is found
    system("cls");
    printf("\n\t\t\t :::::::::::::::: Search Project (ID) ::::::::::::::::\n\n");
    printf(" Enter Project ID: ");
    scanf("%d", &pid);
    
    FILE *fp = fopen("Project.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    
    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (pid == p.Pro_id) {
            printf("\n\t\t\t\t======================= Project ID: %d =========================\n\n", p.Pro_id);
            printf("\t\t\t\t Project ID           -   %d\n", p.Pro_id);
            printf("\t\t\t\t Project Name         -   %s\n", p.Pro_Name);
            printf("\t\t\t\t Project Cost         -   %.2f\n", p.Project_cost);
            printf("\t\t\t\t Employee Name        -   %s\n", p.Emp_Name);
            printf("\t\t\t\t Date of Registration -   %s\n", p.Regitered_date);
            printf("\n\t\t\t\t===============================================================\n");
            found = 1;  // Set flag to indicate project was found
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n\t\t\tNo project found with ID: %d\n", pid);
    }
}

 
 
 
 //Salary wise (Employee)
void CostWiseDisplay() {
    float From, To;
    int found = 0;
    system("cls");
    printf("\n\t\t\t :::::::::::::::: Records Based On Cost (Range) ::::::::::::::::\n\n");
    printf("From: ");
    scanf("%f", &From);
    printf("To: ");
    scanf("%f", &To);

    FILE *fp = fopen("Project.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (p.Project_cost >= From && p.Project_cost <= To) {  // Corrected condition
            printf("\n\t\t\t================================================\n\n");
            printf("\t\t\t\t Project ID         -   %d\n", p.Pro_id);
            printf("\t\t\t\t Project Name       -   %s\n", p.Pro_Name);
            printf("\t\t\t\t Project Cost       -   %.2f\n", p.Project_cost);
            printf("\t\t\t\t Employee Name      -   %s\n", p.Emp_Name);
            printf("\t\t\t\t Date of Registration-   %s\n", p.Regitered_date);
            printf("\n\t\t\t================================================\n");
            found = 1;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n\t\t\tNo projects found with a cost between %.2f and %.2f.\n", From, To);
    }
}

 
 void sort_Project() {
    FILE *fp = fopen("Project.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    struct Project projects[MAX_PROJECTS];
    int count = 0;

    // Read projects from file into array
    while (fread(&projects[count], sizeof(struct Project), 1, fp) == 1 && count < MAX_PROJECTS) {
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No projects found to sort.\n");
        return;
    }

    // Sort projects by Pro_id
    int i,j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (projects[i].Pro_id > projects[j].Pro_id) {
                struct Project temp = projects[i];
                projects[i] = projects[j];
                projects[j] = temp;
            }
        }
    }

    // Display sorted projects
    printf("\n\t\t::::::::::::::::::::::::::::: Sorted List of Projects by ID :::::::::::::::::::::::::::::::::::::\n");
    for (i = 0; i < count; i++) {
        printf("\n\t\t\t================================================\n\n");
        printf("\t\t\t\tProject ID        -   %d\n", projects[i].Pro_id);
        printf("\t\t\t\tProject Name      -   %s\n", projects[i].Pro_Name);
        printf("\t\t\t\tProject Cost      -   %.2f\n", projects[i].Project_cost);
        printf("\t\t\t\tAssigned Employee -   %s\n", projects[i].Emp_Name);
        printf("\t\t\t\tRegistered Date   -   %s\n", projects[i].Regitered_date);
        printf("\n\t\t\t================================================\n");
    }
    printf("\n\t\tTotal Projects: %d\n", count);
}
//************************************************ End Of Project (Functions) ***************************************************