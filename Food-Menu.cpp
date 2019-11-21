#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	int order; //Type of food order
	int riceMealChoice; //Type of Rice Meal
	int fruitChoice; //Type of Fruit
	int drinkChoice; //Type of Drink
	int snacksChoice; //Type of Snacks
	int otherChoice; //Type of Other
	int customerChoice; // If customer wants an additional order (Y/N)

	//Personal Information
	string name;
	string section;

	// Rice meals price
	int riceMealChicken = 55.00;
	int riceMealTalong = 45.00;
	// Rice Meal Quantity
	int riceMealChickenQuantity = 0;
	int riceMealTalongQuantity = 0;


	// Fruits price
	int fruits;
	int fruitBanana = 15.00;
	// Rice Meal Quantity
	int fruitBananaQuantity = 0;


	// Drinks price
	int drinks;
	int drinkC2 = 25.00;
	int drinkSmartC = 25.00;
	int drinkSummit = 15.00;
	int drinkKopiko = 12.00;
	// Drinks Quantity
	int drinkC2Quantity = 0;
	int drinkSmartCQuantity = 0;
	int drinkSummitQuantity = 0;
	int drinkKopikoQuantity = 0;

	// Snacks price
	int snacks;
	int snacksVoice = 10.00;
	int snacksFudgeebar = 10.00;
	int snacksCreamO = 8.00;
	int snacksBreadpan = 8.00;
	// Snacks Quantity
	int snacksVoiceQuantity = 0;
	int snacksFudgeebarQuantity = 0;
	int snacksCreamOQuantity = 0;
	int snacksBreadpanQuantity = 0;

	// Other food prices
	int other;
	int otherCarbonara = 50.00;
	int otherSpaghetti = 50.00;
	int otherPalabok = 45.00;
	// Other food Quantity
	int otherCarbonaraQuantity = 0;
	int otherSpaghettiQuantity = 0;
	int otherPalabokQuantity = 0;


	// Price computation variables 
	int MealQuantity; //No of serving the customer wants
	int priceTotal; // Total price of the order

	//Asks for personal Information
	cout << ("Enter your name & section! :)") << endl;
	cout << ("Name: ");
	getline(cin, name);
	cout << ("Section: ");
	getline(cin, section);
	system("cls");


	//The Menu Table
menu:
	cout << ("Hello ") << name << (" of ") << section << ("! Good day, welcome to CIIT SHS' canteen. What's your order?") << endl;
	cout << ("[1] Rice Meal				[2] Fruits") << endl;
	cout << ("[3] Drinks				[4] Snacks") << endl;
	cout << ("[5] Others				[6] Exit \n\n");
	cin >> order;

	//Rice Meal
	if (order == 1)
	{
		system("cls");
		cout << ("These are the meal for today: \n\n");
		cout << ("[1] Fried Chicken with Rice. . . . . . . . . . . . . . . . . P55.00") << endl;
		cout << ("[2] Tortang Talong. . . . . . . . . . . . . . . . . . . . . P45.00") << endl;
		cin >> riceMealChoice;

		// Asking for order quantity (Rice Meals)
		cout << ("\nEnter the quantity of your order.") << endl;
		cin >> MealQuantity;
		// Asking if customer has additional orders
		cout << ("\n Do you have another order?") << endl;
		cout << ("[1] Yes				[2] No") << endl;
		cin >> customerChoice;

		//switch conditions on rice meal choices
		switch (riceMealChoice)
		{
		case 1: //if customer selected the Chicken meal 
			riceMealChickenQuantity = riceMealChickenQuantity + MealQuantity;
			break;

		case 2://value of the variable will not change if neither of the conditions met
			riceMealTalongQuantity = riceMealTalongQuantity + MealQuantity;
			break;

		default: //value of the variable will not change if neither of the conditions met
			riceMealTalongQuantity;
			riceMealChickenQuantity;
			break;
		}
		// If customer has other orders
		if (customerChoice == 1)
		{
			system("cls");
			goto menu;

		}
		// If customer is done
		else if (customerChoice == 2)
		{

			system("cls");
			//error handling statement if in case customer puts 0 in the "Do you have another order?" question
			if (MealQuantity == 0)
			{
				goto menu;
			}
			// computation for the total price/bill
			else
			{
				riceMealChicken = riceMealChickenQuantity * riceMealChicken; // computation for the price of Chicken Meal only
				riceMealTalong = riceMealTalongQuantity * riceMealTalong; // computation for the price of Talong Meal only
				fruitBanana = fruitBananaQuantity * fruitBanana; // computation for the price of Banana (fruit) only
				priceTotal = riceMealChicken + riceMealTalong + fruitBanana;  // computes the total price

				cout << ("Order Summary:") << endl;
				cout << ("--------------") << endl;
				cout << ("Customer Name: ") << name << endl; //Displays the customer name
				cout << ("Section: ") << section << endl; //Displays the section of the customer
				cout << ("--------------") << endl;

				// Displays the no. of orders for rice meals
				cout << ("Rice Meal:") << endl;
				cout << ("Chicken Meal (55 PHP): ") << riceMealChickenQuantity << (" order/s - ") << riceMealChicken
					<< (" PHP | Talong Meal (45 PHP): ") << riceMealTalongQuantity << (" order/s - ") << riceMealTalong << (" PHP") << endl;
				// Displays the no. of order for fruits
				cout << ("Fruits:") << endl;
				cout << ("Banana (15 PHP): ") << fruitBananaQuantity << (" order/s - ") << fruitBanana << (" PHP") << endl;
				cout << ("Total Bill: ") << priceTotal << (" PHP");
			}

		}

	}
	//Fruits
	else if (order == 2)
	{
		system("cls");
		cout << ("These are the fruits for today: ") << endl;
		cout << ("[1] Banana . . . . . . . . . . . P15.00") << endl;

		cin >> fruitChoice;

		// Asking for order quantity (Rice Meals)
		cout << ("\nEnter the quantity of your order.") << endl;
		cin >> MealQuantity;
		// Asking if customer has additional orders
		cout << ("\n Do you have another order?") << endl;
		cout << ("[1] Yes				[2] No") << endl;
		cin >> customerChoice;

		//switch conditions on fruit choices		
		switch (fruitChoice)
		{
		case 1:
			fruitBananaQuantity = fruitBananaQuantity + MealQuantity;
			break;

		default: //value of the variable will not change if neither of the conditions met
			fruitBananaQuantity;
			break;
		}
		// If customer has other orders
		if (customerChoice == 1)
		{
			system("cls");
			goto menu;

		}
		// If customer is done
		else if (customerChoice == 2)
		{

			system("cls");
			//error handling statement if in case customer puts 0 in the "Do you have another order?" question
			if (MealQuantity == 0) {

				goto menu;

			}
			// computation for the total price/bill
			else {

				riceMealChicken = riceMealChickenQuantity * riceMealChicken; // computation for the price of Chicken Meal only
				riceMealTalong = riceMealTalongQuantity * riceMealTalong; // computation for the price of Talong Meal only
				fruitBanana = fruitBananaQuantity * fruitBanana; // computation for the price of the Banana (fruit) only
				priceTotal = riceMealChicken + riceMealTalong + fruitBanana; // computes the total price

				cout << ("Order Summary:") << endl;
				cout << ("--------------") << endl;
				cout << ("Customer Name: ") << name << endl; //Displays the customer name
				cout << ("Section: ") << section << endl; //Displays the section of the customer
				cout << ("--------------") << endl;
				// Displays the no. of order for rice meals
				cout << ("Rice Meal:") << endl;
				cout << ("Chicken Meal (55 PHP): ") << riceMealChickenQuantity << (" order/s - ") << riceMealChicken
					<< (" PHP | Talong Meal (45 PHP): ") << riceMealTalongQuantity << (" order/s - ") << riceMealTalong << (" PHP") << endl;
				// Displays the no. of order for fruits
				cout << ("Fruits:") << endl;
				cout << ("Banana (15 PHP): ") << fruitBananaQuantity << (" order/s - ") << fruitBanana << (" PHP") << endl;
				cout << ("Total Bill: ") << priceTotal << (" PHP");
			}

		}

	}
	//drinks
	if (order == 3) {
		system("cls");
		cout << ("These are the drinks for the day: \n\n") << endl;
		cout << ("[1] C2...................................P25.00") << endl;
		cout << ("[2] Smart C...........................P25.00") << endl;
		cout << ("[3] Summit...........................P15.00") << endl;
		cout << ("[4] Kopiko........................P12.00") << endl;
		cin >> drinkChoice;

		//asking for order quantity
		cout << "\nEnter the quantity of your order." << endl;
		cin >> MealQuantity;
		//Asking customer if they have any additional orders
		cout << ("\n Do you have another order?") << endl;
		cout << ("[1] Yes				[2] No") << endl;
		cin >> customerChoice;

		//switch conditions
		switch (drinkChoice)
		{
		case 1:
			drinkC2Quantity = drinkC2Quantity + MealQuantity;
			break;
		case 2:
			drinkSmartCQuantity = drinkSmartCQuantity + MealQuantity;
			break;
		case 3:
			drinkSummitQuantity = drinkSummitQuantity + MealQuantity;
			break;
		case 4:
			drinkKopikoQuantity = drinkKopikoQuantity + MealQuantity;
		}
		// If customer has other orders
		if (customerChoice == 1)
		{
			system("cls");
			goto menu;
		}
		// If customer is done
		else if (customerChoice == 2)
		{

			system("cls");
			//error handling statement if in case customer puts 0 in the "Do you have another order?" question
			if (MealQuantity == 0)
			{
				goto menu;
			}
			// computation for the total price/bill
			else {
				riceMealChicken = riceMealChickenQuantity * riceMealChicken; // computation for the price of Chicken Meal only
				riceMealTalong = riceMealTalongQuantity * riceMealTalong; // computation for the price of Talong Meal only
				fruitBanana = fruitBananaQuantity * fruitBanana; // computation for the price of Banana (fruit) only
				drinkC2 = drinkC2Quantity * drinkC2; // computation for the price of C2 only
				drinkSmartC = drinkSmartCQuantity * drinkSmartC; //computation for the price of Smart C only
				drinkSummit = drinkSummitQuantity * drinkSummit; //computation for the price of Summit only
				drinkKopiko = drinkKopikoQuantity * drinkKopiko; //computation for the price of Kopiko only
				priceTotal = riceMealChicken + riceMealTalong + fruitBanana + drinkC2 + drinkSmartC + drinkSummit + drinkKopiko;  // computes the total price


				cout << ("Order Summary:") << endl;
				cout << ("--------------") << endl;
				cout << ("Customer Name: ") << name << endl; //Displays the customer name
				cout << ("Section: ") << section << endl; //Displays the section of the customer
				cout << ("--------------") << endl;

				// Displays the no. of orders for rice meals
				cout << ("Rice Meal:") << endl;
				cout << ("Chicken Meal (55 PHP): ") << riceMealChickenQuantity << (" order/s - ") << riceMealChicken
					<< (" PHP | Talong Meal (45 PHP): ") << riceMealTalongQuantity << (" order/s - ") << riceMealTalong << (" PHP") << endl;
				// Displays the no. of order for fruits
				cout << ("Fruits:") << endl;
				cout << ("Banana (15 PHP): ") << fruitBananaQuantity << (" order/s - ") << fruitBanana << (" PHP") << endl;
				//Displays the no. of order for drinks
				cout << ("Drinks:") << endl;
				cout << ("C2 (25 PHP): ") << drinkC2Quantity << (" order/s - ") << drinkC2 << (" PHP") << endl;
				cout << ("Smart C (25 PHP): ") << drinkSmartCQuantity << (" order/s -") << drinkSmartC << (" PHP") << endl;
				cout << ("Summit (15 PHP): ") << drinkSummitQuantity << (" order/s -") << drinkSummit << (" PHP") << endl;
				cout << ("Kopiko (12 PHP): ") << drinkKopikoQuantity << (" order/s -") << drinkSummit << (" PHP") << endl;
				cout << ("Total Bill: ") << priceTotal << (" PHP");
			}
		}
	}
	//Snacks 
	if (order == 4) {
		system("cls");
		cout << "Here are the snacks for the day: \n\n" << endl;
		cout << "[1] Voice..............................10.00" << endl;
		cout << "[2] Fudgee Bar.......................10.00" << endl;
		cout << "[3] CreamO.......................8.00" << endl;
		cout << "[4] Bread Pan...................8.00" << endl;
		cin >> snacksChoice;

		//asking for order quantity
		cout << "\nEnter the quantity of your order." << endl;
		cin >> MealQuantity;
		//Asking customer if they have any additional orders
		cout << ("\n Do you have another order?") << endl;
		cout << ("[1] Yes				[2] No") << endl;
		cin >> customerChoice;

		//switch statements
		switch (snacksChoice) {
		case 1:
			snacksVoiceQuantity = snacksVoiceQuantity + MealQuantity;
			break;
		case 2:
			snacksFudgeebarQuantity = snacksFudgeebarQuantity + MealQuantity;
			break;
		case 3:
			snacksCreamOQuantity = snacksCreamOQuantity + MealQuantity;
			break;
		case 4:
			snacksBreadpanQuantity = snacksBreadpanQuantity + MealQuantity;
			break;
		}
		// If customer has other orders
		if (customerChoice == 1)
		{
			system("cls");
			goto menu;
		}
		// If customer is done
		else if (customerChoice == 2)
		{
			system("cls");
			//error handling statement if in case customer puts 0 in the "Do you have another order?" question
			if (MealQuantity == 0)
			{
				goto menu;
			}
			// computation for the total price/bill
			else {
				riceMealChicken = riceMealChickenQuantity * riceMealChicken; // computation for the price of Chicken Meal only
				riceMealTalong = riceMealTalongQuantity * riceMealTalong; // computation for the price of Talong Meal only
				fruitBanana = fruitBananaQuantity * fruitBanana; // computation for the price of Banana (fruit) only
				drinkC2 = drinkC2Quantity * drinkC2; // computation for the price of C2 only
				drinkSmartC = drinkSmartCQuantity * drinkSmartC; //computation for the price of Smart C only
				drinkSummit = drinkSummitQuantity * drinkSummit; //computation for the price of Summit only
				drinkKopiko = drinkKopikoQuantity * drinkKopiko; //computation for the price of Kopiko only
				snacksVoice = snacksVoiceQuantity * snacksVoice; //compuation for the price of Voice only
				snacksFudgeebar = snacksFudgeebarQuantity * snacksFudgeebar; //computation for the price of Fudgee Bar only
				snacksCreamO = snacksCreamOQuantity * snacksCreamO; //computation for the price of Cream O only
				snacksBreadpan = snacksBreadpanQuantity * snacksBreadpan; //computation for the price of Bread Pan only
				priceTotal = riceMealChicken + riceMealTalong + fruitBanana + drinkC2 + drinkSmartC + drinkSummit + drinkKopiko + snacksVoice + snacksFudgeebar + snacksCreamO + snacksCreamO + snacksBreadpan;  // computes the total price


				cout << ("Order Summary:") << endl;
				cout << ("--------------") << endl;
				cout << ("Customer Name: ") << name << endl; //Displays the customer name
				cout << ("Section: ") << section << endl; //Displays the section of the customer
				cout << ("--------------") << endl;

				// Displays the no. of orders for rice meals
				cout << ("Rice Meal:") << endl;
				cout << ("Chicken Meal (55 PHP): ") << riceMealChickenQuantity << (" order/s - ") << riceMealChicken
					<< (" PHP | Talong Meal (45 PHP): ") << riceMealTalongQuantity << (" order/s - ") << riceMealTalong << (" PHP") << endl;
				// Displays the no. of order for fruits
				cout << ("Fruits:") << endl;
				cout << ("Banana (15 PHP): ") << fruitBananaQuantity << (" order/s - ") << fruitBanana << (" PHP") << endl;
				//Displays the no. of order for drinks
				cout << ("Drinks:") << endl;
				cout << ("C2 (25 PHP): ") << drinkC2Quantity << (" order/s - ") << drinkC2 << (" PHP") << endl;
				cout << ("Smart C (25 PHP): ") << drinkSmartCQuantity << (" order/s -") << drinkSmartC << (" PHP") << endl;
				cout << ("Summit (15 PHP): ") << drinkSummitQuantity << (" order/s -") << drinkSummit << (" PHP") << endl;
				cout << ("Kopiko (12 PHP): ") << drinkKopikoQuantity << (" order/s -") << drinkSummit << (" PHP") << endl;
				//Displays the no. of order for snacks
				cout << ("Voice (10 PHP): ") << snacksVoiceQuantity << (" order/s - ") << snacksVoice << (" PHP") << endl;
				cout << ("Fudgee Bar (10 PHP): ") << snacksFudgeebarQuantity << (" order/s -") << snacksFudgeebar << (" PHP") << endl;
				cout << ("Cream O (8 PHP): ") << snacksCreamOQuantity << (" order/s -") << snacksCreamO << (" PHP") << endl;
				cout << ("Bread Pan (8 PHP): ") << snacksBreadpanQuantity << (" order/s -") << snacksBreadpan << (" PHP") << endl;
				cout << ("Total Bill: ") << priceTotal << (" PHP");
			}
		}
	}
	if (order == 5) {
		system("cls");
		cout << "Here are the snacks for the day: \n\n" << endl;
		cout << "[1] Carbonara..............................50.00" << endl;
		cout << "[2] Spaghetti............................50.00" << endl;
		cout << "[3] Palabok.............................45.00" << endl;
		cin >> otherChoice;

		//asking for order quantity
		cout << "\nEnter the quantity of your order." << endl;
		cin >> MealQuantity;
		//Asking customer if they have any additional orders
		cout << ("\n Do you have another order?") << endl;
		cout << ("[1] Yes				[2] No") << endl;
		cin >> customerChoice;

		//switch statements
		switch (otherChoice) {
		case 1: 
			otherCarbonaraQuantity = otherCarbonara + MealQuantity;
			break;
		case 2: 
			otherSpaghettiQuantity = otherSpaghettiQuantity + MealQuantity;
			break;
		case 3: 
			otherPalabokQuantity = otherPalabokQuantity + MealQuantity;
		}
		// If customer has other orders
		if (customerChoice == 1)
		{
			system("cls");
			goto menu;
		}
		// If customer is done
		else if (customerChoice == 2)
		{
			system("cls");
			//error handling statement if in case customer puts 0 in the "Do you have another order?" question
			if (MealQuantity == 0)
			{
				goto menu;
			}
			// computation for the total price/bill
			else {
				riceMealChicken = riceMealChickenQuantity * riceMealChicken; // computation for the price of Chicken Meal only
				riceMealTalong = riceMealTalongQuantity * riceMealTalong; // computation for the price of Talong Meal only
				fruitBanana = fruitBananaQuantity * fruitBanana; // computation for the price of Banana (fruit) only
				drinkC2 = drinkC2Quantity * drinkC2; // computation for the price of C2 only
				drinkSmartC = drinkSmartCQuantity * drinkSmartC; //computation for the price of Smart C only
				drinkSummit = drinkSummitQuantity * drinkSummit; //computation for the price of Summit only
				drinkKopiko = drinkKopikoQuantity * drinkKopiko; //computation for the price of Kopiko only
				snacksVoice = snacksVoiceQuantity * snacksVoice; //compuation for the price of Voice only
				snacksFudgeebar = snacksFudgeebarQuantity * snacksFudgeebar; //computation for the price of Fudgee Bar only
				snacksCreamO = snacksCreamOQuantity * snacksCreamO; //computation for the price of Cream O only
				snacksBreadpan = snacksBreadpanQuantity * snacksBreadpan; //computation for the price of Bread Pan only
				otherCarbonara = otherCarbonaraQuantity * otherCarbonara; //computation for the price of Carbonara only
				otherSpaghetti = otherSpaghettiQuantity * otherSpaghetti; //computation for the price of Spaghetti only
				otherPalabok = otherPalabokQuantity * otherPalabok; //computation for the price of Palabok only
				priceTotal = riceMealChicken + riceMealTalong + fruitBanana + drinkC2 + drinkSmartC + drinkSummit + drinkKopiko + snacksVoice + snacksFudgeebar + snacksCreamO + snacksCreamO + snacksBreadpan + otherCarbonara + otherSpaghetti + otherPalabok; // computes the total price


				cout << ("Order Summary:") << endl;
				cout << ("--------------") << endl;
				cout << ("Customer Name: ") << name << endl; //Displays the customer name
				cout << ("Section: ") << section << endl; //Displays the section of the customer
				cout << ("--------------") << endl;

				// Displays the no. of orders for rice meals
				cout << ("Rice Meal:") << endl;
				cout << ("Chicken Meal (55 PHP): ") << riceMealChickenQuantity << (" order/s - ") << riceMealChicken
					<< (" PHP | Talong Meal (45 PHP): ") << riceMealTalongQuantity << (" order/s - ") << riceMealTalong << (" PHP") << endl;
				// Displays the no. of order for fruits
				cout << ("Fruits:") << endl;
				cout << ("Banana (15 PHP): ") << fruitBananaQuantity << (" order/s - ") << fruitBanana << (" PHP") << endl;
				//Displays the no. of order for drinks
				cout << ("Drinks:") << endl;
				cout << ("C2 (25 PHP): ") << drinkC2Quantity << (" order/s - ") << drinkC2 << (" PHP") << endl;
				cout << ("Smart C (25 PHP): ") << drinkSmartCQuantity << (" order/s -") << drinkSmartC << (" PHP") << endl;
				cout << ("Summit (15 PHP): ") << drinkSummitQuantity << (" order/s -") << drinkSummit << (" PHP") << endl;
				cout << ("Kopiko (12 PHP): ") << drinkKopikoQuantity << (" order/s -") << drinkSummit << (" PHP") << endl;
				//Displays the no. of order for snacks
				cout << ("Voice (10 PHP): ") << snacksVoiceQuantity << (" order/s - ") << snacksVoice << (" PHP") << endl;
				cout << ("Fudgee Bar (10 PHP): ") << snacksFudgeebarQuantity << (" order/s -") << snacksFudgeebar << (" PHP") << endl;
				cout << ("Cream O (8 PHP): ") << snacksCreamOQuantity << (" order/s -") << snacksCreamO << (" PHP") << endl;
				cout << ("Bread Pan (8 PHP): ") << snacksBreadpanQuantity << (" order/s -") << snacksBreadpan << (" PHP") << endl;
				//Displays the no. of order for other
				cout << ("Carbonara (50 PHP): ") << otherCarbonaraQuantity << (" order/s -") << otherCarbonara << (" PHP") << endl;
				cout << ("Spaghetti (50 PHP): ") << otherSpaghettiQuantity << (" order/s -") << otherSpaghetti << (" PHP") << endl;
				cout << ("Palabok (45 PHP): ") << otherPalabokQuantity << (" order/s -") << otherPalabok << (" PHP") << endl;
				cout << ("Total Bill: ") << priceTotal << (" PHP");
			}
		}
	}
	return 0;
}
